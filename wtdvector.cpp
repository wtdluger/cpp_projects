#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "wtdvector.hpp"
using std::cin;
using std::cout;
using std::endl;


// Print Vector: 3 functions
void printVector(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ", ";
    }        
    cout << endl; 
}
void printVector(std::vector<double> &arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ", ";
    }        
    cout << endl; 
}
void printVector(std::vector<std::string> &arr)
{
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << ", ";
    }        
    cout << endl; 
}


// Add Vector 2 Functions
void addVector(std::vector<int> x, std::vector<int> y, std::vector<int> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        int j = x[i] + y[i];
        z.push_back(j);
    }
}
void addVector(std::vector<double> x, std::vector<double> y, std::vector<double> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        double j = x[i] + y[i];
        z.push_back(j);
    }
}

// Subtract Vector
void subtractVector(std::vector<int> x, std::vector<int> y, std::vector<int> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        int j = x[i] - y[i];
        z.push_back(j);
    }
}
void subtractVector(std::vector<double> x, std::vector<double> y, std::vector<double> &z)
{
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        double j = x[i] - y[i];
        z.push_back(j);
    }
}


// Dot Product: 2 functions
void dotProduct(std::vector<int> x, std::vector<int> y, int &z)
{
    z = 0;
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        int j = x[i] * y[i];
        z += j;
    }
}
void dotProduct(std::vector<double> x, std::vector<double> y, double &z)
{
    z = 0.0;
    int iter_end;
    if (x.size() <= y.size())
        iter_end = x.size();
    else
        iter_end = y.size();
    for (int i = 0; i < iter_end; ++i) {
        double j = x[i] * y[i];
        z += j;
    }
}

// Cross Product: 2 functions
void crossProduct(std::vector<int> x, std::vector<int> y, std::vector<int> &z)
{
    if (x.size() == 3 && y.size() == 3) {
        // z = {a2b3 - a3b2, -(a1b3-a3b1), a1b2-a2b1}
        z = {x[1]*y[2] - x[2]*y[1],  x[2]*y[0] - x[0]*y[2],  x[0]*y[1] - x[1]*y[0]};
    }
    else {
        z = {0, 0, 0};
        // std::vector<auto> z = {0*x[0], 0*x[1], 0*x[2]};
    }
}
void crossProduct(std::vector<double> x, std::vector<double> y, std::vector<double> &z)
{
    if (x.size() == 3 && y.size() == 3) {
        // z = {a2b3 - a3b2, -(a1b3-a3b1), a1b2-a2b1}
        z = {x[1]*y[2] - x[2]*y[1],  x[2]*y[0] - x[0]*y[2],  x[0]*y[1] - x[1]*y[0]};
    }
    else {
        z = {0.0, 0.0, 0.0};
        // std::vector<auto> z = {0*x[0], 0*x[1], 0*x[2]};
    }
}
