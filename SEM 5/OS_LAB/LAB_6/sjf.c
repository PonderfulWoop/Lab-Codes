#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Process{
    int id, burst_time, arr_time;
};

typedef struct Process Process;
int n;

int get_new(Process ps[], int curr){
    int pos = -1;
    int bt = (int) INFINITY;

    for(int i = 0; i<n; i++){
        if(ps[i].burst_time>0 && ps[i].burst_time<bt && ps[i].arr_time <= curr){
            pos = i;
            bt = ps[i].burst_time;
        }
    }

    return pos;
}

void calc_and_disp(Process ps[]){
    int full_t = 0;
    for(int i = 0; i<n; i++)
        full_t+=ps[i].burst_time;
    
    int pos = get_new(ps, 0);
    printf("exec: %d\n", pos);
    int ft[n];
    for(int i = 0; i<=full_t; i++){
        if(ps[pos].burst_time>0){
            ps[pos].burst_time--;
        }
        else{
            ft[pos] = i;
            pos = get_new(ps, i);
            if(pos == -1)
                break;
            printf("exec: %d\n", pos);
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
    printf("Enter AT and BT for processes:\n");
    for(int i = 0; i<n; i++)
        scanf("%d %d", &ps[i].arr_time, &ps[i].burst_time);

    calc_and_disp(ps);

    exit(0);
}