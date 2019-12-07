#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 8
#define str_size 100

typedef struct {
    int front;
    int rear;
    char arr[max_size][str_size];
}q;

void init(q* x){
    x->front = 0;
    x->rear = 0;
}

void insert(q* x,char* item){
    if((x->rear+1)%max_size==x->front){
        printf("\n\a Queue is full element cannot be inserted\n");
        return 0;
        }
    else{
    strcpy(x->arr[x->rear],item);
    x->rear = (x->rear+1)%max_size;
    }
}

char* delete(q* x){
    if(x->front==x->rear){
        printf("\n Queue is empty\n");
        return NULL;
    }
    else{
        char* t;
        t = x->arr[x->front];
       x->front = (x->front+1)%max_size;
       return t; }
}

void display(q* x){
    int i;
    printf("\n");
    for(i=x->front;i<x->rear;){
            printf(" %s\t",x->arr[i]);
            i = (i+1)%max_size;
    }
    printf("\n");
}

int main()
{
    int c;
    q q1;
    init(&q1);
    char x[str_size],*t;
    while(1){
        printf("\n1. Insert\t2. Delete\t3. Display\t4. Exit -> ");
        scanf("%d",&c);
        getchar();
        switch(c){
        case 1: printf("\n String -> ");
                gets(x);
                insert(&q1,x);
                break;
        case 2: t = delete(&q1);
                strcpy(x,t);
                if(x!=NULL)
                printf("\n Deleted -> %s\n",x);
                else{}
                break;
        case 3: display(&q1);
                break;
        default:exit(0);
        }
    }
    return 0;
}