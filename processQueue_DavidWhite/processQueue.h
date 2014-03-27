#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "error.h"

 // Process Data Structure
    struct process {
    int pid; // Process ID 
    int burst; // CPU Burst Time
    int priority; // Priority
    int working; // Working time, for round-robin scheduling 
    int waiting; // Waiting time, for round-robin scheduling 
    struct process *next;
    };
     
    // Function Prototype Declarations
    struct process *init_process (int pid, int burst, int priority);
    void firstComeFirstServe (struct process *proc);
    void listprocs (struct process *proc);
    void priority (struct process *proc);
    void roundRobinSchedule (struct process *proc, int quantum);
    void shortestJobFirst (struct process *proc);
    double R(double min, double max);
#endif // MESSAGEQUEUE_H
