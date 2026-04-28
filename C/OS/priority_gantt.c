#include <stdio.h>

#define MAX 20
#define IDLE_PROC 0
typedef struct {
    int pid;
    int priority;
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


void PRIORITY(process p[], int n) {
    int time = 0;
    int completed = 0;
    int visited[MAX] = {0};

    while (completed < n) {
        int idx = -1;
        int max_priority = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && p[i].arrival_time <= time) {
                if (p[i].priority > max_priority) {
                    max_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            int next_arrival = 1e9;
            for (int i = 0; i < n; i++) {
                if (!visited[i] && p[i].arrival_time < next_arrival) {
                    next_arrival = p[i].arrival_time;
                }
            }

            add_gantt(IDLE_PROC, time, next_arrival);
            time = next_arrival;
        } else {
            add_gantt(p[idx].pid, time, time + p[idx].burst_time);

            time += p[idx].burst_time;

            p[idx].completion_time = time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;

            visited[idx] = 1;
            completed++;
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

        printf("Priority P%d : ",p[i].pid);
        scanf("%d",&p[i].priority);

        printf("Arrival Time P%d : ",p[i].pid);
        scanf("%d",&p[i].arrival_time);


        printf("Burst time P%d : ",p[i].pid);
        scanf("%d",&p[i].burst_time);
        printf("\n");

    }


    PRIORITY(p,n);
    print_gantt();
    display(p,n);

    return 0;
}