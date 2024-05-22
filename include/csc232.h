/**
* CSC232 - Data Structures
* Missouri State University, Fall 2023
*
* @file    csc232.h
* @author  Jim Daehn <jdaehn@missouristate.edu>
* @brief   Macros, libraries and definitions for use in csc232 assignments.
* @version 1.0.0
* @date    09/02/2023
*
* @copyright Copyright (c) 2023 James R. Daehn
*/
















#ifndef MSU_CSC232_H_
#define MSU_CSC232_H_
















#define FALSE 0
#define TRUE 1
















#define EXECUTE_PREAMBLE TRUE
#define SIMULATE_FUNCTION_IMPLEMENTED TRUE
















#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "loader.h"
#include "node.h"
/** Common iostream objects */
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
















/** Common iomanip objects */
using std::left;
using std::right;
using std::setprecision;
using std::setw;
















/**
* @brief Common namespace for CSC232 identifiers.
*/
















#include <iostream>
#include <queue>
#include <vector>




struct Event {
    int time;
    bool isArrival;




    Event(int t, bool arrival) : time(t), isArrival(arrival) {}
};




struct Customer {
    int arrivalTime;
    int transactionTime;
    int departureTime;
    int waitingTime;




    Customer(int arrival, int transaction)
            : arrivalTime(arrival), transactionTime(transaction), departureTime(0), waitingTime(0) {}
};




struct CompareEvents {
    bool operator()(const Event& e1, const Event& e2) const {
        return e1.time > e2.time;
    }
};




namespace csc232 {
    // ... (your existing code)




    void simulate(const std::string& fileName) {
        std::cout << "Simulation Begins\n";
        Node* arrivals_head = nullptr;
        Node* arrivals_tail = nullptr;




        Node* transtime_head = nullptr;
        Node* transtime_tail = nullptr;
        processFile("main_data.txt", arrivals_head, arrivals_tail, transtime_head, transtime_tail);




        std::priority_queue<Event, std::vector<Event>, CompareEvents> eventQueue;
        std::vector<Customer> customerLine;




        Node* currentArrival = arrivals_head;
        while (currentArrival) {
            eventQueue.push(Event(currentArrival->data, true));
            currentArrival = currentArrival->next;
        }




        int currentTime = 0;
        int totalPeopleProcessed = 0;
        int totalWaitingTime = 0;




        while (!eventQueue.empty() || !customerLine.empty()) {
            if (!eventQueue.empty() && (customerLine.empty() || eventQueue.top().time <= customerLine.front().departureTime)) {
                Event currentEvent = eventQueue.top();
                eventQueue.pop();




                currentTime = currentEvent.time;




                std::cout << "Processing an arrival event at time:" << std::setw(4) << std::fixed << currentTime<< std::setprecision(1) << "\n";




                totalPeopleProcessed++;




                Customer newCustomer(currentTime, transtime_head->data);
                transtime_head = transtime_head->next;
                if (!customerLine.empty()) {
                    newCustomer.waitingTime = customerLine.back().departureTime - currentTime;
                }




                newCustomer.departureTime = currentTime + newCustomer.transactionTime + newCustomer.waitingTime;




                totalWaitingTime += newCustomer.waitingTime;




                customerLine.push_back(newCustomer);
            } else {
                Customer currentCustomer = customerLine.front();
                customerLine.erase(customerLine.begin());




                currentTime = currentCustomer.departureTime;




                std::cout << "Processing a departure event at time:" << std::setw(3) << std::fixed << currentTime<< std::setprecision(1) << "\n";
            }
        }




        std::cout << "Simulation Ends\n\n";
        std::cout << "Final Statistics:\n";
        std::cout << "\tTotal number of people processed: " << totalPeopleProcessed << "\n";
        std::cout << "\tAverage amount of time spent waiting: " << static_cast<double>(totalWaitingTime) / totalPeopleProcessed << "\n";




    }
    // DO NOT Modify anything below this line
















    int Preamble(int argc, char *argv[]);
















    /**
     * @brief Generate a quasi-random UUID.
     * @return A string representation of a quasi-random UUID.
     */
    std::string GenerateUuid() {
        static std::random_device random_device;
        static std::mt19937 random_number_generator(random_device());
















        std::uniform_int_distribution<int> dist(0, 15);
















        const char *uuid_alphabet = "0123456789abcdef";
        const bool dash[] = {false, false, false, false, true, false, true, false,
                             true, false, true, false, false, false, false, false};
















        std::string uuid;
        for (bool dash_location: dash) {
            if (dash_location)
                uuid += "-";
            uuid += uuid_alphabet[dist(random_number_generator)];
            uuid += uuid_alphabet[dist(random_number_generator)];
        }
        return uuid;
    }
}
// namespace csc232
















#endif // MSU_CSC232_H_

