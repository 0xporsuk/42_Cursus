#include "minitalk_bonus.h"

volatile sig_atomic_t g_bit_received = 0;
volatile sig_atomic_t g_message_completed = 0;

void bit_handler(int signum) {
    if (signum == SIGUSR1)
        g_bit_received = 1;
    else if (signum == SIGUSR2)
        g_message_completed = 1;
}

void send_char(int pid, unsigned short c) {
    int i;
    
    for (i = 15; i >= 0; i--) {
        g_bit_received = 0;
        if (c & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (!g_bit_received)
            usleep(100);
    }
}

int main(int argc, char *argv[]) {
    int server_pid;
    char *message;
    struct sigaction sa;
    
    if (argc != 3) {
        ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
        return 1;
    }
    
    sa.sa_handler = bit_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        ft_printf("Signal handling setup failed\n");
        return 1;
    }
    
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0) {
        ft_printf("Invalid server PID\n");
        return 1;
    }
    
    message = argv[2];
    while (*message) {
        send_char(server_pid, (unsigned short)*message);
        message++;
    }
    send_char(server_pid, 0);
    
    while (!g_message_completed)
        pause();
    
    ft_printf("Message delivered successfully!\n");
    return 0;
}
