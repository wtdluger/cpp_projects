#ifndef WTDVECTOR_H
#define WTDVECTOR_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
// #include <list>
using std::cin;
using std::cout;
using std::endl;

void printVector(vector<int>& arr);
void printVector(std::vector<double> &arr);
void printVector(std::vector<std::string> &arr);
void addVector(std::vector<int> x, std::vector<int> y, std::vector<int> &z);
void addVector(std::vector<double> x, std::vector<double> y, std::vector<double> &z);
void subtractVector(std::vector<int> x, std::vector<int> y, std::vector<int> &z);
void subtractVector(std::vector<double> x, std::vector<double> y, std::vector<double> &z);
void dotProduct(std::vector<int> x, std::vector<int> y, int &z);
void dotProduct(std::vector<double> x, std::vector<double> y, double &z);
void crossProduct(std::vector<int> x, std::vector<int> y, std::vector<int> &z);
void crossProduct(std::vector<double> x, std::vector<double> y, std::vector<double> &z);

#endif