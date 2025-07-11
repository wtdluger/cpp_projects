#include <iostream>
#include<fstream>
#include<sstream>
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

/* read a csv file */
std::vector<std::vector<std::string>> readCSV(std::string file_loc)
{
    std::ifstream file(file_loc);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open the file.");
    }
    std::string line;
    std::vector<std::vector<std::string>> csv_data; // To store all data

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> row_data;

        while (std::getline(ss, field, ',')) {
            row_data.push_back(field);
        }
        csv_data.push_back(row_data);
    }
    // close the file when done reading to save resources
    file.close();
    return csv_data;
}

/* write to csv file */
void writeCSV(
    std::vector<std::vector<std::string>> csv_data, 
    std::string outputFileName
){
// If it exists, its content will be truncated (cleared) by default.
    std::ofstream outFile(outputFileName);

    // Check if the file was opened successfully
    if (outFile.is_open()) {
        for (const auto& row : csv_data) 
        {
            for (const auto& field : row) {
                outFile << field << "\t";
            }
        }

        // Close the file when done writing to release resources
        outFile.close();
        std::cout << "Data successfully written to example.txt" << std::endl;
    } else {
        // Handle the error if the file could not be opened
        std::cerr << "Error: Unable to open file." << std::endl;
    }
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