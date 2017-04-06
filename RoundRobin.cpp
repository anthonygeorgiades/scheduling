#include "Task.h"
#include <vector>
#include <queue>          // std::queue
#include <string>
#include <stdio.h>
#include <deque>
#include <stdlib.h> 
#include <algorithm> 


using namespace std;

//To sort by arrival time
bool my_sort (const Task& lhs, const Task& rhs) {
	return lhs.arrival < rhs.arrival;
}
/*
 * Implement this function using the Round Robin algorithm in Part 2.
 */
void schedule(std::vector<Task> tasks, int quantum) {

	int size = tasks.size();	//calculate size 
	sort(tasks.begin(), tasks.end(), my_sort);	//sort tasks, using my_sort above
	
	queue<Task> ready_queue;	//new queue, ready_queue
	int current_time = 0;		//keep track of current time
	Task current_task;			//declare new task, current task
	int i = 0;					//iterator i
	int quant = 0;				//set quant counter to keep trakc of quantum
	bool busy = false;			//set boolean flag busy to false 
	int completed_tasks = 0;	//counter to keep track of completed_tasks
	double waiting_time = 0;	//counter to keep track of waiting_time for ALL tasks

	/*
	While completed_tasks counter is less than size, we continue
	*/
	while(completed_tasks < size) {

		/*
		For int j, we loop through each task 
		If arrival time of task is same as current time
		Then we add the task (and push the task into queue)
		*/
		for (int j = 0; j < size; j++) {
			if(tasks[j].arrival == current_time) {
			cout << tasks[j].arrival << ": Adding task " << tasks[j].name <<endl;
			ready_queue.push(tasks[j]);

			}
		}

		/*
		If quant counter equals quantum and the current task has reamining time left
		Then we print the Time Slice for this task (at current time)
		And then we push current stack onto queue
		And set busy flag to false
		*/
		if(quant == quantum && current_task.remaining > 0) {
			cout << current_time << ": Time Slice Done for Task " << current_task.name <<endl;
			ready_queue.push(current_task);
			busy = false;
			// current_task = ready_queue.front();
		}

		/*
		If current_task remaining time is 0 AND busy flag is true
		Then the current task is finished
		We also calculate waiting time of current task and add it to the "waiting_time" counter 
		We are no longer busy, so busy flag is false, and completed tasks increments by 1
		*/
		if(current_task.remaining == 0 && busy == true) {	
			cout << current_time << ": Finished task " << current_task.name << endl;
			waiting_time = waiting_time + (current_time - current_task.arrival - current_task.time);
			busy = false;
			completed_tasks++;	
		}

		/*
		If the ready_queue is NOT empty and busy is false, well then
		The current task is going to be set to the ready queue (first object)
		And we print that we are now running the current task
		Note: we then need to pop the current task off the queue
		We set our busy flag to true, and reset our quant to 0 (since we were not busy, we know it should be 0)
		*/
		if(!ready_queue.empty() && busy == false) {
			current_task = ready_queue.front();	//return first object
			cout << current_time << ": Running task " << current_task.name <<endl;
			ready_queue.pop();					//pop it off 
			busy = true;
			quant = 0;
		}

		/*
		If current_task has time remaining and quant is less than quantum
		We will decrement the time remaining for current task (we are running)
		And increment the quant (we are busy) 
		*/
		if(current_task.remaining > 0 && quant < quantum ) {
			current_task.remaining --;
			quant ++;
		}

		/*
		If completed tasks equals to size, well then we have finished all tasks!
		Print current time
		*/
		if(completed_tasks == size) {
			cout<< (current_time) << ": All tasks finished" << endl;

		}

		current_time++;	//increment current_time (does not impact finished tasks statement above)

	}

	/*
	Calculate average waiting time which is just waiting_time over size
	*/
	double average = waiting_time / size;
	cout<< "The average waiting time for tasks is: " << average << "." << endl;

}


