#include<fcntl.h>
#define MAX_SIZE 500
main()
{
​int fd1,n;
​char buf[MAX_SIZE],fname[20];
​printf("enter a file name\n");
​scanf("%s",fname);
​fd1=open(fname,O_RDONLY);
​if(fd1==-1)
​printf("the file does not exist");
​else
​{
​ printf("The contents of file %s are:\n",fname);
​ n=read(fd1,buf,MAX_SIZE);
​ write(1,buf,n);
​}
}

