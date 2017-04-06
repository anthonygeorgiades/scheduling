#include <iostream>
#include <vector>
#include <string>
#include "Task.h"

/*
 * Do not implement this function here.
 * Implement it in either Fcfs.cpp or RoundRobin.cpp
 * and then use the appropriate .cpp file when
 * linking the code and creating the executable.
 */
extern void schedule(std::vector<Task>, int);

/*
 * This is the test driver for Priority Round Robin.
 * Do not change this code!
 */
int main() {

  Task *t0 = new Task;
  t0->name = "sleepy";
  t0->arrival = 0;
  t0->time = 15;
  t0->remaining = 15;
  t0->priority = 1;

  Task *t1 = new Task;
  t1->name = "dopey";
  t1->arrival = 2;
  t1->time = 5;
  t1->remaining = 5;
  t1->priority = 9;

  Task *t2 = new Task;
  t2->name = "doc";
  t2->arrival = 0;
  t2->time = 6;
  t2->remaining = 6;
  t2->priority = 8;

  Task *t3 = new Task;
  t3->name = "grumpy";
  t3->arrival = 17;
  t3->time = 7;
  t3->remaining = 7;
  t3->priority = 5;

  Task *t4 = new Task;
  t4->name = "happy";
  t4->arrival = 8;
  t4->time = 3;
  t4->remaining = 3;
  t4->priority = 8;

  Task *t5 = new Task;
  t5->name = "bashful";
  t5->arrival = 16;
  t5->time = 9;
  t5->remaining = 9;
  t5->priority = 4;

  Task *t6 = new Task;
  t6->name = "sneezy";
  t6->arrival = 17;
  t6->time = 5;
  t6->remaining = 5;
  t6->priority = 4;

  std::vector<Task> tasks;

  tasks.push_back(*t0);
  tasks.push_back(*t1);
  tasks.push_back(*t2);
  tasks.push_back(*t3);
  tasks.push_back(*t4);
  tasks.push_back(*t5);
  tasks.push_back(*t6);

  int quantum = 4;

  schedule(tasks, quantum);

  delete t0;
  delete t1;
  delete t2;
  delete t3;
  delete t4;
  delete t5;
  delete t6;

  return 1;

}



