#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct process{
    int pid;
    int arr_time;
    int burst_time;
};
int n;
typedef struct process Process;

int proc_arrives(int i, Process ps[]){
    for(int k = 0; k<n; k++){
        if(ps[k].arr_time == i)
            return ps[k].pid;
    }
    return 0;
}

int get_new_proc(int k, Process ps[]){
    int proc_time= (int) INFINITY;
    int proc_id = -1;
    for(int i = 0; i<n; i++){
        if(ps[i].burst_time > 0 && ps[i].burst_time < proc_time && ps[i].arr_time <= k){
            proc_time = ps[i].burst_time;
            proc_id = i;
        }

    }
    if(proc_id<n && proc_id>=0)
        return proc_id;
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

    for(int curr_time = 0; curr_time<=tot_time; curr_time++){
        int pid;
        if((pid = proc_arrives(curr_time, ps)) != 0){
            if(ps[pid-1].burst_time < ps[curr_exec].burst_time){
                printf("Curr. Time: %d; Process: %d stopped; Process: %d starts.\n", curr_time, curr_exec+1, pid);
                curr_exec = pid - 1;
            }
        }
        if(ps[curr_exec].burst_time>0)
            ps[curr_exec].burst_time--;
        else{
            ft[curr_exec] = curr_time;
            int temp = curr_exec;
            curr_exec = get_new_proc(curr_time, ps);
            if(curr_exec == -1)
                break;
            printf("Curr. Time: %d; Process: %d stopped; Process: %d starts.\n", curr_time, temp+1, curr_exec+1);
            ps[curr_exec].burst_time--;
        }
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
    
    calculate_and_disp(ps);
    exit(0);
}