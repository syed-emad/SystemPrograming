 #define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
const int size = 1000;

char delimiter[1] = {' '};
char * token;
//char printbuffer[size];
int number;

void Add();
void Sub();
void Mul();
void Div();
void Run();
void List();
void Kill();
void killall();

typedef struct details
{
    int pid;
    int ppid;
    char name[1000];
    bool isActive;
    time_t startingtime;
    time_t endingtime;
}details;


details list[100];
int counter=0;

int main(int argc, char *argv[]){

     
    write(STDOUT_FILENO,"Commands: 1.run 2.list 3.kill 4.add 5.sub 6.mul 7.div \nSamples:\n1. run gedit    //to run app \n2.list   //to display list \n3.kill 123   //to kill process by using its pid 123 here is pid \n  kill gedit //to kill process by using its name \n4.add 2 2//for addition, follow same method for sub, mul div \n",sizeof("Commands: 1.run 2.list 3.kill 4.add 5.sub 6.mul 7.div \nSamples:\n1. run gedit    //to run app \n2.list   //to display list \n3.kill 123   //to kill process by using its pid 123 here is pid \n  kill gedit //to kill process by using its name \n4.add 2 2//for addition, follow same method for sub, mul div \n"));
     
    write(STDOUT_FILENO,"------------------------------------------------------------\n",sizeof("------------------------------------------------------------\n"));
    int readfromscreen=0;
    char buff[100];
    
      int pipeOne[2];
  int pipeTwo[2];
  pipe(pipeOne);
  pipe(pipeTwo);
  int pid = fork();
  //----------------------------------------------------------SERVER-----------------------------//
  if (pid>0)
  {
    while(true){
      write(STDOUT_FILENO,"Enter Input\n",sizeof("Enter Input\n"));
     
      
      close(pipeOne[1]);
      int xol=read(pipeOne[0],buff,100);
       
      token=strtok(buff,delimiter);
       
      if (strcmp(token,"add")==0)
        {
            Add();
        }
        else if (strcmp(token,"run")==0)
        {
            Run();
        }
        else if (strcmp(token,"list")==0)
        {
            List();
        }
        else if (strcmp(token,"kill")==0)
        {
            Kill();
        }
        else if (strcmp(token,"mul")==0)
        {
            Mul();
        }
        else if(strcmp(token,"sub")==0){
            Sub();
        }
        else if(strcmp(token,"div")==0){
            Div();
        }
        else if(strcmp(token,"exit")==0){
            killall();
            printf("%s\n","exited" );
        }
        else if(strcmp(token,"killall")==0){
            killall();
        }
    }
  }
  //--------------------------------------------------CLIENT--------------------------------------------//
else if (pid==0)
{
  while(true){
    close(pipeOne[0]);
    readfromscreen=read(STDOUT_FILENO,buff,100);
    buff[readfromscreen-1]='\0';
    write(pipeOne[1],buff,readfromscreen);
   
  }
}


}
void Add(){

  int sum=0;
  char buffq[100];
  int pipefd2[2];
  pipe(pipefd2);  
  int pid=fork();
  if (pid==0)
      {    close(pipefd2[0]);
         while((token=strtok(NULL,delimiter))!=NULL){
            sum=sum+atoi(token);
        }
       
        int v=sprintf(buffq,"%d",sum);
        write(pipefd2[1],buffq,v);
    }
    if (pid>0)
    {
        int p=read(pipefd2[0],buffq,100);
        write(STDOUT_FILENO,"Answer: ",sizeof("Answer: "));
        write(STDOUT_FILENO,buffq,p);
        write(STDOUT_FILENO,"\n",2);   

        int *status;
        int w = waitpid(pid, status, 0);

    }
}
void Mul(){

  int sum=atoi(strtok(NULL,delimiter));
  char buff[100];
  int pipefd2[2];
  pipe(pipefd2);  
  int pid=fork();
  if (pid==0)
      {     close(pipefd2[0]);
         while((token=strtok(NULL,delimiter))!=NULL){
            sum=sum*atoi(token);
        }
      
        int v=sprintf(buff,"%d",sum);
        write(pipefd2[1],buff,v);
    }
    if (pid>0)
    {
        int p=read(pipefd2[0],buff,100);
        write(STDOUT_FILENO,"Answer: ",sizeof("Answer: "));
        write(STDOUT_FILENO,buff,p);
        write(STDOUT_FILENO,"\n",2);   
            int *status;
        int w = waitpid(pid, status, 0);

    }
}
void Sub(){

  int sum=atoi(strtok(NULL,delimiter));
  char buff[100];
  int pipefd2[2];
  pipe(pipefd2);  
  int pid=fork();
  if (pid==0)
      {     close(pipefd2[0]);
         while((token=strtok(NULL,delimiter))!=NULL){
            sum=sum-atoi(token);
        }
      
        int v=sprintf(buff,"%d",sum);
        write(pipefd2[1],buff,v);
    }
    if (pid>0)
    {
        int p=read(pipefd2[0],buff,100);
        write(STDOUT_FILENO,"Answer: ",sizeof("Answer: "));
        write(STDOUT_FILENO,buff,p);
        write(STDOUT_FILENO,"\n",2);   
            int *status;
        int w = waitpid(pid, status, 0);

    }
}
void Div(){

  int sum=atoi(strtok(NULL,delimiter));
  char buff[100];
  int pipefd2[2];
  pipe(pipefd2);  
  int pid=fork();
  if (pid==0)
      {     close(pipefd2[0]);
         while((token=strtok(NULL,delimiter))!=NULL){
            sum=sum/atoi(token);
        }
       
        int v=sprintf(buff,"%d",sum);
        write(pipefd2[1],buff,v);
    }
    if (pid>0)
    {
        int p=read(pipefd2[0],buff,100);
        write(STDOUT_FILENO,"Answer: ",sizeof("Answer: "));
        write(STDOUT_FILENO,buff,p);
        write(STDOUT_FILENO,"\n",2);
            int *status;
        int w = waitpid(pid, status, 0);   

    }
}


