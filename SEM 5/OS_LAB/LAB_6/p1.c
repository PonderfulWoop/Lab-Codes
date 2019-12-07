#include <stdio.h>
#include <stdlib.h>

struct process{
    int pid;
    int arr_time;
    int burst_time;
};

typedef struct process Process;

void calculate_and_disp(int n, Process ps[]){
    int wt[n], tat[n];
    int avg_wt, avg_tat;
    wt[0] = 0;
    tat[0] = ps[0].burst_time;
    int btt = ps[0].burst_time;
    for(int i = 1; i<n; i++){
        wt[i] = btt - ps[i].arr_time;
        btt+= ps[i].burst_time;
        tat[i] = btt - ps[i].arr_time;
    }
    int sum_wt = 0, sum_tat = 0;
    for(int i = 0; i<n; i++){
        printf("PID: %d AT: %d BT: %d WT: %d TAT: %d\n", ps[i].pid, ps[i].arr_time, ps[i].burst_time, wt[i], tat[i]);
        printf("------------------------------------------\n");
        sum_wt+=wt[i];
        sum_tat+=tat[i];
    }
    printf("Average WT: %d\n", sum_wt/n);
    printf("Average TAT: %d\n", sum_tat/n);
}

int main(){
    int n;
    printf("Enter number of processes: \n");
    scanf("%d", &n);
    Process ps[n];
    for(int i = 0; i<n; i++){
        printf("Enter AT and BT for Process [%d]:\n", (i+1));
        scanf("%d", &ps[i].arr_time);
        scanf("%d", &ps[i].burst_time);
        ps[i].pid = i+1;
    }
    
    calculate_and_disp(n, ps);
    exit(0);
}