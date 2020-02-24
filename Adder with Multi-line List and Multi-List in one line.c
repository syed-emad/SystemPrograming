#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main()
{

	int limit;

	limit = 60;

	char array[limit];

	start:
	write(STDOUT_FILENO, "Input Numbers,Add spaces between numbers,PRESS # TO END PROGRAM: \n", 67);

	
	int sum;
	char *ch;
	int j=0;

	int countsub=0;

	char result4[4];
	int a[5];

	int counter=0;
	int stopper=1;

	int alpha=0;

    int counter3;
	int x=1;
	startp:
	while(x==1){ //this will continue until X is press which will terminate
		//putting null terminator at end
		int counterx=read(STDIN_FILENO,array,3000);
		array[counterx-1]='\0';
        //checking for alphabet
		for (int i = 0; i < counterx ; ++i)
		{
			if (isalpha(array[i]) != 0)
			{	counter3=i;
				alpha=2;
			}

		}
		if (alpha==2)
		{
			alpha=1;
			write(STDOUT_FILENO,"Enter correct input\n",20);
			 
				array[counter3]=0;
				goto startp;
			 


		}
		
		ch = strtok(array, " ");
		char subtr[4];
		char subtr2[4];
		int buff;
		int variable;
		int variable2;
		//str tock will run till null
		while(ch !=NULL){
				//ch = strtok(NULL, " ");
			//summing all values till ;
			if (strncmp(ch,";",1) != 0){	

				sscanf(ch, "%d", &buff);


				variable2 = variable2 + buff;
							//to see steps
							//	printf("%s\n", "YYY");
							//printf("step- %d\n", variable2);
							//	sprintf(subtr, "%d", variable2);
			 				//	sscanf(subtr,"%d",&a[j]);
			 				//	write(STDOUT_FILENO,"Values in arrayY:",17);
			 				//	for (int i = 0; i < 5; ++i)
			 				//	 {
			 				//	 	int count=sprintf(result4,"%d ",a[i]); //writes the value in a at i index location to result variable
     						//	write(STDOUT_FILENO,result4,count);
			 				//	 } 


			}
			//when it encounter ; it will goto this loop and add prev ones
			if (strncmp(ch,";",1)==0){
				counter++;
				sprintf(subtr2, "%d", variable2);
				sscanf(subtr2,"%d",&a[j]);
				j++;

				write(STDOUT_FILENO,"Output of last list:",20);
				write(STDOUT_FILENO,subtr2,4);
				write(STDOUT_FILENO,"\n",2);

				startx:
				write(STDOUT_FILENO,"Result List:",12);
				for (int i = 0; i < counter; ++i)
				{
			 					 	int count=sprintf(result4,"%d ",a[i]); //writes the value in a at i index location to result variable
			 					 	write(STDOUT_FILENO,result4,count);
			 					 } 


			 					 write(STDOUT_FILENO,"\n",2);

			 					//reseting for new list
			 					 variable2=0;

			 					//stoping condition
			 					 if (stopper==3)
			 					 {
			 					 	exit(0);
			 					 	break;	
			 					 }

			 					}
			 					//terminating condtion
			 					if (strncmp(ch,"#",1)==0 )
			 					{	    
			 						stopper=3;
			 						goto startx;

			 					}



			 					ch = strtok(NULL, " ");

			 				}




			 			}

			 			return 0;}