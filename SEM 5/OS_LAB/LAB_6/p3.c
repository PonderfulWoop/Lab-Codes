#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct process{
    int pid;
    int arr_time;
    int burst_time;
};
int n, quant;
typedef struct process Process;

int get_new_proc(int curr_proc, int k, Process ps[]){
    int j = (curr_proc + 1)%n;
    while(j != curr_proc){
        if(ps[j].arr_time<=k && ps[j].burst_time>0)
            return j;
        j = (j+1)%n;
    }
    if(ps[curr_proc].burst_time>0)
        return curr_proc;
    else
        return -1;
}

void calculate_and_disp(Process ps[]){
    int tot_time = 0;
    int curr_exec;
    int bts[n];
    int ft[n];

    for(int i = 0; i<n; i++)
        tot_time+=ps[i].burst_time;
    for(int i = 0; i<n; i++)
        bts[i] = ps[i].burst_time;

    curr_exec = 0;

    for(int curr_time = 0; curr_time<=tot_time;){
        int local_quant = quant;
        while(ps[curr_exec].burst_time>0 && local_quant>0){
            ps[curr_exec].burst_time--;
            local_quant--;
            curr_time++;
        } 
        ft[curr_exec] = curr_time;
        int temp = curr_exec;
        curr_exec = get_new_proc(curr_exec, curr_time, ps);
        if(curr_exec == -1)
            break;
        printf("Curr. Time: %d; Process: %d stopped; Process: %d starts.\n", curr_time, temp+1, curr_exec+1);
    }
    printf("\n");
    int avg_wt = 0, avg_tat = 0;
    for(int i = 0; i<n; i++){
        printf("For P%d, FT: %d, TAT: %d, WT: %d\n", (i+1), ft[i], ft[i] - ps[i].arr_time, ft[i] - ps[i].arr_time - bts[i]);
        avg_wt += ft[i] - ps[i].arr_time - bts[i];
        avg_tat += ft[i] - ps[i].arr_time;
    }
    printf("Average WT = %d, Average TAT = %d\n", (avg_wt/n),(avg_tat/n));
}

int main(){
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    Process ps[n];
    for(int i = 0; i<n; i++){
        printf("Enter AT and BT for Process [%d]:\n", (i+1));
        scanf("%d", &ps[i].arr_time);
        scanf("%d", &ps[i].burst_time);
        ps[i].pid = i+1;
    }
    printf("Enter Quant:\n");
    scanf("%d", &quant);
    
    calculate_and_disp(ps);
    exit(0);
}