#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void cppCompiler();
void cppStandard();

int main()
{   
    cppCompiler();
    cppStandard();

    return 0;
}

void cppCompiler() {
    cout << "Compiler Information:" << endl;
    #if defined(__GNUC__) && !defined(__clang__)
        cout << "    GCC (GNU Compiler Collection)" << endl;
        
        cout << "    Version: " << __GNUC__ << ".";
        cout << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << endl;
    #elif defined(__clang__)
        cout << "    Clang" << endl;
    
        cout << "    Version: " << __clang_major__ << ".";
        cout << __clang_minor__ << "." << __clang_patchlevel__ << endl;
    #elif defined(_MSC_VER)
        cout << "    Microsoft Visual C++" << endl;
        cout << "    Version: " << _MSC_VER << endl;
        // For C++ standard version in MSVC, use _MSVC_LANG with /Zc:__cplusplus
        #if defined(_MSVC_LANG)
            cout << "    C++ Standard Version (via _MSVC_LANG): " << _MSVC_LANG << endl;
        #endif
    #else
        cout << "    Unknown Compiler" << endl;
    #endif
}

void cppStandard() {
    switch (__cplusplus) {
        case 202302L:
            cout << "C++23 Standard";
            break;
        case 202100L:
            cout << "Partial C++23";
            break;
        case 202002L:
            cout << "C++20 Standard";
            break;
        case 201703L:
            cout << "C++17 Standard";
            break;
        case 201402L:
            cout << "C++14 Standard";
            break;
        case 201103L:
            cout << "C++11 Standard";
            break;
        case 199711L:
            cout << "C++98 Standard";
            break;
        default:
            cout << "pre-standard C++";
            break;
    }
    cout << " implemented" << endl;
    cout << "    Standard Macro __cplusplus = " << __cplusplus << "L" << endl;
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
