#include <stdio.h>
#include <unistd.h>

int main( )
{
   alarm(5);
   printf("Loop Start \n");
   while (1) {
      sleep(1);
      printf("second \n");
   }
   printf("Alarm clock \n");
   return 0;
}

