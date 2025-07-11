#include <iostream>
using namespace std;

int main() {
    cout << "__cplusplus = " << __cplusplus << endl;
    switch (__cplusplus) {
        case 202302L:
            cout << "C++23 Standard" << endl;
            break;
        case 202002L:
            cout << "C++20 Standard" << endl;
            break;
        case 201703L:
            cout << "C++17 Standard" << endl;
            break;
        case 201402L:
            cout << "C++14 Standard" << endl;
            break;
        case 201103L:
            cout << "C++11 Standard" << endl;
            break;
        case 199711L:
            cout << "C++98 Standard" << endl;
            break;
        default:
            cout << "pre-standard C++" << endl;
            break;
    }
    
    return 0;
}
/*
    the predefined macro 
        __cplusplus 
    contains the version of C++ the compiler will use
        
    the equivalent linux command for this cpp file is
        echo '' | g++ -xc++ -E -dM - | grep __cplusplus
        
    the commonly cited linux command 
        gcc --version 
    provides the version of the gnu compiler being used

    Default Compiling command
        g++ cpp_version.cpp -o cpp_version
    Force Compiling with C++20
        g++ g++ cpp_version.cpp -o cpp_version_20 -std=c++20


    ===========
    Values for __cplusplus macro obtained from:
    https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros

    Original code snippet obtained from:
    https://coderslegacy.com/c/check-cpp-compiler-version/    
*/
