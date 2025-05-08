#include "../libs/common.h"
#include "../libs/markdown.h"
#include <fcntl.h>

// TODO: server code that manages the document and handles client instructions

int main(int argc, char *argv[]){
    // make fifo

    // how to unlink (delete) a FIFO when done
    if (mkfifo("myfifo1", 0777) == -1){
        // error == already exist
        if(errno != EEXIST){
            printf("could not create fifo file\n");
        }
    }

    printf("Opeing.. \n");
    int fd = open("myfifo1", O_WRONLY);

    int x = 97;
    if(write(fd, &x, sizeof(x)) == -1){
        printf("write faild\n");
    }

    printf("Writing.. \n");
    close(fd);

    printf("Closed.. \n");


    return 0;
}