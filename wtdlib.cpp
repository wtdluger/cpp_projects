#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <chrono>
#include <thread>
#include "wtdlib.h"
using namespace std;

/* prints a vector of integers */
void printVector(vector<int>& arr) {
    for (int element : arr) {
        std::cout << element << ", ";
    }        
    cout << endl;
}

/* prints a list of integers */
void printList(list<int>& arr) {
    for (int element : arr) {
        cout << element << ", ";
    }        
    cout << endl;
}

/* 
    Function takes input in milliseconds 
    and pauses the program for that amount of time. 
    Utilizes the chrono and thread headers
*/
void timer(int duration_ms) {
    chrono::milliseconds duration_time(duration_ms);
    thread t([&]() {
        this_thread::sleep_for(duration_time);
    });
    t.join();
}

/*
    linux command to compile linked files
    g++ wtdlib.cpp main.cpp -o program_name
*/