#include <stdio.h>

typedef struct{
	int r, f;
	int a[10];
}Queue;

void push(Queue *q, int a){
	if(q->r != 9){
		q->a[++(q->r)] = a;
	}
}
int isEmpty(Queue q){
	if(q.r == q.f)
		return 1;
	return 0;
}
int largest(int arr[], int n){
	int l = arr[0];
	for(int i = 1; i<n; i++){
		if(l<arr[i])
			l = arr[i];
	}
	return l;
}
int removeQ(Queue *q){
	if(q->r != -1){
		return q->a[++(q->f)];
	}
}

void radixSort(int arr[], int n){
	Queue q[10];
	int max = largest(arr, n);
	for(int exp = 1; max/exp > 0; exp*=10){
		for(int i = 0; i<10; i++){
		q[i].r = q[i].f = -1;
		}
		for(int j = 0; j<n; j++){
			push(&q[(arr[j]/exp)%10], arr[j]);
		}
		int l = 0;
		for(int k = 0; k<10; k++){
			while(!isEmpty(q[k])){
				arr[l] = removeQ(&q[k]);
				l++;
			}
		}
	}

}

int main(){
	int arr[] = {23, 433, 12, 9, 34};
	radixSort(arr, 5);
	for(int i = 0; i<5; i++)
		printf("%d ", arr[i]);
	printf("\n");
}