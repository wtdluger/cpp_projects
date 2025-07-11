#ifndef WTDLIB_H
#define WTDLIB_H

#include <iostream>
#include<fstream>
#include<sstream>
#include <string>
#include <list>
#include <vector>
#include <chrono>
#include <thread>
using namespace std;

std::vector<std::vector<std::string>> readCSV(std::string file_loc);
void writeCSV(
    std::vector<std::vector<std::string>> csv_data, 
    std::string outputFileName
);
void printVector(vector <int>& arr);
void printList(list <int>& arr);
void timer(int duration_ms);

#endif