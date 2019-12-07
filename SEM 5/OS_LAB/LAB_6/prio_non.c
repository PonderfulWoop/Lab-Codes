#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Process{
    int id, arr_time, burst_time, priority;
};

typedef struct Process Process;
int n;

int get_new(Process ps[], int curr_time){
    int pos = -1;
    int p = (int)INFINITY;

    for(int i = 0; i<n; i++){
        if(ps[i].burst_time > 0 && ps[i].priority < p && ps[i].arr_time <= curr_time){
            pos = i;
            p = ps[i].priority;
        }
    }

    return pos;
}

void calc_and_disp(Process ps[]){
    int tot_time = 0;
    for(int i = 0; i<n; i++)
        tot_time+=ps[i].burst_time;

    int pos = get_new(ps, 0);
    int ft[n];

    for(int i = 0; i<=tot_time; i++){
        if(ps[pos].burst_time>0){
            ps[pos].burst_time--;
        }
        else{
            ft[pos] = i;
            pos = get_new(ps, i);
            if(pos == -1)
                break;
            ps[pos].burst_time--;
        }
    }

    printf("Finish times: \n");
    for(int i = 0; i<n; i++)
        printf("%d ", ft[i]);
    printf("\n");
}

int main(){
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    Process ps[n];
    printf("Enter AT, BT, Prio for processes:\n");
    for(int i = 0; i<n; i++)
        scanf("%d %d %d", &ps[i].arr_time, &ps[i].burst_time, &ps[i].priority);

    calc_and_disp(ps);

    exit(0);
}