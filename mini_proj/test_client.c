#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define FIFO_C2S "FIFO_C2S_%d"
#define FIFO_S2C "FIFO_S2C_%d"

volatile sig_atomic_t ready = 0;

void handle_ready(int sig) {
    ready = 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./client <server_pid>\n");
        return 1;
    }

    pid_t server_pid = atoi(argv[1]);

    // Setup handler for SIGRTMIN+1
    signal(SIGRTMIN + 1, handle_ready);

    // Send signal to server
    kill(server_pid, SIGRTMIN);

    // Wait for reply
    while (!ready);

    char fifo_c2s[64], fifo_s2c[64];
    sprintf(fifo_c2s, FIFO_C2S, getpid());
    sprintf(fifo_s2c, FIFO_S2C, getpid());

    int fd = open(fifo_c2s, O_WRONLY);
    write(fd, "Hello server!", 14);
    close(fd);

    printf("[Client] Sent message to server.\n");

    return 0;
}