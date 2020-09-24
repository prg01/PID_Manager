/*
 * PID_Manager_main.c
 */

#include "PID_Number.h"

int main()
{

	int i;
	allocate_map();
	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("\n mutex init has failed\n");
		return 1;
	}

	// Let us create 5 threads
	for (i = 0; i < 5; i++) {
		pthread_create(&tid[i], NULL,
            allocatePidInThread, (void *)&tid[i]);
	}

	for (i = 0; i < 5; i++) {
		pthread_join(tid[i], NULL);
	}

	pthread_mutex_destroy(&lock);
	return 0;
}
