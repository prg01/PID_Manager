/*
 * PID_Number.c
 */
#ifndef PID_NUMBER_C_
#define PID_NUMBER_C_


#include "PID_Number.h"


int allocate_map()
{
	int arr_size;
	if(((MAX_PID-MIN_PID+1)%32)==0)
		/*since the remainder is zero means the size of the array will perfectly contain the range
		 * defined by the min and max PID
		 */
	{
		arr_size=(MAX_PID-MIN_PID+1)/32;
	}
	else
	{
		arr_size=((MAX_PID-MIN_PID+1)/32)+1;
	}
	PID = (int*) calloc(arr_size, sizeof (int)); //returns the pointer to the array
	if(PID==NULL)
	{
		return -1;
	}
	return 1;
}

int allocate_pid()
{
	int i;
	for(i=0; i<(MAX_PID-MIN_PID+1); i++)
	{
		if(!CheckBit(PID,i))
		{
			SetBit(PID,i);
			return (i+MIN_PID);
		}
	}
	if (i==(MAX_PID-MIN_PID+1))
	{
		return -1;
	}
	return 0;
}

void release_pid(int pid)
{
    printf("Released PID %d\n",pid);
	ClearBit(PID,(pid-MIN_PID));
}

void *allocatePidInThread(void *vargp)
{
    pthread_mutex_lock(&lock);
    int j;
	j = allocate_pid();
	printf("Allocated PID: %d \n", j);
	pthread_mutex_unlock(&lock);
	sleep((rand()%(MAX_SLP-MIN_SLP+1))+MIN_SLP);
	release_pid(j);
	return NULL;
}
#endif /* PID_NUMBER_C_ */
