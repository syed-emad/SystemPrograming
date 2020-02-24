#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main()
{

  //int counter;

  //input1 for selection funtion to perform
  char input1[1];

  //to hold function value
  int functioname;

  //amount of numbers to add number
  char number1[4];

  //Function names use for showing message
  char Add[8] = "Addition";
  char Subtract[11] = "Subtraction";
  char Multiply[8] = "Multiply";
  char Divide[6] = "Divide";
  char Exit[23] = "Exiting Program.....";

//char *ptr;
//long ret;

//1st start point
start:

  write(STDOUT_FILENO, "Input 1,2,3 or 4 and press enter \n 1)Add 2)Sub 3)Mult 4)Div 5)Exit \n ", 70);
  int check = read(STDIN_FILENO, input1, 2);

  sscanf(input1, "%d", &functioname);
  //printf("%s\n","valuee" );
  //printf("%d\n", functioname);

  //if user inputs integer value in tens or hundred
  if (functioname > 5 || functioname < 1) //condition check
  {
    functioname = 0; //reseting value

    write(STDOUT_FILENO, "Undefined Function Selectedx", 28);
    goto start; //sending it back to start
  }
  //Error if Wrong input selected
  if (functioname != 1 && functioname != 2 && functioname != 3 && functioname != 3 && functioname != 4)
  { //normal msg output
    write(STDOUT_FILENO, "Undefined Function Selected", 27);
    write(STDOUT_FILENO, "\n", 2);
    write(STDOUT_FILENO, "/--Please Select Correct Input--/", 36);
    write(STDOUT_FILENO, "\n", 2);
    //goto start of code
    goto start;
  }
  write(STDOUT_FILENO, "Fuction Selected:", 17);

  //normal msg output
  if (functioname == 1)
  {
    write(STDOUT_FILENO, Add, 8);
    write(STDOUT_FILENO, "\n", 2);
  }
  if (functioname == 2)
  {
    write(STDOUT_FILENO, Subtract, 11);
    write(STDOUT_FILENO, "\n", 2);
  }
  if (functioname == 3)
  {
    write(STDOUT_FILENO, Multiply, 8);
    write(STDOUT_FILENO, "\n", 2);
  }
  if (functioname == 4)
  {
    write(STDOUT_FILENO, Divide, 6);
    write(STDOUT_FILENO, "\n", 2);
  }
  if (functioname == 5)
  {
    write(STDOUT_FILENO, Exit, 24);
    write(STDOUT_FILENO, "\n", 2);
    exit(0);
  }

  //2nd start point
  int alphabet = 0, number = 0, space = 0, i;
start2:
  write(STDOUT_FILENO, "Input how many numbers you want ", 32);
  int nr = read(STDIN_FILENO, number1, 20);
  //if no value is inputed and enter is pressed
  if (nr == 1)
  {
    write(STDOUT_FILENO, "Please Enter a value", 20);
    write(STDOUT_FILENO, "\n", 2);
    goto start2;
  }
  // check for alphabets

  for (i = 0; number1[i] != '\0'; i++)
  {

    if (isalpha(number1[i]) != 0)
      alphabet++;
    else if (isspace(number1[i]) != 0)
      space++;
  }
  if (alphabet != 0 || space > 1)
  {
    alphabet = 0;
    space = 0;
    //resets all the values in an array.2nd parameter tells the value to be set
    //and the 3rd parameter tells the number of bytes to set the value to.
    //memset(number1, 0, 255);

    memset(number1, 0, 255);
    write(STDOUT_FILENO, "Incorrect Input2", 17);

    write(STDOUT_FILENO, "\n", 2);
    //write(STDOUT_FILENO,"Incorrect Input1",17);

    write(STDOUT_FILENO, "\n", 2);
    goto start2;
  }
  //printf("%s\n","space" );
  //printf("%d\n",space );
  //else if (space >1)
  //	{
  //		goto start2;
  //	}

  char *name;
  int limit;

  limit = 3000;

  //allocating memory dynamically
  name = (char *)malloc(limit * sizeof(char));
  char array[limit];
  int alphabet2 = 0, number2 = 0, space2 = 0;
start3:

  write(STDOUT_FILENO, "Input Numbers,Add spaces between numbers ", 42);
  int a = read(STDIN_FILENO, array, limit);

  for (int i = 0; array[i] != '\0'; i++)
  {
    if (isalpha(array[i]) != 0)
      alphabet2++;
    else if (isspace(array[i]) != 0)
      space2++;
  }

  if (alphabet2 != 0 || space2 == 1)
  {
    memset(array, 0, 255);
    alphabet2 = 0;
    write(STDOUT_FILENO, "Incorrect Input", 17);
    write(STDOUT_FILENO, "\n", 2);

    //exit(0);
    goto start3;
  }

  if (a == 1)
  {
    printf("%s\n", "Please Enter a value");
    goto start2;
  }
  //printing array
  write(STDOUT_FILENO, array, a);

  //creating pointer
  char *ch;
  ch = strtok(array, " ");

  //used to hold the current pointer vallue
  int buff;
  //use to hold the result of each iteration sum, sub etc
  int variable = atoi(ch);
  //next line
  char ch2[1] = "\n";
  //write(STDOUT_FILENO, ch2, 1);

  //addition
  if (functioname == 1)
  {
    char subtr[4];
    while (ch != NULL)
    {
      ch = strtok(NULL, " ");

      if (ch != NULL)
      {
        sscanf(ch, "%d", &buff);

        variable = variable + buff;
      }
    }

    int countsub = sprintf(subtr, "%d", variable);
    write(STDOUT_FILENO, "Result: ", 8);
    write(STDOUT_FILENO, subtr, countsub);
    write(STDOUT_FILENO, "\n", 2);

    goto start;
  }
  //Subtraction
  if (functioname == 2)
  {
    char subtr[4];
    while (ch != NULL)
    {
      ch = strtok(NULL, " ");

      if (ch != NULL)
      {
        sscanf(ch, "%d", &buff);

        variable = variable - buff;
      }
    }
    int countsub = sprintf(subtr, "%d", variable);
    write(STDOUT_FILENO, "Result: ", 8);
    write(STDOUT_FILENO, subtr, countsub);
    write(STDOUT_FILENO, "\n", 2);

    goto start;
  }
  //multiplication
  if (functioname == 3)
  {
    char subtr[4];
    while (ch != NULL)
    {
      ch = strtok(NULL, " ");

      if (ch != NULL)
      {
        sscanf(ch, "%d", &buff);

        variable = variable * buff;
      }
    }
    int countsub = sprintf(subtr, "%d", variable);
    write(STDOUT_FILENO, "Result: ", 8);
    write(STDOUT_FILENO, subtr, countsub);
    write(STDOUT_FILENO, "\n", 2);
    goto start;
  }

  if (functioname == 4)
  {
    char subtr[4];
    while (ch != NULL)
    {
      ch = strtok(NULL, " ");

      if (ch != NULL)
      {
        sscanf(ch, "%d", &buff);
        variable = variable / buff;
      }
    }
    int countsub = sprintf(subtr, "%d", variable);
    write(STDOUT_FILENO, "Result: ", 8);
    write(STDOUT_FILENO, subtr, countsub);
    write(STDOUT_FILENO, "\n", 2);

    goto start;
  }

  return 0;
}