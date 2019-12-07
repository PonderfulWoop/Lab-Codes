#include <stdio.h>
struct pque
{
    int r,f;
    int a[10];
};

void insertq(struct pque *q,int ele)
{
    int pos=q->r;
    if(q->r==-1)
    {
        q->r++;
        q->a[q->r]=ele;
    }
    else
    {
            while(pos>=0 && q->a[pos]>ele )
            {
                q->a[pos+1]=q->a[pos];
                pos--;
            }

            q->a[pos+1]=ele;
            q->r++;
    }

}

int deleteq(struct pque * q)
{
    int ele;
    if(q->r==q->f)
    {
        ele=q->a[q->f];
        q->r=-1;
        q->f=0;
        return ele;
    }
    return(q->a[(q->f)++]);
}

void showq(struct pque *q)
{
    int i=0;
    printf("\nPriority Queue Is: ");
    for(i=q->f;i<=q->r;i++)
        printf("%d\t",q->a[i]);
}

int main()
{
    int ch;
    int ele;
    struct pque q;
    q.f=0;
    q.r=-1;

    while(1)
    {
            printf("\n\n****MENU****");
            printf("\n1.INSERT IN PRIORITY QUEUE");
            printf("\n2.DELETE FROM PRIORITY QUEUE");
            printf("\n3.SHOW PRIORITY QUEUE");
            printf("\n4.EXIT");
            printf("\n\nEnter Your Choice: ");
            scanf("%d",&ch);

            switch(ch)
            {
                case 1:
                    if( q.r==4)
                        printf("\nINSERTION NOT POSSIBLE IN PRIORITY QUEUE");
                    else
                    {
                        printf("\nEnter The Number: ");
                        scanf("%d",&ele);
                        insertq(&q,ele);
                    }
                break;


                case 2:
                if(q.r<q.f)
                    printf("\nPRIORITY QUEUE EMPTY");
                else
                    printf("\nELEMENT DELETED FROM PRIORITY QUEUE IS - %d",deleteq(&q));
                break;


                case 3:
                if(q.r<q.f)
                    printf("\nPRIORITY QUEUE EMPTY");
                else
                   showq(&q);
                   break;
                case 4:
                    exit(0);

                default:
                    printf("\nIncorrect Choice Entered, Please Enter Again!!");

            }
    }

    return 0;

}
