//
// Created by Никита Степанов on 22.03.2024.
//

#ifndef DATETIME_DATETIME_H
#define DATETIME_DATETIME_H

#include <iostream>
#include <string>
#include <cmath>

class DateTime {
private:
    int year, month, day;
    double time; // Время хранится как дробная часть дня

public:

    // Метод для проверки корректности даты
    bool isValidDate(int y, int m, int d);

    DateTime(int y, int m, int d, double t);

    // Метод для проверки високосного года
    bool isLeapYear(int y) const;

    // Перегрузка оператора сложения для добавления дней к дате
    DateTime operator+(int days) const;

    // Перегрузка оператора вычитания для вычисления разницы между датами в днях
    int operator-(const DateTime& other) const {
        int days1 = toDays();
        int days2 = other.toDays();
        return std::abs(days1 - days2);
    }

    // Перегрузка операторов сравнения дат
    bool operator>(const DateTime& other) const {
        if (year != other.year)
            return year > other.year;
        if (month != other.month)
            return month > other.month;
        if (day != other.day)
            return day > other.day;
        return time > other.time;
    }

    bool operator<(const DateTime& other) const {
        return !(*this > other || *this == other);
    }

    bool operator>=(const DateTime& other) const {
        return (*this > other || *this == other);
    }

    bool operator<=(const DateTime& other) const {
        return !(*this > other);
    }

    bool operator==(const DateTime& other) const {
        return year == other.year && month == other.month && day == other.day && time == other.time;
    }

    // Метод для вычисления номера дня недели (0 - воскресенье, 1 - понедельник, ..., 6 - суббота)
    int getDayOfWeek() const;

    // Метод для преобразования даты в количество дней относительно опорной даты
    int toDays() const;

    // Вспомогательная функция для получения количества дней в месяце
    int daysInMonth(int y, int m) const;

    // Метод для вывода даты и времени в формате yyyy-MM-ddThh:mm:ss
    void printDateTime() const {
        printf("%02d.%02d.%04dT%02d:%02d:%02d\n", day, month, year, static_cast<int>(time * 24), static_cast<int>((time * 1440)) % 60), static_cast<int>(time * 86400) % 60;
    }

    // Метод для определения даты пасхи
    DateTime calculateEasterDate() const;

};

#endif //DATETIME_DATETIME_H
