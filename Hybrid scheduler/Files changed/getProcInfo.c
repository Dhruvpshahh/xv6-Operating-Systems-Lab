#include "types.h"
#include "stat.h"
#include "user.h"
#include "processInfo.h"

int main(int argc, char *argv[])
{	
	if(argc < 2){
		printf(2, "Usage: getProcInfo...\n");
		exit();
	}

	for(int i=1; i<argc; i++)
	{
		struct processInfo* ptr;
		ptr = (struct processInfo*) malloc(sizeof(struct processInfo));
		
		if(getProcInfo(atoi(argv[i]), ptr) < 0)
		{
			// printf(2, "getProcInfo: %s failed\n", argv[i]);
			// break;
			printf(2,"Process pid=%d, doesnt exist in the process table\n",atoi(argv[i]));
		}
		else{
			printf(1, "Name: %s\n", ptr->name);
			printf(1, "PPID: %d\n", ptr->ppid);
			printf(1, "Psize: %d\n", ptr->psize);
			printf(1, "Context switches: %d\n", ptr->numberContextSwitches);
			printf(1, "State: %s\n", ptr->state);
			printf(1, "Killed: %d\n", ptr->killed);
			printf(1, "Burst Time: %d\n", ptr->burst_time);
		}
	}

	exit();
}