void Run(){
    
  char pID[100];
  char buff[100];
  int pipefd1[2];
  int idholder;
  int pipeN[2];
  char global[2]={'1'};
   
  pipe(pipefd1);
  pipe(pipeN);

  
  while ((token = strtok(NULL, delimiter)) != NULL) 
  { 
    int pipefdv[2];
    pipe2(pipefdv, O_CLOEXEC );
    int pid=fork();
    
    if (pid==0)
        {   close(pipefd1[0]);
            close(pipefdv[0]);
            int c= sprintf(pID,"%d",getpid());
            write(pipefd1[1],pID,c);
             
            char *args[]={token,NULL};
         
            
            if (execvp(args[0],args)!=0)
            {  
              write(STDOUT_FILENO,"file not found in directoy",sizeof("file not found in directoy"));
               
              sprintf(global,"%d",3);
              write(pipefdv[1],global,3);
 
            }
        }

    
        if (pid>0)
            {  

                close(pipefd1[1]);
                close(pipefdv[1]);
                read(pipefdv[0],global,3);
                
            
                if (strcmp(global,"3")==0)
                {
                  printf("%s\n","Restart Program" );
                  exit(0);
                }
                else if (strcmp(global,"1")==0)
                {
                  int p=read(pipefd1[0],buff,14);
                
               list[counter].pid=atoi(buff);
               list[counter].ppid=getpid();
                
               strcpy( list[counter].name, token);
               list[counter].isActive=true;
               list[counter].startingtime=time(NULL); 
               counter++;
               write(STDOUT_FILENO,"Child Successfully created\n",27);
               write(STDOUT_FILENO,"Has been added to the list\n",30);
                }
             





           }
       }

   }


void List(){
    char buff[size];
     write(STDOUT_FILENO,"PID     PPID    Name          Active     StartTime     EndTime\n",64);
     
for (int i = 0; i <counter; ++i)
{ 
   number= sprintf(buff,"%d\t%d\t%s\t\t%d \t %ld \t %ld \n",list[i].pid,list[i].ppid,list[i].name,list[i].isActive,list[i].startingtime,list[i].endingtime);
   write(STDOUT_FILENO,buff,number);
}
}



void Kill(){
    token=strtok(NULL,delimiter);
     
    int counterc=0;
  

     
     
    for (int i = 0; i < counter; ++i)
    {   if (list[i].pid==atoi(token) || strcmp(list[i].name,token)==0)
        {    
            counterc++;
            
            if (list[i].isActive==true)
            {
                    kill(list[i].pid, SIGKILL);
                    list[i].isActive=false;
                    list[i].endingtime=time(NULL);
                     
                    write(STDOUT_FILENO,"Successfully Exited \n",sizeof("Successfully Exited \n"));
                    break;
             }
            else{
             
            write(STDOUT_FILENO,"Programm already Killed \n",sizeof("Programm already Killed \n"));
                 }
        
        }

    
    }        if(counterc==0){
         
        write(STDOUT_FILENO,"Incorrect PID entered \n",sizeof("Incorrect PID entered \n"));
    }
}
void killall(){
   
     kill(0,SIGKILL);

  
}