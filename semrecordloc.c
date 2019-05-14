#include <sys/types.h>

#include <unistd.h>

#include <fcntl.h>

void main (argc, char* argv [])

{

 

struct flock f1 = F_WRLCK, SEEK_SET, 0, 0, 0

    int fd = 0;

f1.L_Pid = getPid ();

if (argc > 1)

 { f1.L_Type = F_RDLCK; }

 

if (fd = open ("Test.C", O_RDWR) == -1)

  printf ("ERROR");

  printf ("LOCKED");

  printf ("Press Return to get locked");

  if (fcntl (fd, F_SETLKW))

  {

    f1.l_type = F_UNLCK;

    if (fcntl (fd, F_SELCK, &f1) == -1)

    {

      printf ("ERROR");

      printf ("Press trying to get unlock");

      close (fd);

    }

  }

}


