#include<process_copy.h>

int Pram_check(int argc,char*srcfile,int pronum){
if(argc<3){
printf("Too less Parameter------Pram_check.c\n");	
return -1;}

if((access(srcfile,F_OK)!=0)){
printf("access failed------Pram_check.c\n");	
return -1;}

if(pronum<5||pronum>100){
	
printf("Pronum failed------Pram_check.c\n");	
return -1;}

printf("Parameters are right------Pram_check.c\n");	
return 0;
}
