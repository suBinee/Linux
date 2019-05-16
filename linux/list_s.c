#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include<time.h>

void printSize(char*, char*, struct stat*);


int main(int argc, char **argv)
{
    DIR *dp;
    char *dir;
    struct dirent *d;
    struct stat st;
    char path[BUFSIZ+1];

    if(argc==1)
        dir=".";
    else dir=argv[1];

    if((dp=opendir(dir))==NULL)
        perror(dir);
    

    while((d=readdir(dp))!=NULL){
        sprintf(path,"%s/%s ",dir, d->d_name);
       // printf("path: %s\n", path);
        if(lstat(path, &st)<0)
            perror(path);
        else
            printSize(path, d->d_name, &st);
    }

    closedir(dp);
    exit(0);
}

void printSize(char *pathname, char *file, struct stat *st)
{
    printf("%9d", st->st_size);
}

