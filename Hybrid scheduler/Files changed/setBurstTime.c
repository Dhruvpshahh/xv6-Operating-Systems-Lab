#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if(argc < 2)
    {
		printf(2, "Usage: getProcInfo...\n");
		exit();
	}

    if(setBurstTime(atoi(argv[1]))<0)
    {
        printf(2, "Setting burst time failed\n");
		exit();
    }

    // printf(1,"Burst time set to %d\n",getBurstTime());
    exit();
}