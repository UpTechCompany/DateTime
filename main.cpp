#include <iostream>
#include "DateTime/DateTime.h"

int main() {
    DateTime dt1(2024, 1, 12, 0.0);
    DateTime dt2 = dt1 + 100; // Добавляем 100 дней к дате

    std::cout << "Дата 1: ";
    dt1.printDateTime();
    std::cout << "Дата 2: ";
    dt2.printDateTime();

    std::cout << "Разница дней: " << (dt2 - dt1) << " days\n";

    if (dt2 > dt1) {
        std::cout << "Дата 2 больше Даты 1\n";
    }

    std::cout << "Пасха: ";
    dt1.calculateEasterDate().printDateTime();

    return 0;
}

