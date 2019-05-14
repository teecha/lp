#include <stdio.h>

#include <errno.h>

#include <ctype.h>

#include <unistd.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <string.h>

#include <fcntl.h>

#include "half_duplex.h" /* For name of the named-pipe */

#include <stdlib.h>

 

int main(int argc, char *argv[])

{

int fd;

/* Check if an argument was specified. */

if (argc != 2) {

printf("Usage: %s<string to be sent to the server>n",argv[0]);

exit (1);

}

/* Open the pipe for writing */

fd = open(HALF_DUPLEX, O_WRONLY);

/* Write to the pipe */

write(fd, argv[1], strlen(argv[1]));

}


