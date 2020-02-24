#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{

  int sum = 0;    //variabl to hold  final sum result
  int value;      //eache value is added to sum variable
  char *ch;       //pointer for string tokenization
  char buff[100]; //buffer to read the user input in parent
  char buff3[12]; //result of sum is added here
  char hold[4];   //use to hold the size of input by the user to make sure memory of input is not > than assing memory
  char hold2[4];

  int pipefd[2];  //pipe1-to send inp to child
  int pipefd2[2]; //pipe2- to send result to parent
  pid_t pid;      //process id type variable
  
  int alphabet = 0;
  int space2 = 0;
  
  //char *j;

  startv:
  //checking if pipes have been created with no isse
  if (pipe(pipefd) == -1)
  {
    write(STDOUT_FILENO, "pipe failed\n", 12);
    return 1;
  }

  if (pipe(pipefd2) == -1)
  {
    write(STDOUT_FILENO, "pipe failed\n", 12);
    return 1;
  }
  //doing fork
  pid = fork();

  //checking if fork has been done properly
  if (pid < 0)
  {
    write(STDOUT_FILENO, "error in fork\n", 13);
  }

//if user input exced memory code come here
start:

  //child process
  if (pid == 0)
  {

    close(pipefd[1]);  // closing pipe1 write
    close(pipefd2[0]); //closing pipe2 read

    //reading from pipe1
    int x = read(pipefd[0], buff, sizeof(buff));

    //adding null at end to remove space issue at end of input
    buff[x - 1] = '\0';

    //performing string tokenization
    ch = strtok(buff, " ");
 
    while (ch != NULL)
    {	
      sscanf(ch, "%d", &value);
      //write(STDOUT_FILENO, "child is adding... \n", 20);

      //performing sum
      sum += value;
      ch = strtok(NULL, " ");
    }

    //writing answer to buffer
    int countxx=sprintf(buff3, "%d", sum);
     
    //writing to pipe2
    write(pipefd2[1], buff3, countxx);
  }

  //parent process
  if (pid > 0)
  {
    close(pipefd[0]);  //closing pipe1 read
    close(pipefd2[1]); //closing pipe2 write
    //reading from user
    write(STDOUT_FILENO,"ENTER INPUT(Enter # to end program): \n",39);
    int a = read(STDIN_FILENO, buff, 100);
     space2=0;

    //checking is user inp doesnt exceed memory
    if (a > 100)
    {

      write(STDOUT_FILENO, "Memory Exced write less numbers \n", 33);
      write(STDOUT_FILENO, "Memory allocated:100 \n", 23);
      write(STDOUT_FILENO, "Memory input give:", 18);
      //printf("%d\n", a);
      int o = sprintf(hold, "%d", a);
      write(STDOUT_FILENO, hold, o);
      write(STDOUT_FILENO, "\n", 2);
      goto start;
    }

    if (buff[0]=='#')
    {
    	printf("%s\n", "Program Exited");
    	exit(0);
    }

    //checking if user has input an alphabet or no input
     for (int i=0; i<a; i++) 
    { 	
        // check for alphabets 
        if (isalpha(buff[i]) != 0){ 
            alphabet++; }
  		if (isspace(buff[i])!=0)
  		{
  			space2++;
  		}
          
    } 
  
 	 

     
    if (alphabet != 0 || space2 == 1)
    { 
      write(STDOUT_FILENO, "Incorrect Input:", 16);
      	if (alphabet >0)
      	{	
      		write(STDOUT_FILENO,"You entered ",12);
      		
      		sprintf(hold,"%d",alphabet);
      		write(STDOUT_FILENO,hold,sizeof(hold));
      		     

      		write(STDOUT_FILENO, " alphabets \n", 13); 
      		alphabet=0;
      		 
      	}
      	if (space2 =1 )
      	{	
      		write(STDOUT_FILENO,"Enter some input \n",19);
      		
      	}
     	 //exit(0);
      	goto start;
    }

    //writing to pipe1
    write(pipefd[1], buff, a);

    //reading from pipe2
    int countv = read(pipefd2[0], buff3, sizeof(buff3));
    
    //outputing suming result
    write(STDOUT_FILENO, buff3, countv);
    write(STDOUT_FILENO,"\n",2);
    goto startv;
  }
       return 0;

}