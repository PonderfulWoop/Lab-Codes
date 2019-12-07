#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    float weight;
    int value;
}Item;

typedef struct Node{
    int level, profit, bound;
    float weight;
}Node;

Item List[50];
int n, Capacity;

void Sort_Items(){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-i-1; j++){
            float val1 = List[j].value/List[j].weight;
            float val2 = List[j+1].value/List[j].weight;
            if(val2>val1){
                Item temp = List[j];
                List[j] = List[j+1];
                List[j+1] = temp;
            }
        }
    }
}

int empty(Node q[], int k, int f){
    for(int i = f; i<=k; i++)
        if(q[i].weight != -1)
            return 0;
    
    return 1;
}

int  dequeue(Node q[], int f){
    q[f].weight = -1;
    f++;
    return f;
}

int bound(Node u){
    if(u.weight >= Capacity)
        return 0;

    int profit_bound = u.profit;

    int j = u.level + 1;
    int tot_weight = u.weight;

    while((j<n) && (tot_weight + List[j].weight <= Capacity)){
        tot_weight += List[j].weight;
        profit_bound += List[j].value;
        j++;
    }

    if(j<n)
        profit_bound += (Capacity - tot_weight) * (List[j].value/List[j].weight);
    
    return profit_bound;
}

int knap(){
    Sort_Items();

    Node Queue[50];
    for(int i = 0; i<50; i++)
        Queue[i].weight = -1;
    int k = -1;
    int f = -1;
    Node u,v;

    u.level = -1;
    u.profit = u.weight = 0;
    Queue[++k] = u;
    f++;

    int maxProfit = 0;
    while(!empty(Queue, k, f)){
        u = Queue[f];
        f = dequeue(Queue,f);

        if(u.level == -1)
            v.level = 0;
        
        if(u.level == n-1)
            continue;
        
        v.level = u.level + 1;

        v.weight = u.weight + List[v.level].weight;
        v.profit = u.profit + List[v.level].value;

        if(v.weight <= Capacity && v.profit > maxProfit)
            maxProfit = v.profit;
        
        v.bound = bound(v);
        if(v.bound > maxProfit)
            Queue[++k] = v;
        
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v);
        
        if(v.bound > maxProfit)
            Queue[++k] = v;
    }

    return maxProfit;
}

int main(){
    Capacity = 10;
    n = 5;

    int v[] = {40, 50, 100, 95, 30};
    float w[] = {2, 3.14, 1.98, 5, 3};

    for(int i = 0; i<n; i++){
        List[i].weight = w[i];
        List[i].value = v[i];
    }
    printf("Maximum Profit: %d\n", knap());

    return 0;
}