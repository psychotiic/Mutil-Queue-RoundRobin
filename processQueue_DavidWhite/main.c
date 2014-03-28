
//Author: David White
//Date:3/27/14
//Program: Process Queue Scheduler
//About:  
/* This program uses a single queue to run 48 concurrent processes at the same time.
The program then does a time calculation to see how long each algorithm takes.  The time and 
processes are output to show what has happened.Some of the information I used in the 
code came from the stackoverflow, I read a lot about the differnt types and found lots of 
examples all from stackoverflow. 

ERROR>> When running this on OSX the average time wont compute.  It does just fine on unbuntu 12.04 or any version of linux
OSX is not returning anything in the time slot it just shows 0.00000 milla-secs.  

EXAMPLE RUN OF OUTPUT

david@ubuntu:~$ cd processQueue_DavidWhite/
david@ubuntu:~/processQueue_DavidWhite$ make
gcc -o Schedule main.c processQueue.c -std=c99
./david@ubuntu:~/processQueue_DavidWhite$ ./Schedule 
STARTING:	List of Current Running Processes
PID: 1		Priority: 3		Burst Time: 10
PID: 2		Priority: 1		Burst Time: 1
PID: 3		Priority: 13	Burst Time: 2
PID: 4		Priority: 12	Burst Time: 4
PID: 5		Priority: 14	Burst Time: 1
PID: 6		Priority: 5		Burst Time: 4
PID: 7		Priority: 4		Burst Time: 3
PID: 8		Priority: 7		Burst Time: 3
PID: 9		Priority: 5		Burst Time: 3
PID: 10		Priority: 15	Burst Time: 4
PID: 11		Priority: 10	Burst Time: 3
PID: 12		Priority: 2		Burst Time: 3
PID: 13		Priority: 0		Burst Time: 1
PID: 14		Priority: 2		Burst Time: 4
PID: 15		Priority: 2		Burst Time: 2
PID: 16		Priority: 2		Burst Time: 1
PID: 17		Priority: 15	Burst Time: 1
PID: 18		Priority: 8		Burst Time: 4
PID: 19		Priority: 9		Burst Time: 2
PID: 20		Priority: 10	Burst Time: 3
PID: 21		Priority: 7		Burst Time: 4
PID: 22		Priority: 4		Burst Time: 4
PID: 23		Priority: 8		Burst Time: 4
PID: 24		Priority: 6		Burst Time: 4
PID: 25		Priority: 4		Burst Time: 2
PID: 26		Priority: 12	Burst Time: 4
PID: 27		Priority: 1		Burst Time: 4
PID: 28		Priority: 8		Burst Time: 1
PID: 29		Priority: 3		Burst Time: 3
PID: 30		Priority: 14	Burst Time: 2
PID: 31		Priority: 1		Burst Time: 1
PID: 32		Priority: 7		Burst Time: 1
PID: 33		Priority: 3		Burst Time: 4
PID: 34		Priority: 14	Burst Time: 4
PID: 35		Priority: 4		Burst Time: 3
PID: 36		Priority: 6		Burst Time: 4
PID: 37		Priority: 8		Burst Time: 3
PID: 38		Priority: 8		Burst Time: 1
PID: 39		Priority: 7		Burst Time: 4
PID: 40		Priority: 14	Burst Time: 3
PID: 41		Priority: 4		Burst Time: 3
PID: 42		Priority: 10	Burst Time: 2
PID: 43		Priority: 11	Burst Time: 1
PID: 44		Priority: 7		Burst Time: 4
PID: 45		Priority: 13	Burst Time: 2
PID: 46		Priority: 3		Burst Time: 4
PID: 48		Priority: 2		Burst Time: 5
ENDING:	List of Current Running Processes

STARTING:	Priority Schedule Algorithm
PID: 13	Priority: 1	Wait Time: 0	Turnaround Time: -48
PID: 2	Priority: 2	Wait Time: 1	Turnaround Time: 49
PID: 27	Priority: 6	Wait Time: 2	Turnaround Time: -47
PID: 31	Priority: 7	Wait Time: 6	Turnaround Time: 53
PID: 12	Priority: 10	Wait Time: 7	Turnaround Time: -46
PID: 14	Priority: 14	Wait Time: 10	Turnaround Time: 56
PID: 15	Priority: 16	Wait Time: 14	Turnaround Time: -42
PID: 16	Priority: 17	Wait Time: 16	Turnaround Time: 58
PID: 48	Priority: 22	Wait Time: 17	Turnaround Time: -41
PID: 1	Priority: 32	Wait Time: 22	Turnaround Time: 32
PID: 29	Priority: 35	Wait Time: 32	Turnaround Time: 0
PID: 33	Priority: 39	Wait Time: 35	Turnaround Time: 35
PID: 46	Priority: 43	Wait Time: 39	Turnaround Time: 4
PID: 7	Priority: 46	Wait Time: 43	Turnaround Time: 39
PID: 22	Priority: 50	Wait Time: 46	Turnaround Time: 7
PID: 25	Priority: 52	Wait Time: 50	Turnaround Time: 43
PID: 35	Priority: 55	Wait Time: 52	Turnaround Time: 9
PID: 41	Priority: 58	Wait Time: 55	Turnaround Time: 46
PID: 6	Priority: 62	Wait Time: 58	Turnaround Time: 12
PID: 9	Priority: 65	Wait Time: 62	Turnaround Time: 50
PID: 24	Priority: 69	Wait Time: 65	Turnaround Time: 15
PID: 36	Priority: 73	Wait Time: 69	Turnaround Time: 54
PID: 8	Priority: 76	Wait Time: 73	Turnaround Time: 19
PID: 21	Priority: 80	Wait Time: 76	Turnaround Time: 57
PID: 32	Priority: 81	Wait Time: 80	Turnaround Time: 23
PID: 39	Priority: 85	Wait Time: 81	Turnaround Time: 58
PID: 44	Priority: 89	Wait Time: 85	Turnaround Time: 27
PID: 18	Priority: 93	Wait Time: 89	Turnaround Time: 62
PID: 23	Priority: 97	Wait Time: 93	Turnaround Time: 31
PID: 28	Priority: 98	Wait Time: 97	Turnaround Time: 66
PID: 37	Priority: 101	Wait Time: 98	Turnaround Time: 32
PID: 38	Priority: 102	Wait Time: 101	Turnaround Time: 69
PID: 19	Priority: 104	Wait Time: 102	Turnaround Time: 33
PID: 11	Priority: 107	Wait Time: 104	Turnaround Time: 71
PID: 20	Priority: 110	Wait Time: 107	Turnaround Time: 36
PID: 42	Priority: 112	Wait Time: 110	Turnaround Time: 74
PID: 43	Priority: 113	Wait Time: 112	Turnaround Time: 38
PID: 4	Priority: 117	Wait Time: 113	Turnaround Time: 75
PID: 26	Priority: 121	Wait Time: 117	Turnaround Time: 42
PID: 3	Priority: 123	Wait Time: 121	Turnaround Time: 123
PID: 45	Priority: 125	Wait Time: 123	Turnaround Time: 0
PID: 5	Priority: 126	Wait Time: 125	Turnaround Time: 126
PID: 30	Priority: 128	Wait Time: 126	Turnaround Time: 0
PID: 34	Priority: 132	Wait Time: 128	Turnaround Time: 128
PID: 40	Priority: 135	Wait Time: 132	Turnaround Time: 4
PID: 10	Priority: 139	Wait Time: 135	Turnaround Time: 139
PID: 17	Priority: 140	Wait Time: 139	Turnaround Time: 140
Average Algorithm Time 223.964409 Milla-seconds.
ENDING:	Priority Schedule Algorithm

STARTING:	Round Robin Schedule Algorithm 	 (Quantum Time Setting: 1)
PID: 1	Queue Timer: 10	 Wait Time: 130	Turnaround Time: 140
PID: 2	Queue Timer: 1	 Wait Time: 1	Turnaround Time: 2
PID: 3	Queue Timer: 2	 Wait Time: 47	Turnaround Time: 49
PID: 4	Queue Timer: 4	 Wait Time: 112	Turnaround Time: 116
PID: 5	Queue Timer: 1	 Wait Time: 4	Turnaround Time: 5
PID: 6	Queue Timer: 4	 Wait Time: 113	Turnaround Time: 117
PID: 7	Queue Timer: 3	 Wait Time: 85	Turnaround Time: 88
PID: 8	Queue Timer: 3	 Wait Time: 86	Turnaround Time: 89
PID: 9	Queue Timer: 3	 Wait Time: 87	Turnaround Time: 90
PID: 10	Queue Timer: 4	 Wait Time: 114	Turnaround Time: 118
PID: 11	Queue Timer: 3	 Wait Time: 89	Turnaround Time: 92
PID: 12	Queue Timer: 3	 Wait Time: 90	Turnaround Time: 93
PID: 13	Queue Timer: 1	 Wait Time: 12	Turnaround Time: 13
PID: 14	Queue Timer: 4	 Wait Time: 115	Turnaround Time: 119
PID: 15	Queue Timer: 2	 Wait Time: 57	Turnaround Time: 59
PID: 16	Queue Timer: 1	 Wait Time: 15	Turnaround Time: 16
PID: 17	Queue Timer: 1	 Wait Time: 16	Turnaround Time: 17
PID: 18	Queue Timer: 4	 Wait Time: 116	Turnaround Time: 120
PID: 19	Queue Timer: 2	 Wait Time: 59	Turnaround Time: 61
PID: 20	Queue Timer: 3	 Wait Time: 93	Turnaround Time: 96
PID: 21	Queue Timer: 4	 Wait Time: 117	Turnaround Time: 121
PID: 22	Queue Timer: 4	 Wait Time: 118	Turnaround Time: 122
PID: 23	Queue Timer: 4	 Wait Time: 119	Turnaround Time: 123
PID: 24	Queue Timer: 4	 Wait Time: 120	Turnaround Time: 124
PID: 25	Queue Timer: 2	 Wait Time: 65	Turnaround Time: 67
PID: 26	Queue Timer: 4	 Wait Time: 121	Turnaround Time: 125
PID: 27	Queue Timer: 4	 Wait Time: 122	Turnaround Time: 126
PID: 28	Queue Timer: 1	 Wait Time: 27	Turnaround Time: 28
PID: 29	Queue Timer: 3	 Wait Time: 100	Turnaround Time: 103
PID: 30	Queue Timer: 2	 Wait Time: 69	Turnaround Time: 71
PID: 31	Queue Timer: 1	 Wait Time: 30	Turnaround Time: 31
PID: 32	Queue Timer: 1	 Wait Time: 31	Turnaround Time: 32
PID: 33	Queue Timer: 4	 Wait Time: 123	Turnaround Time: 127
PID: 34	Queue Timer: 4	 Wait Time: 124	Turnaround Time: 128
PID: 35	Queue Timer: 3	 Wait Time: 103	Turnaround Time: 106
PID: 36	Queue Timer: 4	 Wait Time: 125	Turnaround Time: 129
PID: 37	Queue Timer: 3	 Wait Time: 105	Turnaround Time: 108
PID: 38	Queue Timer: 1	 Wait Time: 37	Turnaround Time: 38
PID: 39	Queue Timer: 4	 Wait Time: 126	Turnaround Time: 130
PID: 40	Queue Timer: 3	 Wait Time: 107	Turnaround Time: 110
PID: 41	Queue Timer: 3	 Wait Time: 108	Turnaround Time: 111
PID: 42	Queue Timer: 2	 Wait Time: 78	Turnaround Time: 80
PID: 43	Queue Timer: 1	 Wait Time: 42	Turnaround Time: 43
PID: 44	Queue Timer: 4	 Wait Time: 127	Turnaround Time: 131
PID: 45	Queue Timer: 2	 Wait Time: 80	Turnaround Time: 82
PID: 46	Queue Timer: 4	 Wait Time: 128	Turnaround Time: 132
PID: 48	Queue Timer: 5	 Wait Time: 130	Turnaround Time: 135
Average Algorithm Time 7.347349 Milla-seconds.
ENDING:	Round Robin Schedule Algorithm

david@ubuntu:~/processQueue_DavidWhite$ 
*/
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include "processQueue.h"
int main (void) {
    struct process *plist, *ptmp;
    plist = init_process(1, 10, 3);
    plist->next = init_process(2, 1, 1); ptmp = plist->next; // pid, burst time, priotrity
    for(int i=3;i < 47; i++){
	 ptmp->next = init_process(i, R(1,5),R(0,16)); 
         ptmp = ptmp->next;
    }
    ptmp->next = init_process(48, 5, 2); // ends the data
    listprocs(plist);
    priority(plist);
    roundRobinSchedule(plist, 1); // process list and quatium timer
    while (plist != NULL) {
    	ptmp = plist;
    	plist = plist->next;
    	free(ptmp);
    };
    return(0);
  };
 

  
