#include <stdio.h>
#include <stdlib.h>
#define max_size_1 10
#define max_size_2 20

typedef struct {
    int front;
    int rear;
    int arr[max_size_2];
}q;

void init(q* x,q* y){
    x->front = 0;
    x->rear = 0;
    y->front = max_size_2-max_size_1;
    y->rear = max_size_2-max_size_1;
}

void insert(q* x,int item,int m){
    int y;
    if(m==1){y = max_size_1;}
    else{y = max_size_2;}
    if((x->rear+1)%y==x->front){
        printf("\n Queue is full element cannot be inserted\n");
        return;
        }
    else{
    x->arr[x->rear] = item;
    x->rear = (x->rear+1)%y;
    if(m==2 && x->rear<10){
        x->rear += 10;
    }
    }
}

int delete(q* x,int m){
    int y;
    if(m==1){y = max_size_1;}
    else{y = max_size_2;}
    if(x->front==x->rear){
        printf("\n Queue is empty\n");
        return 0;
    }
    else{
        int t;
        t = x->arr[x->front];
       x->front = (x->front+1)%y;
       if(m==2 && x->front<10){
        x->front += 10;
        }
       return t; }
}

void display(q* x,int y){
    int i;
    printf("\n");
    if(y == 1){
    for(i=x->front;i<x->rear;){
            printf("\t%d",x->arr[i]);
            i = (i+1)%max_size_1;
    }}
    if(y==2){
    for(i=x->front;i<x->rear;){
            printf("\t%d",x->arr[i]);
            i = (i+1)%max_size_2;
    }}
    printf("\n");
}

int main()
{
    int c,x;
    q q1,q2;
    init(&q1,&q2);

    while(1){
        printf("\n\t1. Insert - First Queue \t2. Insert - Second Queue\n\t3. Delete from - First Queue\t4. Delete from - Second Queue\n\t5. Display - First Queue\t6. Display - Second Queue\n\t7. Exit -> ");
        scanf("%d",&c);
        getchar();
        switch(c){
        case 1: printf("\n\tElement -> ");
                scanf("%d",&x);
                insert(&q1,x,1);
                break;
        case 2: printf("\n\tElement -> ");
                scanf("%d",&x);
                insert(&q2,x,2);
                break;
        case 3: x = delete(&q1,1);
                printf("\n\tDeleted -> %d\n",x);
                break;
        case 4: x = delete(&q2,2);
                printf("\n\tDeleted -> %d\n",x);
                break;
        case 5: display(&q1,1);
                break;
        case 6: display(&q2,2);
                break;
        default:exit(0);
        }
    }
    return 0;
}