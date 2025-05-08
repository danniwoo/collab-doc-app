#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FIFO_C2S "FIFO_C2S_%d"
#define FIFO_S2C "FIFO_S2C_%d"

static pid_t client_pid;

void handle_sig(int sig, siginfo_t *info, void *ucontext) {
    client_pid = info->si_pid;

    printf("Received SIGRTMIN from client %d\n", client_pid);

    char fifo_c2s[64], fifo_s2c[64];
    sprintf(fifo_c2s, FIFO_C2S, client_pid);
    sprintf(fifo_s2c, FIFO_S2C, client_pid);

    mkfifo(fifo_c2s, 0666);
    mkfifo(fifo_s2c, 0666);

    // Send SIGRTMIN+1 to client
    kill(client_pid, SIGRTMIN + 1);

    // Open FIFO and read message
    int fd = open(fifo_c2s, O_RDONLY);
    char buf[256];
    read(fd, buf, sizeof(buf));
    printf("[Server] Got message: %s\n", buf);

    close(fd);
    unlink(fifo_c2s);
    unlink(fifo_s2c);
    exit(0);
}

int main() {
    printf("Server PID: %d\n", getpid());

    struct sigaction sa;
    sa.sa_sigaction = handle_sig;
    sa.sa_flags = SA_SIGINFO;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGRTMIN, &sa, NULL);

    // Wait forever
    while (1) pause();
}