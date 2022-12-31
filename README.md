# Cafe-POSIX-Threads
* A simulation of a cafe using POSIX threads, 
mutexes and semaphores. <br>
* Cafe should only sell one product, a normal coffee to make it simpler. The program 
scenario is, consumers come to the cafe and tries to find an empty register to buy a coffee. 
Registers take the order, prepare it and give it to the customer and the customer leaves.

### Definitions
#### #define CUSTOMER_NUMBER 25
  * The definition above will be used for how many customers your program should work for. 
After this many customers are created and serviced, the program should terminate. This 
will also be used to identify customers by given them IDs from 0 to 24.<br>
#### #define CUSTOMER_ARRIVAL_TIME_MIN 1<br>
* The definition above will be used for how much time, at minimum, should pass between 
customers arriving.<br>
#define CUSTOMER_ARRIVAL_TIME_MAX 3<br>
* The definition above will be used for how much time, at maximum, should pass between 
customers arriving.<br>
#### #define REGISTER_NUMBER 5<br>
* The definition above will be used for how many registers your program should work for. 
This will also be used to identify registers by given them IDs from 0 to 4.<br>
#### #define COFFEE_TIME_MIN 2<br>
* The definition above will be used for minimum waiting time for ordering and receiving a 
coffee by customers. This represents that minimum waiting time should be 1 second.<br>
#### #define COFFEE_TIME_MAX 5<br>
* The definition above will be used for minimum waiting time for ordering and receiving a 
coffee by customers. This represents that maximum waiting time should be 5 seconds.<br>

### Algorithms
1- Customer arrives after a random number of seconds passed defined by 
CUSTOMER_ARRIVAL_TIME_MIN and CUSTOMER_ARRIVAL_TIME_MAX 
variables.<br>
2- Customer tries to find an open register and waits if there is none. When he/she finds an 
empty register, he/she gives his/her order and get his/her coffee. This process should take 
a random amount of time, defined by COFFEE_TIME_MIN and COFFEE_TIME_MAX variables.<br>
3- All of this process should be outputted in terminal (CLI) to keep the user informed.<br>

### OUTPUTS
* CUSTOMER <CUSTOMER_ID> IS CREATED AFTER <TIME> SECONDS.<br>
 This output should be given when you create a customer with given <CUSTOMER_ID> 
and after waiting a random time given in <TIME>.
* CUSTOMER <CUSTOMER_ID> GOES TO REGISTER <REGISTER_ID>.<br>
 This output should be given when a customers (with <CUSTOMER_ID>) finds an empty 
register (with <REGISTER_ID>) and starts the ordering process.
* CUSTOMER <CUSTOMER_ID> FINISHED BUYING FROM REGISTER <REGISTER_ID> 
AFTER <TIME> SECONDS.<br>
 This output should be given when a customers (with <CUSTOMER_ID>) finishes buying 
coffee from register (with <REGISTER_ID>) and prints out how much time did it took 
(with <TIME>), which was randomly selected.
