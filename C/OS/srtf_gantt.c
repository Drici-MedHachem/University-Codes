#include <stdio.h>

#define MAX 20
#define IDLE_PROC 0
typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
} process;

typedef struct {
    int pid;
    int start;
    int end;
} slice;

slice gantt[100];
int gantt_idx = 0;

void add_gantt(int pid, int start, int end) {
    if (start >= end)
        return;

    gantt[gantt_idx].pid = pid;
    gantt[gantt_idx].start = start;
    gantt[gantt_idx].end = end;

    gantt_idx++;
}

void print_gantt() {

    printf("\n Gantt Diagram :\n");
    for (int i = 0; i < gantt_idx; i++) {
        printf("+------");
    }
    printf("+\n");


    for (int i = 0; i < gantt_idx; i++) {
        if (gantt[i].pid == IDLE_PROC)
            printf("| IDLE ");
        else
            printf("| P%-3d ", gantt[i].pid);
    }
    printf("|\n");


    for (int i = 0; i < gantt_idx; i++) {
        printf("+------");
    }
    printf("+\n");


    printf("%d", gantt[0].start);
    for (int i = 0; i < gantt_idx; i++) {
    printf("      %d", gantt[i].end);
    }

    printf("\n");
}


void SRTF(process p[], int n) {
    int time = 0;
    int completed = 0;
    int remaining[MAX];
    
    for (int i = 0; i < n; i++) {
        remaining[i] = p[i].burst_time;
    }

    int last_pid = -2; 

    while (completed < n) {
        int idx = -1;
        int min_remaining_time = 1e9;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && remaining[i] > 0) {
                if (remaining[i] < min_remaining_time) {
                    min_remaining_time = remaining[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            if (last_pid != IDLE_PROC) {
                add_gantt(IDLE_PROC, time, time + 1);
                last_pid = IDLE_PROC;
            } else {
                gantt[gantt_idx - 1].end++;
            }
            time++;
        } else {
            if (last_pid != p[idx].pid) {
                add_gantt(p[idx].pid, time, time + 1);
                last_pid = p[idx].pid;
            } else {
                gantt[gantt_idx - 1].end++;
            }

            remaining[idx]--;
            time++;

            if (remaining[idx] == 0) {
                completed++;
                p[idx].completion_time = time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
            }
        }
    }

}


void display(process p[], int n) {
    int total_waiting_time = 0 , total_turnaround_time = 0;

    printf("\n Results Table: \n");

    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");


    for(int i = 0 ; i < n ; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,
        p[i].arrival_time,
        p[i].burst_time,
        p[i].completion_time,
        p[i].turnaround_time,
        p[i].waiting_time);

    total_waiting_time += p[i].waiting_time;
    total_turnaround_time += p[i].turnaround_time;
    }


}


int main() {
    process p[MAX];
    int n;
    
    printf("Number of processes : ");
    scanf("%d",&n);
    printf("\n");

    for(int i = 0 ; i < n ; i++) {
        p[i].pid = i+1;

        printf("Arrival Time P%d : ",p[i].pid);
        scanf("%d",&p[i].arrival_time);


        printf("Burst time P%d : ",p[i].pid);
        scanf("%d",&p[i].burst_time);
        printf("\n");

    }


    SRTF(p,n);
    print_gantt();
    display(p,n);

    return 0;
}