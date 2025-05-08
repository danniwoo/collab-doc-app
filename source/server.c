#include "../libs/common.h"
#include "../libs/markdown.h"

// TODO: server code that manages the document and handles client instructions

int main(int argc, char *argv[]){
    printf("hi\n");
    int pid = getpid();
    int time_interval; // in milliseconds

    printf("Server PID: %d\n", pid);

    if(argc == 2){
        char *output;
        // long result = strtol(argv[1], &output, )
        // time_interval = (int)argv[1];
    }

    
    return 0;
}