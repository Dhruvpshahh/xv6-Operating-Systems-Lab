#include "types.h"
#include "stat.h"
#include "user.h"

#define PGSIZE 4096
#define ITERATIONS 10
#define CHILDREN 20


void child_process(int i){
	char *ptr[ITERATIONS];

	for(int j=0;j<ITERATIONS;j++){
		// set all values
		ptr[j]=(char*)malloc(PGSIZE);
		for(int k=0;k<(PGSIZE);k++){
			ptr[j][k]=(i+j*k)%128;
		}

		int matched=0;
		// check all values
		for(int k=0;k<(PGSIZE);k++){
			if(ptr[j][k]==(i+j*k)%128){
				matched++;
			}
		}
		printf(1, "Process: %d\tIteration: %d\tMatched: %dB\tDifferent: %dB\n",i+1, j+1, matched, 4096-matched);
	}

}

int
main(int argc, char* argv[]){

	for(int i=0;i<CHILDREN;i++){
		if(!fork()){
			
			child_process(i);

			printf(1, "\n");
			exit();
		}
	}

	while(wait()!=-1);
	exit();

}