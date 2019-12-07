#include <stdio.h>
#include <stdlib.h>

#define PAGES 8
#define PAGE_SIZE 32

int main(){
    int la;
    printf("Enter the logical address:\n");
    scanf("%d", &la);

    //Calc Page No.
    printf("Page No.: %d\n", la/PAGE_SIZE);

    //Offset
    printf("Offset: %d\n", la%PAGE_SIZE);

    exit(0);
}