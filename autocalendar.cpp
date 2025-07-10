#include <iostream>
#include <cmath>

int main() {
    /**
    Takes month, day, year int input and returns
    day of week and if the year is a leap year.

    Utilizes the following formula
	w = { d + floor(2.6*m-0.2) + y + floor(y/4) + floor(c/4)-2*c} mod 7
    a Disparate Variation of Gauss's Algorithm to calculate the day of the week

    d := date of the month
    m := adjusted month number: 
        January = 11, February = 12, March = 1, April = 2, ..., December = 10
    c := last 2 digits of a 4 digit year
    y := first 2 digits of a 4 digit year
        if m == 11 || m == 12
        y = y - 1
    w := day of week: Sunday = 0, Monday = 1, ..., Sunday = 6

    Sources:
    https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
    used Disparate variation under Gauss's Algorithm 
    https://en.wikipedia.org/wiki/Leap_year#Algorithm
    */

    /* Date Input */
    int month = 3;
    int date = 19;
    int year = 2025;

    std::cout << "Enter the month: ";
    std::cin >> month;
    std::cout << "Enter the date: ";
    std::cin >> date;
    std::cout << "Enter the year: ";
    std::cin >> year;
    std::cout << std::endl;

    std::string day_list[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday", 
        "Thursday", "Friday", "Saturday"
    };
    std::string month_list[] = {
        "January", "February", "March", "April", 
        "May", "June", "July", "August", 
        "September", "October", "November", "December"
    };

    /* Modification of month day & year into m, d, and y */
    // calculation of c and y from a numberical year utilizing a string
    std::string zero = "0";
    std::string year_string;
    if (year >= 1000) {
        year_string = std::to_string(year);
    }
    else if (year <= 999 && year >= 100){
        year_string = zero + zero + std::to_string(year);
    }
    else if (year <= 99 && year >= 10) {
        year_string = zero + zero +std::to_string(year);
    }
    else if (year <= 9) {
        year_string = zero + zero +zero + std::to_string(year);
    }
    else {
        year_string = std::to_string(year);
    }
    
    int c = (year_string[0] - '0')*10 + (year_string[1] - '0');
    int y = (year_string[2] - '0')*10 + (year_string[3] - '0');

    // modification of y for January and February
    if (month == 1 || month == 2) {
        int y = y - 1;
    }

    // calculation of d from date of month
    int d = date;

    // calculation of m from month of year (shifting the month number)
    int m = month - 2;
    if (month == 11 || month == 12) {
        m += 12;
    }

    /* calculation of day of the week */
    int w = d + std::floor(2.6*m-0.2) + y + std::floor(y/4) + std::floor(c/4) - 2*c;
    w = w % 7;
    std::cout << "The day of the week is: " << day_list[w] << "." << std::endl;

    /* calculation of leap year */
    bool leap_year;
    if (year % 4 != 0) {
        leap_year = false;
    }
    else if (year % 100 != 0) {
        leap_year = true;
    }
    else if (year % 400 != 0) {
        leap_year = false;
    }
    else {
        leap_year = true;
    }
    if (leap_year) {
        std::cout << year << " is a leap year." << std::endl;
    }
    else {
        std::cout << year << " is not a leap year." << std::endl;
    }
    return 0;
}
