/*
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
 // AUTORÍA: DANIEL FIDALGO PANERA y RODRIGO LÓPEZ

#include <iostream>

using namespace std;

int askYear();
int askMonth();
int askDay();
long int elapsed(int day, int month, int year, int day1, int month1, int year1);
long int elapsedYear(int year, int year1);
int elapsedThisYear(int day, int month, int day1, int month1);
int countLeaps(int year1, int year);
int daysInMonth(int month, int year);

int main() {
	int diference, result, resultYear, resultThisYear, leaps,daysMonth;
	const int day1 = 01, month1 = 01, year1 = 1900;
	int day = 0, month = 0, year = 0;

	year = askYear();
	month = askMonth();
	day = askDay();
	result = elapsed(day, month, year, day1, month1, year1);
	resultYear = elapsedYear(year, year1);
	resultThisYear = elapsedThisYear(day, month, day1, month1);
	leaps = countLeaps(year1, year);
    daysMonth = daysInMonth(month, year);


	while (day > 31 || day < 1) {
		cout << "Introduce el dia: ";
		cin >> day;
	}


	for (int i = 0; i < diference; i++) {
		if (i % 7 == 0) {

		}
	}

	return 0;
}

int askYear() {
	int year;
	do {
		cout << "Introduce el año posterior a 1900 : ";
		cin >> year;
	} while (year < 1900);

	return year;
}

int askMonth() {
	int month;
	do {
		cout << "Introduce el mes: ";
		cin >> month;
	} while (month > 12 || month < 1);

	return month;
}

int askDay() {
	int day;
	do {
		cout << "Introduce el dia: ";
		cin >> day;
	} while (day > 31 || day < 1);

	return day;
}

long int elapsed(int day, int month, int year, int day1, int month1, int year1){
	int result = ((year -year1)*365 + (month - month1)*30 + (day -day1));
	cout <<"dias transcurridos" <<result << "\n";

	return result;

}
long int elapsedYear(int year, int year1){
	int resultYear = ((year -year1)*365);
	cout << "dias hasta año"<< resultYear << "\n";

	return resultYear;

}

int elapsedThisYear(int day, int month, int day1, int month1){
	int resultThisYear = ((month - month1)*30  + (day -day1));
	cout << resultThisYear << "\n";

	return resultThisYear;

}

int countLeaps(int year1, int year) {
    int leaps = 0;
    for(int i = year1; i<= year; i++){
        if(i % 4 == 0 && (i % 100 != 0 || i % 400 == 0)){
         leaps++;
        }
    }
    cout << "num de bisiestos"<< leaps;

	return leaps;
}

int daysInMonth(int month, int year) {
    int daysMonth;
    if (month == 1 ||month == 3 || month == 5 || month == 7 || month == 8 || month == 10 ||month == 12){
     daysMonth = 31;
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
     daysMonth = 30;
    } else {
        if(2 == 2) { //TODO: si bool si 29 y si bool no 28; dejo estructura hecha.
        daysMonth = 29;
        } else {
        daysMonth = 28;
        }
    }
    cout << "dias del mes"<< daysMonth;
    return daysMonth;
}
