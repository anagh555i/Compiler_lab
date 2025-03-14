#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include<stdlib.h>

int main(int argc,char**argv){
//     printf("%d %s\n",argc,argv[1]);
    int fd=open(argv[1],O_RDONLY);
    char *input;
//     input= (char*)malloc(sizeof(char)*100);
//     int i=read(fd,input,100);
//     printf("%lld %d\n",fd,i);
//     printf("%s\n",input);
    // printf("%d",'a'-'A');
    char * s="hello";
    int i=0;
    for(i=0;i<5;i++)printf("%c\n",s[i]);
}