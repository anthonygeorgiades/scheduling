CC = c++
Args = -Wall

all: fcfs roundrobin priorityrr

fcfs:
	$(CC) -o fcfs Driver.cpp Fcfs.cpp
	
roundrobin:
	$(CC) -o roundrobin Driver.cpp RoundRobin.cpp

priorityrr:
	$(CC) -o priorityrr PriorityDriver.cpp PriorityRR.cpp
	
clean:
	rm -rf fcfs roundrobin priorityrr *.o
