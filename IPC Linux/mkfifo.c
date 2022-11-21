#define _GNU_SOURCE
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define NAMEDPIPE_NAME "/tmp/my_named_pipe"
#define BUFSIZE        50

int main (int argc, char ** argv) {
    int fd, len;
    char buf[BUFSIZE];

    if ( mkfifo(NAMEDPIPE_NAME, 0777) ) { //(S_IRWXO | S_IRWXG | S_IRWXU)
        perror("mkfifo");    
        return 1;
    }
    printf("%s is created\n", NAMEDPIPE_NAME);


    if ( (fd = open(NAMEDPIPE_NAME, O_RDONLY)) <= 0 ) {
        perror("open");
        return 1;
    }
    printf("%s is opened\n", NAMEDPIPE_NAME);

    printf("%d size of pipe\n", fcntl(fd, F_GETPIPE_SZ));
    if (fcntl(fd, F_SETPIPE_SZ, 5000) <= 0){
        printf("set pipe size failed\n");        
    }
    printf("%d size of pipe\n", fcntl(fd, F_GETPIPE_SZ));

    do {
        memset(buf, '\0', BUFSIZE);
        if ( (len = read(fd, buf, BUFSIZE-1)) <= 0 ) {
            perror("read");
            close(fd);
            remove(NAMEDPIPE_NAME);
            return 0;
        }
        printf("Incomming message (%d): %s\n", len, buf);
    } while ( 1 );
}
