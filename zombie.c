#include<stdio.h>

main()

{

​int pid;

​pid=fork();

​if(0==pid)

​{

​printf("child process %d \n",getpid());

    _exit(0);

​}

​else

​{

​wait(0);

​sleep(10);

​printf("parent process \n");

​}

}
