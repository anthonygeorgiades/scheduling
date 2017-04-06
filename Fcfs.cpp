#include "Task.h"
#include <vector>
#include <queue>         
#include <string>
#include <stdio.h>
#include <deque>
#include <stdlib.h> 
#include <algorithm> 


using namespace std;

/*
-Fcfs.cpp: the empty FCFS implementation
-a task arrives
-a task begins execution
-a task completes execution
-all tasks are completed
*/


//To sort by arrival time
bool my_sort (const Task& lhs, const Task& rhs) {
	return lhs.arrival < rhs.arrival;
}


/*
 * Implement this function using the FCFS algorithm in Part 1.
 * Note that the second parameter is unused. Literally. You should not use it.
 */ 
void schedule(vector<Task> tasks, int unused) {


	int size = tasks.size();	//store size of tasks 
	sort(tasks.begin(), tasks.end(), my_sort);	//sort tasks calling my_sort above 

	queue<Task> my_queue_1;	//only using one queue now

	int ending_time[size];	//store ending time, each index corresponds to each task in order
	int waiting_time[size];	//store waiting time, each index corresponds to each task in order

	/*
	Queue up queue 1 by pushing each task in tasks 
	*/
	for(int i = 0; i<size; i++) {
		my_queue_1.push(tasks[i]);
	}

	/*
	Calculate the ending time for each task and place in the array
	*/
	for(int i = 0; i<size; i++) {
		if(i == 0) {
			ending_time[i] = tasks[i].remaining;
		} else {
			ending_time[i] = ending_time[i-1] + tasks[i].time;
		}
	}

	/*
	Calculate the waiting time for each task and place in the array
	*/
	for(int i = 0; i<size; i++) {
		if(i == 0) {
			waiting_time[i] = 0
			;
		} else {
			waiting_time[i] = ending_time[i-1] - tasks[i].arrival;
		}
	}

	/*
	Declare variables for while loop  
	*/
	int current_time = 0;	//declare current time as 0 
	Task current_task;		//declare new task as current task
	int i = 0;				//indexing through each array
	int j =1;				//indexing, but not including first task 
	int count = size;		//set count to size of number of tasks

	while(!my_queue_1.empty()) {	//while myqueue is not empty we perform the following:

		/*
		Set current_task to front of queue
		Then, check if current task arrival is equal to current time 
		If so, print adding task of current task
		If i is 0 (first task) and arrival of next task is not 0, then run current task 
		(otherwise we would add other task first before running first task)
		*/
		current_task = my_queue_1.front();
		if(current_task.arrival == current_time) { 
			cout << current_task.arrival << ": Adding task " << current_task.name <<endl;
			if(i == 0 && tasks[i+1].arrival != 0)  {	
				cout << current_task.arrival << ": Running task " << current_task.name <<endl;
			}
		}

		/*
		If arrival of task is equal to current time (for tasks j=1 to size, so not including first task)
		Then we print adding task of this task  
		Then increment j (already added this task)
		*/
		if(tasks[j].arrival == current_time) {
			cout << tasks[j].arrival << ": Adding task " << tasks[j].name <<endl;
			j++;
		}	
 
 		/*
		If current time equals ending time of i, then print finished task 
		We are using our helper array (ending_time)
		Then pop this task of the front of the queue
		Then if i < size -1, we will run the next task j (which starts at ending time j-1)
		**At this point, we are running the task i+1, which starts at the ending_time i
		While this is a "hack", Professor Murphy noted it was ok for this function 
		Although it is not transferable to roundrobin and priority
 		*/
		if(current_time == ending_time[i]) {	
			cout << ending_time[i] << ": Finished task " << current_task.name << endl;

			tasks[i].remaining = tasks[i].time - tasks[i].remaining;	//updated time remaining of this task
     		my_queue_1.pop();	//

     		if(i<size-1) {
     			cout << ending_time[i] << ": Running task " << tasks[i+1].name << endl;
     		}

			i++;
		}

		current_time++;

	}
	

	//Once outside of loop, we can print all tasks finished
	cout<< (current_time-1) << ": All tasks finished" << endl;

	//Loop through "waiting" time array and add each waiting time to a total
	double total = 0;
	for(int i =0; i<size; i++) {
		total = total + waiting_time[i];
	}

	//Calculate the average, which is total over size
	double average = total / size;

	//Print the average waiting time. Done.
	cout<< "The average waiting time for tasks is: " << average << "." << endl;

}
	



