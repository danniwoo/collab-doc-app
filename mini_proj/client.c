// #include "../libs/common.h"
// #include "../libs/markdown.h"
// #define _GNU_SOURCE
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>



// TODO: server code that manages the document and handles client instructions

// ./client <server_pid> <username>
int main(int argc, char *argv[]){

    // sigrtmin
    // int server_pid = atoi(argv[1]);
    pid_t server_pid = atoi(argv[1]);

    printf("%d\n", server_pid);
    printf("%d\n", SIGRTMIN);

    // kill(server_pid, SIGRTIM)
    



    // read from fifo
    // printf("Opeing.. \n");
    // int fd = open("myfifo1", O_RDONLY);

    // int x;
    // if(read(fd, &x, sizeof(x)) == -1){
    //     printf("read faild\n");
    // }

    // printf("read.. \n");


    // printf("%d\n", x);
    // close(fd);

    // printf("Closed.. \n");


    return 0;
}