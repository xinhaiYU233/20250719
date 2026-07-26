#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>

//function claim
int Pram_check(int argc,char*srcfile,int pronum);

int busines_cur(char* srcfile , int pronum);

int process_create(char*srcfile,char*destfile,int pronum,int blocksize);
