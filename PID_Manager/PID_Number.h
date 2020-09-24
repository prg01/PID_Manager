/*
 * PID_Number.h
 */

#ifndef PID_NUMBER_H_
#define PID_NUMBER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "bitmap_ops.h"

#define MIN_PID 300
#define MAX_PID 5000

#define MIN_SLP 1
#define MAX_SLP 7

pthread_mutex_t lock;
int *PID;
pthread_t tid[100];

int allocate_map();

int allocate_pid();

void release_pid(int pid);

void *allocatePidInThread(void *vargp);


#endif /* PID_NUMBER_H_ */
