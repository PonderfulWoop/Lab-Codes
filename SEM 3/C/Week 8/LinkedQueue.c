#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE head;

void Insert(int);
void Delete();
void Display();
NODE getNode();
int main()
{
    int Choice, num;
    head=getNode();
    head->info=0;
    while(1)
    {
        printf("1. Insert.\n");
        printf("2. Delete.\n");
        printf("3. Display.\n");
        printf("0. Exit.\n");
        printf("Enter your choice: ");
        scanf ("%d", &Choice);
        if (Choice==0)
            break;
        switch(Choice)
        {
          case 1:
            printf("Enter the element: ");
            scanf ("%d", &num);
            Insert(num);
            break;

          case 2:
            Delete();
            break;

          case 3:
            Display();
            break;

          default:
            printf("Invalid Choice.\n");
        }
    }
    return 0;
}

void Insert (int num)
{
    NODE temp = getNode();
    NODE p;
    temp->info=num;

    if (head->info==0)
        head->link=temp;

    else
    {
        p=head->link;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
    head->info++;
}

void Delete()
{
    NODE temp;
    if (head->info==0)
        printf("The Queue is empty.\n");
    else
    {
        temp=head->link;
        printf("The deleted element is: %d\n", temp->info);
        head->link=temp->link;
        head->info--;
        free(temp);
    }
}

void Display()
{
    NODE temp;
    temp=head->link;
    if (head->info==0)
        printf("The queue is empty.\n");
    else
    {
        printf("The queue is:\n");
        while (temp!=NULL)
        {
            printf("%d, ", temp->info);
            temp=temp->link;
        }
        printf("\n\n");
    }
}

NODE getNode()
{
    NODE temp;
    temp=(NODE) malloc(sizeof(struct node));
    temp->link=NULL;
    return temp;
}