#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

void general_1000()
{   char num[10];//to hold start time
    char num2[10];//to hold end time
    char result[10];// hold the result of overall time taker
    char buf[1000];//used in transfer of amount of bytes required 
    int count; //use to hold the read count if it is EOF  will return 0 so the loop will end
    int c; //used to hold the count of write
    //clock_t t; //clock variable for clock
    double time_taken; //time taken variable to hold result
    time_t begin;   //start time variable 
    time_t end;     // end time variable
    int fd = open("Source.txt", O_CREAT | O_RDWR, S_IRWXU);  //Source file
    int fd2 = open("outputnosync1000.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU); //Destination file
    //int fd2 = open("outputosync1000.txt", O_CREAT | O_RDWR | O_APPEND|O_SYNC, S_IRWXU); (1)use this command for O Sync
    if (fd == -1 || fd2 == -1)
    {
        perror("error");    //check if file is correct
    }
    count = -2; //condition to make sure it goes into wihle loop
    begin = time(NULL); // noticing start time
    write(STDOUT_FILENO, "Start time: ", 12); 
    sprintf(num, "%ld", begin);
    write(STDOUT_FILENO, num, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",begin );
    while (count != 0)  //lopp starting to read write file
    {
        count = read(fd, buf, 1000);
        c = write(fd2, buf, count);
        //(2)sync() use this command for sync
        //(3)fsync(fd2); use this command for fsync
        //(4)fdatasync(fd2); use this command for fdatasync
    }
    close(fd); //closing source file  
    close(fd2); //closing destination file
    end = time(NULL); //noticing end time
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(num2, "%ld", end);
    write(STDOUT_FILENO, num2, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",end );
    time_taken = end - begin; //subtracting end and begin time to cal overall time taken
    write(STDOUT_FILENO, "Execution time nosync_1000:", 27);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10); //outputing time taken
    write(STDOUT_FILENO, "\n \n", 4);
    }

void nosync_1000()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[1000];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("Source.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputnosync1000.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 1000);
        c = write(fd2, buffer, returncount);
        //fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",endingtime );
    time_taken = endingtime - starttingtime;
    write(STDOUT_FILENO, "Execution time nosync_1000:", 27);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
    //printf(" %f\n",time_taken);
}
void nosync_100()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[100];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("Source.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputnosync100.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 100);
        c = write(fd2, buffer, returncount);
        //       fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time nosync_100: %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time nosync_100:", 26);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 9);
    write(STDOUT_FILENO, "\n \n", 4);
}
void fsync_1000()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[1000];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("ouputfsync1000.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 1000);
        c = write(fd2, buffer, returncount);
        fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    write(STDOUT_FILENO, "Execution time fsync_1000:", 26);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
    //printf("Execution time fsync_1000: %f\n",time_taken);
}

void fsync_100()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[100];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputfsync100.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 100);
        c = write(fd2, buffer, returncount);
        fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time fsync_100:", 25);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
void osync_1000()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[1000];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);

    int fd2 = open("outputosync1000.txt", O_CREAT | O_RDWR | O_APPEND | O_SYNC, S_IRWXU);

    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 1000);
        c = write(fd2, buffer, returncount);
        //fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time osync_1000: %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time osync_1000:", 26);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}

void osync_100()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[100];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);

    int fd2 = open("outputosync100.txt", O_CREAT | O_RDWR | O_APPEND | O_SYNC, S_IRWXU);

    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 100);
        c = write(fd2, buffer, returncount);
        //fsync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time osync_100:", 25);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
void sync_100()
{

    clock_t t;
    double time_taken;
    char starttime2[10];
    char result[10];
    char starttime[10];
    char buffer[100];
    int returncount;
    int c;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputsync100.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 100);
        c = write(fd2, buffer, returncount);
        sync();
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time sync_100:", 24);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
void sync_1000()
{

    int returncount;
    int c;
    clock_t t;
    char buffer[1000];
    char starttime[10];
    char starttime2[10];
    char result[10];
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputsync1000.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 1000);
        c = write(fd2, buffer, returncount);
        sync();
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time sync_1000:", 25);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
void fdatasync_100()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[100];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputfdatasync100.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );
    //t = clock();
    while (returncount != 0)
    {
        returncount = read(fd, buffer, 100);
        c = write(fd2, buffer, returncount);
        fdatasync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;
    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time fdatasync_100:", 29);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
void fdatasync_1000()
{

    char starttime[10];
    char starttime2[10];
    char result[10];
    char buffer[1000];
    int returncount;
    int c;
    clock_t t;
    double time_taken;
    time_t starttingtime;
    time_t endingtime;
    int fd = open("testtry1x.txt", O_CREAT | O_RDWR, S_IRWXU);
    int fd2 = open("outputfdatasync1000.txt", O_CREAT | O_RDWR | O_APPEND, S_IRWXU);
    if (fd == -1 || fd2 == -1)
    {
        perror("error");
    }
    returncount = -2;
    starttingtime = time(NULL);
    write(STDOUT_FILENO, "Start time: ", 12);
    sprintf(starttime, "%ld", starttingtime);
    write(STDOUT_FILENO, starttime, 10);
    write(STDOUT_FILENO, "\n", 2);
    //printf("%ld\n",starttingtime );

    while (returncount != 0)
    {
        returncount = read(fd, buffer, 1000);
        c = write(fd2, buffer, returncount);
        fdatasync(fd2);
    }
    close(fd);
    close(fd2);
    endingtime = time(NULL);
    //printf("%ld\n",endingtime );
    write(STDOUT_FILENO, "End time: ", 10);
    sprintf(starttime2, "%ld", endingtime);
    write(STDOUT_FILENO, starttime2, 10);
    write(STDOUT_FILENO, "\n", 2);
    time_taken = endingtime - starttingtime;

    //printf("Execution time): %f\n",time_taken);
    write(STDOUT_FILENO, "Execution time fdatasync_1000:", 30);
    sprintf(result, "%f", time_taken);
    write(STDOUT_FILENO, result, 10);
    write(STDOUT_FILENO, "\n \n", 4);
}
int main(void)
{
    nosync_1000();    //Done
    nosync_100();     //Done
    fsync_100();      //Done
    fsync_1000();     //Done
    osync_1000();     //Done
    osync_100();      //Done
    sync_100();       //Done
    sync_1000();      //DONE
    fdatasync_1000(); //DONE
    fdatasync_100();  //Done

    return 0;
}