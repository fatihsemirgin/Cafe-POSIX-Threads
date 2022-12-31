#include <pthread.h> //to use pthread functions 
#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<stdbool.h>
#include <semaphore.h>
#define CUSTOMER_NUMBER 25
#define REGISTER_NUMBER 5
#define CUSTOMER_ARRIVAL_TIME_MIN 1
#define CUSTOMER_ARRIVAL_TIME_MAX 3
#define COFFEE_TIME_MIN 2
#define COFFEE_TIME_MAX 5
#define TRUE 1
#define FALSE 0
void *Customer_func(void *t_id);		//This function can accept a pointer as an argument
pthread_mutex_t mutex[REGISTER_NUMBER];	// MUTEX ARRAY (Mutexes for registers)
int registers[REGISTER_NUMBER];			// MUTEX ARRAY (For Free Registers)
int main(int argc, char *argv[]) {		// MAIN
	// Initialize MUTEX ARRAYS
	int k = 0;	// For loop variable
	for(k = 0; k < REGISTER_NUMBER; k++) {	// Loop for Initialize mutexes of registers 
		pthread_mutex_init(&mutex[k], 0);	// Init function for mutex
	}
	for(k = 0; k < REGISTER_NUMBER; k++) {	// Loop for registers array that including register_ids.
		registers[k] = k;					// 
	}
	pthread_t threads[CUSTOMER_NUMBER]; 	// to define a thread
	int i;									// Variable for loop
	int tcr;								// return value of pthread_create function
	for (i = 0; i < CUSTOMER_NUMBER; i++) {	// Loop for creating customer threads
		srand(time(0));						// reset for rand function
		int number = (rand() % (CUSTOMER_ARRIVAL_TIME_MAX - CUSTOMER_ARRIVAL_TIME_MIN + 1)) + CUSTOMER_ARRIVAL_TIME_MIN;	// generate random arrival_time
		sleep(number);		// waiting time for creation
		printf("CUSTOMER <%d> IS CREATED AFTER <%d> SECONDS.\n", (i),number);	// For output
		tcr = pthread_create(&threads[i], NULL, Customer_func,(void*)i);				// Create function for customer threads (attributes are null)
		if (tcr != 0)															// If the creation is not successful
			printf("Thread creation error\n");									// Creation error.
	}
	for (i= 0; i < CUSTOMER_NUMBER; i++) {										// Loop for thread join
		pthread_join(*(threads + i), NULL);										// for a thread to terminate, detaches the thread, then returns the threads exit status. 
	}																			// If the status parameter is NULL, the threads exit status is not returned.
}
bool check_registers() {		// If a customer is waiting but any register is empty then that customer goes to that register.
	bool check = FALSE;			// Bool variable for if there is any register that empty.
	for(int k = 0; k < REGISTER_NUMBER; k++) {	// Loop for traversel registers array.
		if(registers[k] != -1) {	// checking register empty or not
			check = TRUE;			// If any register is empty then set the TRUE
			break;					// break of for	
		}
	}
	return check;	// return of function
}
void *Customer_func(void *param) {				// Function of customer thread
	int tid;									// id of customer thread
	tid = (int)param;							// casting to integer
	srand(time(0));								// reset for rand function.
	int register_no = rand() % REGISTER_NUMBER;	// generate register_id for any customer goes to random register.
	bool check = check_registers();				// get return value of check_registers function
	if(check) {									// if any register is empty
		while(TRUE) {										// while for a free register
			if(registers[register_no] == register_no) {		// For catch the random register in register array
				registers[register_no] = -1;				// For set the register filled. 
				break;										// break for while
			} else {
				register_no = rand() % REGISTER_NUMBER;		// if random register is filled then generate new register_no.
			}
		}
	}
	pthread_mutex_lock(&mutex[register_no]);									// Mutex lock for selected register.
	printf("CUSTOMER <%d> GOES TO REGISTER <%d>.\n",tid,register_no);			// For output
	int number = (rand() % (COFFEE_TIME_MAX - COFFEE_TIME_MIN + 1)) + COFFEE_TIME_MIN;		//	Generate random coffe_time
	sleep(number);																			// Waiting time for coffe_time (service_time)
	printf("CUSTOMER <%d> FINISHED BUYING FROM REGISTER <%d> AFTER <%d> SECONDS.\n",tid,register_no,number);	// For output
	pthread_mutex_unlock(&mutex[register_no]);							// Mutex unlock : Free the register
	registers[register_no]=register_no;									// For add the register into free registers array
	pthread_exit(NULL);													// Terminate the customer thread.
}
