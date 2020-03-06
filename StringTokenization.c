#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void) {
   char num[25],fsum[25];
   int a,sum=0;
   char *p;
   write(STDOUT_FILENO, "Enter numbers(separated by space): \n", 35);
   read(STDIN_FILENO, num, 25);
   p=strtok(num, " ");
   while(p!=NULL) {
       sscanf(p, "%d", &a);
       printf("%d\n", a);
       sum += a;
       p = strtok(NULL, " ");
   }
   int count=sprintf(fsum,"%d", sum);
   write(STDOUT_FILENO, "The Sum is=", 10);
  write(STDOUT_FILENO, fsum, count);
}