#include "iostream"
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

int main () {
    std::cout << "Input day of week: ";
    int day;
    std::cin >> day;
    if (day == MONDAY) std::cout << "Monday" << std::endl;
    else if (day == TUESDAY) std::cout << "Tuesday" << std::endl;
    else if (day == WEDNESDAY) std::cout << "Wednesday" << std::endl;
    else if (day == THURSDAY) std::cout << "Thursday" << std::endl;
    else if (day == FRIDAY) std::cout << "Friday" << std::endl;
    else if (day == SATURDAY) std::cout << "Saturday" << std::endl;
    else if (day == SUNDAY) std::cout << "Sunday" << std::endl;
    else std::cout << "Invalid day";
}