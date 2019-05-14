#include<stdio.h>

#include<sys/types.h>

#include<sys/ipc.h>

#include<sys/msg.h>

struct msgbuf{

​long mtype;

​char mtext[40];

};

main()

{

​int msqid,len,type,ret;

struct msgbuf msgread={0,"\0"};

msqid=msgget((key_t)7,IPC_CREAT|0666);

if(-1==msqid)

{

​perror("msgget:");

​exit(1);

}

printf("enter the msg type:\n");

scanf("%d",&type);

len=sizeof(msgread.mtext);

ret=msgrcv(msqid,&msgread,len,type,0);

printf("ret=%d\n",ret);

if(-1==ret)

{

​perror("msgrcv:");

​exit(1);

}

else

printf("message type=%d message text=%s\n",msgread.mtype,msgread.mtext);

}


