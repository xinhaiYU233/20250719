#include<process_copy.h>

int busines_cur(char*srcfile,int pronum){
int fd = open(srcfile,O_RDONLY);

if(fd == -1){
printf("open file %s failed------busines_cur.c\n",srcfile);	
return -1;}

int size = lseek(fd,0,SEEK_END);
if(size == 0){
printf("Empty file------busines_cur.c\n");
return -1;
}

if(size % pronum == 0){

	return size/pronum;
}

return size/pronum+1;
}
