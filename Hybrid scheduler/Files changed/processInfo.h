struct processInfo
{
    int ppid;
    int psize;
    int numberContextSwitches;
    int burst_time;
    char name[16];
    char state[7];
    int killed; 
};
