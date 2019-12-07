#include <stdio.h>
#include <stdlib.h>
struct node
{
    char info;
    struct node *link;
};
typedef struct node *NODE;


void Insert(NODE, char);
void Display(NODE);
NODE getNode();
int main()
{
    int num, i, c1, c2;
    char item;
    NODE head1, head2, head3;
    NODE temp1, temp2;
    head1=getNode();
    head2=getNode();
    head3=getNode();
    printf("First List:\n");
    printf("Enter the number of elements: ");
    scanf ("%d", &num);
    printf ("Enter the elements in sorted order:\n");
    for (i=0; i<num; i++)
    {
        scanf("%c", &item);
        scanf("%c");
        Insert(head1, item);
    }
    printf("Second List:\n");
    printf("Enter the number of elements: ");
    scanf ("%d", &num);
    printf ("Enter the elements in sorted order:\n");
    for (i=0; i<num; i++)
    {
        scanf("%c", &item);
        scanf("%c");
        Insert(head2, item);
    }
    temp1=head1->link;
    temp2=head2->link;
    while (temp1!=NULL&&temp2!=NULL)
    {
        c1=(int)temp1->info;
        c2=(int)temp2->info;
        if (c1<c2)
        {
            Insert(head3, temp1->info);
            temp1=temp1->link;
        }
        else
        {
            Insert (head3, temp2->info);
            temp2=temp2->link;
        }
    }
    while (temp1!=NULL)
    {
        Insert(head3, temp1->info);
        temp1=temp1->link;
    }
    while (temp2!=NULL)
    {
        Insert (head3, temp2->info);
        temp2=temp2->link;
    }

    Display(head3);
    return 0;
}

void Insert (NODE head, char item)
{
    NODE temp = getNode();
    NODE p;
    temp->info=item;
    temp->link=NULL;

    if (head->link==NULL)
        head->link=temp;

    else
    {
        p=head->link;
        while(p->link!=NULL)
            p=p->link;
        p->link=temp;
    }
}


void Display(NODE head)
{
    NODE temp;
    temp=head->link;
    if (head->link==NULL)
        printf("The list is empty.\n");
    else
    {
        printf("The joined list is:\n");
        while (temp!=NULL)
        {
            printf("%c, ", temp->info);
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