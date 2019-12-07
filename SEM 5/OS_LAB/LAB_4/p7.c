#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

int closedir(DIR *dirp);

int main(){
    char dirname[100];
    DIR *p;
    struct dirent *d;
    printf("Enter directory name\n");
    scanf("%s", dirname);
    p = opendir(dirname);
    if(!p){
        printf("Cannot find directory\n");
        exit(-1);
    }
    while(d = readdir(p)){
        printf("%s\n", d->d_name);
    }
    exit(0);
}