
//Author: David White
//Date:3/27/14
//Program: processQueue Scheduler
//About:  
/* This program uses a single queue to run 48 concurrent processes at the same time.
The program then does a time calculation to see how long each algorithm takes.  The time and 
processes are output to show what has happened.Some of the information I used in the 
code came from the stackoverflow, I read a lot about the differnt types and found lots of 
examples all from stackoverflow. */
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
	 ptmp->next = init_process(i, R(1,5),R(1,17)); 
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
 

  
