#include <assert.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>
#include <x86intrin.h>



void busy_wait(struct timespec t){
	struct tms buf1, buf2;
    	
	clock_t then = times(&buf1);
	while( (times(&buf2)-then)/sysconf(_SC_CLK_TCK) < t.tv_sec){
        
	}
}



int main(){
	struct timespec t1 = {1,0};
	busy_wait(t1);

	return 0;	
}
