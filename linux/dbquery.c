#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "student.h"

int main(int argc, char *argv[])
{
    int fd, id;
    struct student rec;
    char c;
    if(argc<2){
        fprintf(stderr, "사용법: %s file \n", argv[0]);
        exit(1);
    }

    if((fd=open(argv[1], O_RDONLY)) ==-1){
        perror(argv[1]);
        exit(2);
    }

    do{
        printf("\n 검색할 학생의 학번 입력:");
        if(scanf("%d", &id)==1){
            lseek(fd, (id-START_ID)*sizeof(rec), SEEK_SET);
            if((read(fd, &rec, sizeof(rec))>0) && (rec.id!=0))
                printf("학번 : %d\t 이름:%s\t 점수:%d\n", rec.id, rec.name, rec.score);
            else printf("레코드 %d 없음\n", id);
        }
        else printf("입력오류");
        
        printf("계속하겠습니까? (Y/N)");
        scanf(" %c", &c);
    }while(c=='Y');

    close(fd);
    exit(0);

}
