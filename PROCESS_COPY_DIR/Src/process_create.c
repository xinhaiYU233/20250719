#include<process_copy.h>

int process_create(char*srcfile,char*destfile,int pronum,int blocksize){
pid_t pid;
pid_t zpid;
int i = 0;
for(i = 0;i<pronum;i++){
pid = fork();
if(pid == 0)break;
}

if(pid >0){
//recycle Zombine process
while((zpid = waitpid(-1,NULL,WNOHANG))!= -1){
	if(zpid>0){
printf("Process %d has been recycled------process_create.c\n",zpid);
}else if(zpid ==0){
	printf("there is no Zombine Process------process_create.c\n");
sleep(3);
}
}

}else if(pid == 0){
int offset = i*blocksize;
char stroffset[10];
char strblocksize[10];
bzero(stroffset,10);
bzero(strblocksize,10);
sprintf(stroffset,"%d",offset);
sprintf(strblocksize,"%d",blocksize);
execl("/home/colin/20250719/PROCESS_COPY_DIR/Mod/copy","copy",srcfile,destfile,strblocksize,stroffset,NULL);
}else{
perror("fork call failed\n");
exit(0);
}
return 0;
}
