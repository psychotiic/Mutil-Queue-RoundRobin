#include "processQueue.h"
#include<stdlib.h> 
#include <stdio.h>

#include <time.h>  // needed to get the time
#include <sys/time.h> // to get the time
#include <string.h> // to get strings
     

    double R(double min, double max){
    return (double)rand()/(double)RAND_MAX * (max - min) + min;
}
    /* Process list entry initialization routine */
    struct process *init_process (int pid, int burst, int priority) {
    struct process *proc;
    proc = malloc(sizeof(struct process));
    if (proc == NULL) {
    printf(">>ERROR: Memory Allocation Failure.\nShutting Down.\n");
    exit(1);
    };
    proc->pid = pid;
    proc->burst = burst;
    proc->priority = priority;
    proc->working = 0;
    proc->waiting = 0;
    proc->next = NULL;
    return(proc);
    };
    /* Process listing */
    void listprocs (struct process *proc) {
    struct process *tmp = proc;
     
    printf("STARTING:\tList of Current Running Processes\n");
     
    while (tmp != NULL) {
    printf("PID: %d\t\tPriority: %d\tBurst Time: %d\n", tmp->pid, tmp->priority, tmp->burst);
    tmp = tmp->next;
    };
     
    printf("ENDING:\tList of Current Running Processes\n\n");
    };
     
     
    /* Priority scheduling simulation
     * Note: lower priority value gets a higher priority
     */
    void priority (struct process *proc) {
    int time, start, end, highest;
    struct process *copy, *tmpsrc, *tmp, *beforehighest;
	
	printf("STARTING:\tPriority Schedule Algorithm\n");
	//("Total Sort Time: %lf sec.\n\n",outputTime);
	//printf("Total Sort Time: %lf sec.\n\n", GetTime()); 
    /* Duplicate process list */
    tmpsrc = proc;
    copy = tmp = NULL;
    while (tmpsrc != NULL) {
    if (copy == NULL) {
    copy = init_process(tmpsrc->pid, tmpsrc->burst, tmpsrc->priority);
    tmp = copy;
    } else {
    tmp->next = init_process(tmpsrc->pid, tmpsrc->burst, tmpsrc->priority);
    tmp = tmp->next;
    };
    tmpsrc = tmpsrc->next;
    };
     
    /* Main routine */
    time = 0;
    while (copy != NULL) {
    /* Find the next job */
    beforehighest = NULL;
    highest = copy->priority;
    tmp = copy->next;
    tmpsrc = copy;
    while (tmp != NULL) {
    if (tmp->priority < highest) {
    highest = tmp->priority;
    beforehighest = tmpsrc;
    };
    tmpsrc = tmp;
    tmp = tmp->next;
    };
     
    /* Process job and remove from copy of process list */
    if (beforehighest == NULL) {
    /* Handle first job is highest priority case */
    start = time;
    time += copy->burst;
    end = time;
    printf("PID: %d\tPriority: %d\tWait Time: %d\tTurnaround Time: %d\n", copy->pid, time, start, end);
    tmpsrc = copy->next;
    free(copy);
    copy = tmpsrc;
    } else {
    /* Handle first job is not highest priority case */
    tmp = beforehighest->next;
    start = time;
    time += tmp->burst;
    end = start - end;
    printf("PID: %d\tPriority: %d\tWait Time: %d\tTurnaround Time: %d\n", tmp->pid, time, start, end);
    beforehighest->next = tmp->next;
    free(tmp);
    };
    };
	//GetTime(time);
    printf("Average Algorithm Time:\b %lf Milla-seconds.\n", ReturnTime(time));

    printf("ENDING:\tPriority Schedule Algorithm\n\n");
    };

	void GetTime(double totalTimes){	
		struct timeval start1, end1;
		totalTimes = totalTimes / 48;
		double outputTime;
		outputTime = (((end1.tv_sec * 1000000 + end1.tv_usec)
			- (start1.tv_sec * 1000000 + start1.tv_usec))/totalTimes) /( 1000000.0);
		printf("Average Algorithm Time:\b %lf Milla-seconds.\n", outputTime);
	}
      
	double ReturnTime(double totalTimes){
   	struct timeval start1, end1;
        totalTimes = totalTimes / 48;
    	double outputTime = (((end1.tv_sec * 1000000 + end1.tv_usec)
                        - (start1.tv_sec * 1000000 + start1.tv_usec))/totalTimes) /( 1000000.0);
             return outputTime;
    }

     
    /* Round-Robin scheduling simulation */
    void roundRobinSchedule (struct process *proc, int quantum) {
    int jobsremain, passes;
    struct process *copy, *tmpsrc, *tmp, *slot;
	double division;
    printf("STARTING:\tRound Robin Schedule Algorithm \t (Quantum Time Setting: %d)\n", quantum);
    /* Duplicate process list */
    tmpsrc = proc;
    copy = tmp = NULL;
    while (tmpsrc != NULL) {
    if (copy == NULL) {
    copy = init_process(tmpsrc->pid, tmpsrc->burst, tmpsrc->priority);
    tmp = copy;
    } else {
    tmp->next = init_process(tmpsrc->pid, tmpsrc->burst, tmpsrc->priority);
    tmp = tmp->next;
    };
    tmpsrc = tmpsrc->next;
    };
     
    /* Main routine */
    jobsremain = 1;
    slot = NULL;
    while (jobsremain) {
    jobsremain = 0;
     
    /* Pick next working slot */
    if (slot == NULL) {
    slot = copy;
    jobsremain = 1;
    } else {
    passes = 0;
    do {
    if (slot->next == NULL) {
    passes++;
    slot = copy;
    } else {
    slot = slot->next;
    };
    } while (passes <= 2 && slot->burst == slot->working);
    if (passes <= 2) {
    jobsremain = 1;
    };
    };
     
    /* Perform a cycle */
    tmp = copy;
    while (tmp != NULL) {
    if (tmp->burst > tmp->working) {
    if (tmp == slot) {
    tmp->working += quantum;
    } else {
    tmp->waiting += quantum;
    };
    };
    tmp = tmp->next;
    };
    };
     
    /* Display statistics and clean up copy */
    tmp = copy;
    while (tmp != NULL) {
    printf("PID: %d\tQueue Timer: %d\t Wait Time: %d\tTurnaround Time: %d\n", tmp->pid, tmp->working, tmp->waiting, tmp->working + tmp->waiting);
	division += tmp->working + tmp->waiting;
    tmpsrc = tmp;
    tmp = tmp->next;
    free(tmpsrc);
    };
	//GetTime(division);
    printf("Average Algorithm Time:\b %lf Milla-seconds.\n", ReturnTime(division));
    printf("ENDING:\tRound Robin Schedule Algorithm\n\n");
    };
   
