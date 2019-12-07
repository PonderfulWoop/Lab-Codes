#include <stdio.h>

struct Student
{
	int roll_no;
};



void Bubble_Sort(struct Student S[],int size)
{
  struct Student temp;
  int i,j;

  for(i=0;i<size-1;++i)
  	for(j=i+1;j<size;++j)
  		if(S[i].roll_no>S[j].roll_no)
  		{
  			temp=S[i];
  			S[i]=S[j];
  			S[j]=temp;
  		}
 
 printf("\nThe sorted list\n");

 for(i=0; i<size; ++i)
 {
 	printf("\nThe details of student %d are: \n", (i+1));
 	printf("%d",S[i].roll_no);
 }

}

void main()
{
	int size;

	printf("Enter the number of students:");
	scanf("%d",&size);
 
	struct Student S[size];

	for(int i=0; i<size; ++i )
	{
		printf("\nEnter the details for student %d :", (i+1));

		scanf("%d",&S[i].roll_no);


	}

	Bubble_Sort(S,size);
}