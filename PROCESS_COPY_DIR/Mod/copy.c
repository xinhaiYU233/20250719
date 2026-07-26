#include<process_copy.h>

int main(int argc,char*argv[]){

printf("Process %d is tunning copy.c\n",getpid());
if(argc!=5){
printf("Wrong Parameter-----copy.c\n");	
return -1;}

char*srcfile =argv[1];
char*destfile = argv[2];
int blocksize = atoi(argv[3]);
int offset = atoi(argv[4]);

int sfd =open(srcfile,O_RDONLY);
if(sfd == -1){
	
printf("open srcfile failed------copy.c\n");	
return -1;}

int dfd =open(destfile,O_RDWR|O_CREAT,0644);
if(dfd < 0){
printf("open destfile failed------copy.c\n");
close(sfd);	
return -1;}

char buf[blocksize];
int readlen;

lseek(sfd,offset,SEEK_SET);
lseek(dfd,offset,SEEK_SET);
while((readlen = read(sfd,buf,blocksize))>0){

write(dfd,buf,readlen);

}

close(sfd);
close(dfd);


return 0;
}
