#include <iostream>
using namespace std;

int main() {
    cout << "__cplusplus = " << __cplusplus << endl;
    if (__cplusplus == 202302L) {
        cout << "C++23 Standard" << endl;
    }
    else if (__cplusplus == 202002L) {
        cout << "C++20 Standard" << endl;
    }
    else if (__cplusplus == 201703L) {
        cout << "C++17 Standard" << endl;
    }
    else if (__cplusplus == 201402L) {
        cout << "C++14 Standard" << endl;
    }
    else if (__cplusplus == 201103L) {
        cout << "C++11 Standard" << endl;
    }
    else if (__cplusplus == 199711L) {
        cout << "C++98 Standard" << endl;
    }
    else {
        cout << "pre-standard C++" << endl;
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
        g++ 2025.0618_cpp_version.cpp -o cpp_version
    Force Compiling with C++20
        g++ g++ 2025.0618_cpp_version.cpp -o cpp_version_20 -std=c++20


    ===========
    Values for __cplusplus macro obtained from:
    https://en.cppreference.com/w/cpp/preprocessor/replace#Predefined_macros

    Original code snippet obtained from:
    https://coderslegacy.com/c/check-cpp-compiler-version/    
*/