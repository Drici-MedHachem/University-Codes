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

void ROUND_ROBIN(process p[], int n, int quantum) {
    int time = 0;
    int completed = 0;
    int remaining[MAX];

    for (int i = 0; i < n; i++) {
        remaining[i] = p[i].burst_time;
    }

    int queue[MAX];
    int front = 0, rear = 0;

    int in_queue[MAX] = {0};

    int last_pid = -2;

    while (completed < n) {

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= time && !in_queue[i] && remaining[i] > 0) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (front == rear) {
            if (last_pid != IDLE_PROC) {
                add_gantt(IDLE_PROC, time, time + 1);
                last_pid = IDLE_PROC;
            } else {
                gantt[gantt_idx - 1].end++;
            }
            time++;
            continue;
        }

        int idx = queue[front++];

        int exec_time = (remaining[idx] < quantum) ? remaining[idx] : quantum;

        if (last_pid != p[idx].pid) {
            add_gantt(p[idx].pid, time, time + exec_time);
            last_pid = p[idx].pid;
        } else {
            gantt[gantt_idx - 1].end += exec_time;
        }

        time += exec_time;
        remaining[idx] -= exec_time;

        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time > time - exec_time && p[i].arrival_time <= time && !in_queue[i] && remaining[i] > 0) {
                queue[rear++] = i;
                in_queue[i] = 1;
            }
        }

        if (remaining[idx] > 0) {
            queue[rear++] = idx;
        } else {
            completed++;
            p[idx].completion_time = time;
            p[idx].turnaround_time = time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
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

    printf("\nAverage Waiting Time = %.2f\n", (float)total_waiting_time / n);
    printf("Average Turnaround Time = %.2f\n", (float)total_turnaround_time / n);

}


int main() {
    process p[MAX];
    int n;
    int quantum;
    printf("Quantum : ");
    scanf("%d",&quantum);
    printf("\n");
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


    ROUND_ROBIN(p,n,quantum);
    print_gantt();
    display(p,n);

    return 0;
}