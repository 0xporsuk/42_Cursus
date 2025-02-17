#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void signal_handler(int signum, siginfo_t *info, void *context) {
    static int bit_count = 0;
    static unsigned char current_char = 0;
    (void)context;

    if (signum == SIGUSR1)
        current_char = (current_char << 1) | 1;
    else if (signum == SIGUSR2)
        current_char = current_char << 1;

    bit_count++;
    if (bit_count == 8) {
        write(1, &current_char, 1);
        bit_count = 0;
        current_char = 0;
    }
    // Her bit alındığında client'a bilgi gönder
    kill(info->si_pid, SIGUSR1);
}

int main(void) {
    struct sigaction sa;
    
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    printf("Server PID: %d\n", getpid());
    
    while (1)
        pause();
    
    return 0;
}