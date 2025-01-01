#include<stdio.h>
#include<string.h>

int main(){
    char *str="hellow";
    char temp[100];
    int n=strlen(str);
    strncpy(temp,str,n-1);
    temp[n-2]='\0';
    printf("%s\n",temp);
}