#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
int main(int argc,char* argv[])
{
int i;
struct stat s;
if (argc<3)
{
perror("ERROR:Too Few Arguments");
exit(1);
}
if(argc>4)
{
perror("ERROR:Too Many Arguments");
exit(1);
}
if(argc==3)
i=0;
else
i=1;
if(i && !(strcmp(argv[1],"-s")==0)) {
perror("ERROR:Invalid Syntax");
exit(1);
}
if(access(argv[i+1],F_OK))
{
 perror("ERROR:File name not Found");
 exit(1);
}
if(!access(argv[i+2],F_OK))
{
 perror("ERROR:File Name already exist");
 exit(1);
}
if(stat(argv[i+1],&s)<0)
{
 perror("ERROR:Unable to reterive stat information");
 exit(1);
}
if(!S_ISREG(s.st_mode))
{
 perror("ERROR:Not a Regular File");
 exit(1); }
if(argc==3)
if(link(argv[i+1],argv[i+2])<0)
{
 perror("ERROR:Unable to create the Link");
 exit(1);
}
if(argc==4)
if(symlink(argv[i+1],argv[i+2])<0)
{
 perror("ERROR:Unable to create the Link");
 exit(1);
}
}
