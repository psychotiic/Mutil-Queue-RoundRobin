//Some of the information I used in the code came from the stackoverflow,
// I read a lot about the differnt types and found lots of examples all from
// stackoverflow.
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include "processQueue.h"

int main (void) {

// Initialize process list
    struct process *plist, *ptmp;
    plist = init_process(1, 10, 3);
    plist->next = init_process(2, 1, 1); ptmp = plist->next; // pid, burst time, priotrity
	for(int i=3;i < 47; i++){
	 ptmp->next = init_process(i, R(1,5),R(1,16)); ptmp = ptmp->next;
	}
    ptmp->next = init_process(48, 5, 2); // ends the data
     
    // Perform simulations
    listprocs(plist);
   // firstComeFirstServe(plist);
   // shortestJobFirst(plist);
    priority(plist);
    roundRobinSchedule(plist, 1);
     
    // Terminate cleanly 
    while (plist != NULL) {
    ptmp = plist;
    plist = plist->next;
    free(ptmp);
    };
    return(0);

printf("\ndont worry I have gotten to the end\n");
  };
 

  
