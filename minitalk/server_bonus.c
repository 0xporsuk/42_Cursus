#include "minitalk_bonus.h"

void signal_handler(int signum, siginfo_t *info, void *context) {
    static int bit_count = 0;
    static unsigned short current_char = 0;
    static int client_pid = 0;
    (void)context;

    if (client_pid != info->si_pid) {
        bit_count = 0;
        current_char = 0;
        client_pid = info->si_pid;
    }

    if (signum == SIGUSR1)
        current_char = (current_char << 1) | 1;
    else if (signum == SIGUSR2)
        current_char = current_char << 1;

    bit_count++;
    if (bit_count == 16) {
        if (current_char == 0) {
            ft_printf("\nMessage received successfully from PID: %d\n", client_pid);
            kill(client_pid, SIGUSR2);
        } else {
            write(1, &current_char, 2);
        }
        bit_count = 0;
        current_char = 0;
    }
    kill(client_pid, SIGUSR1);
}

int main(void) {
    struct sigaction sa;
    
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    
    if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1) {
        ft_printf("Signal handling setup failed\n");
        return 1;
    }
    
    ft_printf("Server PID: %d\n", getpid());
    
    while (1)
        pause();
    
    return 0;
}
