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

#include <iostream> 

using namespace std;

int askYear();
int askMonth();
int askDay();
long int elapsed(int day, int month, int year, int day1, int month1, int year1);
long int elapsedYear(int day, int month, int year, int day1, int month1, int year1);

int main() {
	int diference, result, resultYear;;
	const int day1 = 01, month1 = 01, year1 = 1900;
	int day = 0, month = 0, year = 0;

	year = askYear();
	month = askMonth();
	day = askDay();
	result = elapsed(day, month, year, day1, month1, year1);
	resultYear = elapsedYear(day, month, year, day1, month1, year1);
	


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
	cout << result << "\n";

	return result;

}
long int elapsedYear(int day, int month, int year, int day1, int month1, int year1){
	int resultYear = ((year -year1)*365);
	cout << resultYear << "\n";

	return resultYear;

}


