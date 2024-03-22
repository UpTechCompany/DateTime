//
// Created by Никита Степанов on 22.03.2024.
//

#include "DateTime.h"

bool DateTime::isValidDate(int y, int m, int d) {
    if (m < 1 || m > 12 || d < 1)
        return false;

    static const int daysInMonth[] = {31, 28 + isLeapYear(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    return d <= daysInMonth[m - 1];
}

DateTime::DateTime(int y, int m, int d, double t){
    if (isValidDate(y, m, d)){
        year = y;
        month = m;
        day = d;
        time = t;
    } else {
        year = month = day = time = 0;
    }

}

bool DateTime::isLeapYear(int y) const {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

DateTime DateTime::operator+(int days) const {
    int y = year, m = month, d = day + days;
    while (d > daysInMonth(y, m)) {
        d -= daysInMonth(y, m);
        if (++m > 12) {
            m = 1;
            ++y;
        }
    }
    return DateTime(y, m, d, time);
}


int DateTime::getDayOfWeek() const {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
}

int DateTime::toDays() const {
    int y = year, m = month;
    int totalDays = day - 1; // Начинаем с 0
    while (--m > 0) {
        totalDays += daysInMonth(y, m);
    }
    return totalDays + 365 * (y - 1) + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
}

int DateTime::daysInMonth(int y, int m) const {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return m == 2 && isLeapYear(y) ? 29 : days[m - 1];
}

DateTime DateTime::calculateEasterDate() const {
    int g = year % 19;
    int c = year / 100;
    int h = (c - c / 4 - (8 * c + 13) / 25 + 19 * g + 15) % 30;
    int i = h - h / 28 * (1 - 29 / (h + 1) * ((21 - g) / 11));
    int dayEaster = i - (year + year / 4 + i + 2 - c + c / 4) % 7;
    int monthEaster = 3 + (dayEaster + 40) / 44;
    dayEaster += 28 - 31 * (monthEaster / 4);
    return DateTime(year, monthEaster, dayEaster, time);
}