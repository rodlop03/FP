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
#include <string>

using namespace std;

int askYear();
int askMonth();
int askDay();
long int elapsed(int day, int month, int year, int day1, int month1, int year1);
long int elapsedYear(int year, int year1);
int elapsedThisYear(int day, int month, int day1, int month1);
int countLeaps(int year1, int year);
int daysInMonth(int month, int year);
bool isLeap(int year);
int checkWeekDay(long int result);
string dayName(int weekDay);
int printMenu();
int printSundays(int year);
bool holiday();
const int day1 = 01, month1 = 01, year1 = 1900;


int main() {
  int sundays, firstSunday, menu, diference, resultYear, resultThisYear, leaps, daysMonth, weekDay;
  long int result;
  const int day1 = 01, month1 = 01, year1 = 1900;
  int day = 0, month = 0, year = 0;
  bool leap = false;
  string name;

  menu = printMenu();   //llama a menu, que devuelve un entero, ese entero se compara con los cases 
  switch (menu) {
    case 1:
      year = askYear();  //lee y comprueba año
      month = askMonth();//lee y comprueba mes
      day = askDay();//lee y comprueba dia
      
      
      // la funcion day solo lee comprueba y guarda el dia, pero si quitamos la parte de debuggin, el caso 1 no devuelve nada, habria que sacar un cout con el nombre del dia
       break;
    case 2:
      year = askYear();// lee comprueba y valida un año
      int aux1, aux2, aux3;
      aux1 =  elapsed(1, 1, year, day1, month1, year1);//OBLIGA AL MES Y DIA A SER 1 
      aux3 = checkWeekDay(aux1);
      for (int i = 1; aux2 !=7; i++) {
        aux1 =  elapsed(i, 1, year, day1, month1, year1);//el for va cambiando los dias pero solo los del mes de enero
        aux2 = checkWeekDay(aux1);
        firstSunday = aux2 - aux3 + 1;// NO LO ENTIENDO
      }
      cout << "El primer domingo del año " << year << " es el día: "<< firstSunday << " de Enero" << '\n'; // muestra
      break;
    case 3:
      year = askYear();//llama a ask year
      sundays =  printSundays(year);// llama a sundays con la variable year que acaba de recibir de ask year
      break;
    case 4:
      //code;
      break;
    case 0:
      //code;
      break;
    default:
    //code;
    break;
  }

  result = elapsed(day, month, year, day1, month1, year1);
  resultYear = elapsedYear(year, year1);
  cout << "dias hasta año " << resultYear << "\n";
  resultThisYear = elapsedThisYear(day, month, day1, month1);
  cout << "Dias este año " <<resultThisYear << "\n";
  leaps = countLeaps(year1, year);
  cout << "num de bisiestos " << leaps << "\n";
  daysMonth = daysInMonth(month, year);
  leap = isLeap(year);
  cout << year << (leap? " Es" : " No es") << " bisiesto\n";
  weekDay = checkWeekDay(result);
  name = dayName(weekDay);
  cout << "dias del mes " << daysMonth << "\n";// todo esto se va a borrar

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

long int elapsed(int day, int month, int year, int day1, int month1,
                 int year1) {
  long int result = 0;
  result += elapsedYear(year, year1);// diferencia entre años
  for (int i = month1; i < month; i++) {
    result += daysInMonth(i, year);//diferencia entre meses
  }
  result += day;//dia introducido
  return result;//muestra la suma acumulada de todos los años meses y dias
}

long int elapsedYear(int year, int year1) {
  int resultYear = ((year - year1) * 365) + countLeaps(year1, year) ;
  return resultYear;//diferencia entre años añadiendo bisiestos
}

int elapsedThisYear(int day, int month, int day1, int month1) {
  int resultThisYear = ((month - month1) * 30 + (day));
  return resultThisYear;//cuenta dias solo de este año, por eso no incluye la variable año
}

int countLeaps(int year1, int year) {//devuelve el numero de bisiestos entre los dos años
  int leaps = 0;
  for (int i = year1; i < year; i++) {
    if (isLeap(i)) {
      leaps++;
    }
  }
  return leaps;
}

int daysInMonth(int month, int year) {// define los dias que tiene cada mes
  int daysMonth;
  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||
      month == 10 || month == 12) {
    daysMonth = 31;
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    daysMonth = 30;
  } else {
    if (isLeap(year)) {
      daysMonth = 29;
    } else {
      daysMonth = 28;
    }
  }
  return daysMonth;
}

