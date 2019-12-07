#include <stdio.h>

struct deq
{
    int r,f;
    int a[5];
};

void addright(struct deq * q,int ele)
{
    q->a[++(q->r)]=ele;
}

int deleteleft(struct deq * q)
{
    int a=q->a[q->f];
    if(q->f==q->r)
    {
        q->f=0;
        q->r=-1;
    }
    else
        q->f++;
    return a;
}

void addleft(struct deq * q,int ele)
{
    if(q->r==-1)
    {
        q->r=0;
        q->a[q->f]=ele;
    }
    else
    {
        q->f--;
        q->a[q->f]=ele;
    }


}

int deleteright(struct deq * q)
{
   int a=q->a[q->r];
    if(q->f==q->r)
    {
        q->f=0;
        q->r=-1;
    }
    else
        q->r--;
    return a;
}

void showq(struct deq * q)
{
    int i=q->f;
    if(q->r<q->f)
        printf("\nDouble Ended Que is Empty");
    else
    {
        for(i=q->f;i<=q->r;i++)
            printf("%d\t",q->a[i]);
    }

}

int main()
{
    int ch;
    int ele;
    struct deq q;
    q.f=0;
    q.r=-1;

    while(1)
    {
            printf("\n\n****MENU****");
            printf("\n1.INSERT IN QUEUE FROM LEFT");
            printf("\n2.INSERT IN QUEUE FROM RIGHT");
            printf("\n3.DELETE FROM QUEUE FROM LEFT");
            printf("\n4.DELETE FROM QUEUE FROM RIGHT");
            printf("\n5.SHOW QUEUE");
            printf("\n6.EXIT");
            printf("\n\nEnter Your Choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1:
                    if(q.f==0 && q.r!=-1)
                        printf("\nINSERTION NOT POSSIBLE FROM LEFT");
                    else
                    {
                        printf("\nEnter The Number: ");
                        scanf("%d",&ele);
                        addleft(&q,ele);
                    }
                break;

                case 2:
                if(q.r==4)
                        printf("\nINSERTION NOT POSSIBLE FROM RIGHT");
                    else
                    {
                        printf("\nEnter The Number: ");
                        scanf("%d",&ele);
                        addright(&q,ele);
                    }
                break;

                case 3:
                if(q.r<q.f)
                    printf("\nQueue Empty");
                else
                    printf("\nElement Deleted from Left Is - %d",deleteleft(&q));
                break;

                case 4:
                if(q.r<q.f)
                    printf("\nQueue Empty");
                else
                    printf("\nElement Deleted from Right Is - %d",deleteright(&q));
                break;


                case 5:
                   showq(&q);
                   break;
                case 6:
                    exit(0);

                default:
                    printf("\nIncorrect Choice Entered, Please Enter Again!!");

            }
    }

    return 0;

}
