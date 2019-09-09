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
#include <stdint.h>

int main(){

	
/*
	// access latency
	//struct timespec buf;
	struct tms buf;
	for (int i = 0; i < 10*1000*1000;i++){
		//__rdtsc();
		//clock_gettime(CLOCK_MONOTONIC, &buf);
		clock_t then = times(&buf);
	}

*/


	int ns_max = 50;
	int histogram[ns_max];
	memset(histogram, 0, sizeof(int)*ns_max);
	for(int i = 0; i < 10*1000*1000; i++){
	/*
	uint64_t t1 = __rdtsc(); 
	uint64_t t2 = __rdtsc();
	int ns = (t2 - t1)/2.66;
	
	struct timespec buf1,buf2;
	clock_gettime(CLOCK_MONOTONIC, &buf1);
	clock_gettime(CLOCK_MONOTONIC, &buf2);
	uint64_t t1 = buf1.tv_nsec;
	uint64_t t2 = buf2.tv_nsec;
	int ns = (t2-t1);
	*/
	struct tms buf;
	clock_t t1 = times(&buf);
	clock_t t2 = times(&buf);
	int ns = 1e9*(t2-t1)/sysconf(_SC_CLK_TCK);

		if(ns >= 0 && ns < ns_max){
			histogram[ns]++;     
		} 
	} 
	for(int i = 0; i < ns_max; i++){
		printf("%d\n", histogram[i]);
	}

}
