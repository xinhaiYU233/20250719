#include<process_copy.h>

int main(int argc,char*argv[]){
int pronum;


if(argv[3] == 0){

pronum = 5;
}else{
pronum =atoi(argv[3]);
}

//call Pram_check
int check_num;
check_num = Pram_check(argc,argv[1],pronum);

if(check_num <0){
printf("Pram_check failed------main.c\n");	
return -1;}

//call busines_cur
int blocksize;
blocksize = busines_cur(argv[1],pronum);

if(blocksize <0){
printf("busines_cur failed------main.c\n");
return -1;}

//call process_create

check_num = process_create(argv[1],argv[2],pronum,blocksize);
if(check_num <0 -1){
printf("process_create failed------main.c\n");	
return -1;}

return 0;
}
