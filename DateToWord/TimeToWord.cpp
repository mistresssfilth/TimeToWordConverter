#include <exception>
#include <iostream>

using namespace std;


void converter(int hour, int minutes) {
    char nums[][32] = { 
        "Ноль", "Одна", "Две", "Три", "Четыре", 
        "Пять", "Шесть", "Семь", "Восемь",
        "Девять", "Десять", "Одиннадцать", 
        "Двенадцать", "Тринадцать", "Четырнадцать", 
        "Пятнадцать", "Шестандцать","Семнадцать", "Восемнадцать", 
        "Девятнадцать", "Двадцать", "Двадцать одна", "Двадцать два", 
        "Двадцать три", "Двадцать четыре", "Двадцать пять", 
        "Двадцать шесть", "Двадцать семь", "Двадцать восемь", 
        "Двадцать девять"
    };
    char before[][32] = {
        "Нуля", "часа", "двух", "трех", "четырех", "пяти", 
        "шести", "семи", "восьми", "девяти",
        "десяти", "одиннадцати", "двенадцати"
    };
    char half[][32] = {
        "Нуль", "первого", "второго", "третьего",
        "четвертого", "пятого", "шестого",
        "седьмого", "восьмого", "девятого",
        "десятого", "одиннадцатого", "двенадцатого",
    };

    if (minutes == 0)
        cout << nums[minutes] << " часов.";
    else if (minutes == 1)
        cout << "Одна минута после " << before[hour % 12];
    else if (minutes == 15)
        cout << "Четверть " << half[hour % 12 + 1];
    else if (minutes == 30)
        cout << "Половина " << half[hour % 12 + 1];
    else if (minutes == 45)
        cout << "Четверть до" << before[hour % 12 + 1];
    else if (minutes == 59)
        cout << "Одна минута до " << before[hour % 12 + 1];
    else if (minutes < 5)
        cout << nums[minutes] << " минуты после " << before[hour % 12];
    else if (minutes < 30)
        cout << nums[minutes] << " минут после " << before[hour % 12];
    else
        cout << nums[60 - minutes] << " минут до " << before[hour % 12 + 1];
}
void check(int hour, int minutes) {
    if (hour < 0 || hour > 23 || minutes > 59 || minutes < 0)
        throw "Некорректное число";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Hello World!\n";
    int hour;
    int minutes;
    cin >> hour;
    cin >> minutes;

    try {
        check(hour, minutes);
        converter(hour, minutes);
    }
    catch(const char* msg){
        cout << msg;
    }

    

}

