#include <iostream>
#include <queue>
#include <array>
#include "Events.hpp"

int main(int argc, const char* argv[]) {
    if (argc < 3) {
        std::cout << "Not enough args...\n";
        exit(1);
    }
    const int hours_of_operation = 12;
    const int total_minutes = hours_of_operation * 60;
    const int total_seconds = total_minutes * 60;
    const int totalCustomers = std::atof(argv[1]) * total_minutes;
    const int maxServiceTimeInSeconds = std::atof(argv[2]) * 60;
    const long seed = std::atol(argv[3]);
    std::srand(seed);

    std::priority_queue<Event> events;
    std::cout << "total customers is " << totalCustomers << "\n";
    std::cout << "max service time in seconds is " << maxServiceTimeInSeconds << "\n";

    // generate customers and events
    for (int i = 0; i < totalCustomers; i++) {
        int arrivalTime = rand() % total_seconds;
        int secondsToService = rand() % maxServiceTimeInSeconds;
        Customer c = Customer(secondsToService, arrivalTime);
        events.emplace(Event(arrivalTime, c));
    }

    Bank bank = Bank();
    Store store = Store();

    bank.simulateWaitTimes(events);
    store.simulateWaitTimes(events);

//    std::cout << "total store wait times: " << store.storeWaitTimes.size() << "\n";
//    std::cout << "total bank wait times: " << bank.bankWaitTimes.size() << "\n";
    printStats(bank.bankWaitTimes, "Bank wait times (in minutes):");
    printStats(store.storeWaitTimes, "Store wait times (in minutes):");

//    for (int i = 0; i < bank.bankWaitTimes.size(); i++) {
//        std::cout << "bank at " << i << " took " << bank.bankWaitTimes[i] << "\n";
//        std::cout << "store at " << i << " took " << store.storeWaitTimes[i] << "\n\n";
//    }

//    std::cout << "THE END!" << std::endl;
    return 0;
}