bool isLeap(int year) {// define si un año introducido es bisiesto o no
  bool divPorCuatroPeroNoCien = ( year % 4 == 0 ) && ( year % 100 != 0 );
  bool divPorCuatrocientos = ( year % 400 == 0 );
  bool leap = divPorCuatroPeroNoCien || divPorCuatrocientos;
  return leap;

}

int checkWeekDay(long int elapsed) {// con la resta acumulada limitas el valor de los dias a 1-7
  int weekDay, aux;//NO LO ENTIENDO
  aux = elapsed;//NO LO ENTIENDO
  while (aux > 7){//NO LO ENTIENDO
    aux -= 7;//NO LO ENTIENDO
  }//NO LO ENTIENDO
  weekDay = aux;//NO LO ENTIENDO
  return weekDay;//NO LO ENTIENDO
}

string dayName(int weekDay) { //asigna los dias en letra en funcion  del valor recibido de weekday
  string name;
  switch (weekDay) {
    case 1:
      name = "Lunes";
      break;
    case 2:
      name = "Martes";
      break;
    case 3:
      name = "Miércoles";
      break;
    case 4:
      name = "Jueves";
      break;
    case 5:
      name = "Viernes";
      break;
    case 6:
      name = "Sábado";
      break;
    case 7:
      name = "Domingo";
      break;
    default:
      cout << "This is broken\n" << weekDay;
  }
  cout << "El día de la semana es: " << name << "\n";
  return name;
}

int printMenu() {//muestra el meno y solo deja meter opciones 0-4
  int menu = 5;
  while (menu < 0 || menu > 4) {
    cout << "-------------------------------------------\n";
    cout << " 1 – Calcular el día de la semana para una fecha dada\n";
    cout << " 2 – Obtener la fecha correspondiente al primer domingo de un año\n";
    cout << " 3 – Obtener los domingos de un año\n";
    cout << " 4 – Obtener los posibles puentes de un año\n";
    cout << " 0 - Salir;\n";
    cout << "-------------------------------------------\n";
    cout << "Introduce una opcción: ";
    cin >> menu;
  }
  return menu;
}

int printSundays(int year) {
  int max, sundays, aux1, aux2, aux3, aux4, total = 0;
  cout << "\n"
       << "  Domingos de " << year << "\n";
  for (int i = 1; i < 13; i++) {
    aux1 = elapsed(1, i, year);
    aux3 = checkWeekDay(aux1);
    for (int j = 1; aux2 != 7; j++) {
      aux1 = elapsed(j, i, year);
      aux2 = checkWeekDay(aux1);
      sundays = aux2 - aux3 + 1;
      aux4 = sundays;
      max = daysInMonth(i, year);
      if (aux2 == 7 && aux4 < max) {
        cout << "   " << sundays << " de " << monthName[i - 1] << '\n';
        total++;
        for (int n = 0; aux4 < max; n++) {
          aux4 += 7;
          if (aux4 <= max) {
            cout << "   " << aux4 << " de " << monthName[i - 1] << '\n';
            total++;
          }
        }
      }
    }
    cout << "\n";
    aux4 = 0;
    aux2 = 0;
  }
  return total;
}

bool holiday() {
  int dayH, monthH, yearH, i = 0, aux;
  bool martes, jueves;
  char c;
  string lastW;
  ifstream file;
  ofstream newFIle;
  file.open("fiestas.txt");
  newFIle.open("puentes.txt");
  if (file.is_open()) {
    file >> yearH;
    while (dayH != 0) {
      file >> dayH;
      file.get(c);
      file >> monthH;
      if (newFIle.is_open()) {
        if (i == 0) {
          newFIle << yearH << endl;
        }
        i++;
        aux = elapsed(dayH, monthH, yearH);
        martes = checkWeekDay(aux) == 2;
        jueves = checkWeekDay(aux) == 4;
        lastW = ((martes) ? ("martes") : ("jueves"));
        if ((martes || jueves) && dayH != 0) {
          newFIle << dayH << " " << monthH << " " << lastW << endl;
        }
      }
    }
    newFIle << 0 << " " << 0 << " "
            << "XX";
    newFIle.close();
    file.close();
  }
}

// fsociety.txt

/*
Leave me here.
www.whoismrrobot.com
*/git status
