# Event Based Queue Simulator

## About This Project:

This is a project I did as part of the Master's of Software Development program at the University of Utah in Spring of 2019. It is an event based simulation comparing two different types of queues: the bank queue (which only has one shared line to many tellers), and the grocery store queue (which has many lines to many checkers). This simulation uses "events," which represent things that happen in a store or at a bank, such as customer arrives, or teller finishes. Using these events and a priority queue (based on time of event), a full days worth of queueing can be simulated in a matter of nanoseconds. Which queue do you think is faster? 

## How To Run:
1. Clone this repository into a directory of your choice: 
```
git clone https://github.com/jhiggi44/Queue_Event_Simulator.git
```

2. cd into the repository. 

3. Build project into an executable via the command line by running:
```
clang++ -std=c++17 main.cpp Events.cpp -o runSim
```
4. Run the exectuable with three command line arguments that indicate the average number of customers that arrive per minute, the max service time for a customer (which represents that one customer who took the longest), and a seed for the pseudorandom generation of events. 
```
./runSim <numberOfCustomersPerMin> <maxCustomerServiceTime> <seedForRandomEventGeneration>
````
5. Examine the results and repeat  step 4 until you feel thoroughly enlightened. 
