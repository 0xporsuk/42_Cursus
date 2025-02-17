#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t g_bit_received = 0;

void bit_handler(int signum) {
    (void)signum;
    g_bit_received = 1;
}

void send_char(int pid, unsigned char c) {
    int i;
    struct sigaction sa;
    
    sa.sa_handler = bit_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    
    for (i = 7; i >= 0; i--) {
        g_bit_received = 0;
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (!g_bit_received)
            pause();
    }
}
int main(int argc, char *argv[]) {
    int server_pid;
    char *message;
    
    if (argc != 3) {
        printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }
    
    server_pid = atoi(argv[1]);
    message = argv[2];
    
    while (*message) {
        send_char(server_pid, *message);
        message++;
    }
    send_char(server_pid, '\0');  // NULL karakteri gönder
    
    return 0;
}