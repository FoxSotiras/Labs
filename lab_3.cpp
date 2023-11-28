#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits>
#include "dynamic_array.h" //my dynamic array in C++, watch https://github.com/FoxSotiras/MyLib-CPP for details
using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::memcpy;
using std::numeric_limits;
using std::streamsize;

void Prog1();
void Prog2();
void Prog3();
void GetNumbers(mylib::dynamic_array<short>& array);
bool IsEven(short num);
short GetMinNumber(mylib::dynamic_array<short>& array);

int main()
{
    unsigned short task = 0;
    cout << "Какую задачу вы хотите решить?" << endl;
    cout << "  1. Найти минимальное число среди чисел массива." << endl;
    cout << "  2. Ввод строки и её сортировка." << endl;
    cout << "  3. " << endl;
    cout << "  4." << endl;
    cout << "Ваш выбор: ";
    cin >> task;

    switch (task)
    {
        case 1:
            Prog1();
            break;
        case 2:
            Prog2();
            break;
        case 3:
            Prog3();
            break;
        default:
            cout << "Выбери номер задачи, малолетний дебил!" << endl;
            break;
    }

    return 0;
}

void Prog1()
{
    mylib::dynamic_array<short> nums;
    GetNumbers(nums);

    short min_num = GetMinNumber(nums);
    cout << "Минимальное чётное число в массиве: " << min_num << endl;
}

void Prog2()
{
    const unsigned short string_len = 512;

    char string[string_len];
    cout << "Введите строку: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(string, string_len);

    char numbers[string_len], symbols[string_len], punctuation[string_len];
    unsigned short i = 0, numbers_cnt = 0, symbols_cnt = 0, punctuation_cnt = 0;
    while(string[i] != '\0')
    {
        if (string[i] >= 48 && string[i] <= 57)
        {
            numbers[numbers_cnt++] = string[i];
        }
        else if (string[i] == '!' || string[i] == '"' || string[i] == '\'' || string[i] == '?'
        || string[i] == '.' || string[i] == ',' || string[i] == '-' || string[i] == ':' || string[i] == ';'
        || string[i] == '[' || string[i] == ']' || string[i] == '(' || string[i] == ')')
        {
            punctuation[punctuation_cnt++] = string[i];
        }
        else if (string[i] > 32)
        {
            symbols[symbols_cnt++] = string[i];
        }

        ++i;
    }

    sort(numbers, numbers + numbers_cnt);
    sort(symbols, symbols + symbols_cnt);
    sort(punctuation, punctuation + punctuation_cnt);

    char output[string_len];
    memcpy(output, numbers, sizeof(char) * numbers_cnt);
    memcpy(output + numbers_cnt, symbols, sizeof(char) * symbols_cnt);
    memcpy(output + numbers_cnt + symbols_cnt, punctuation, sizeof(char) * punctuation_cnt);

    cout << "Отсортированная строка: " << output << endl;
}

void Prog3()
{

}

void GetNumbers(mylib::dynamic_array<short>& array)
{
    unsigned short len = 0, method = 0;
    cout << "Введите желаемое количество чисел для обработки: ";
    cin >> len;
    if (len <= 0)
    {
        cout << "Длина - это натуральное число, подучи матан." << endl;
        exit(0);
    }
    
    cout << "Как вы хотите ввести числа?" << endl;
    cout << "  1. Самостоятельно." << endl << "  2. C помощью рандома (лень всему голова)." << endl;
    cout << "Ваш выбор: ";
    cin >> method;

    short num = 0;
    switch (method)
    {
        case 1:
            for (int i = 0; i < len; ++i)
            {
                cout << "Введите число: ";
                cin >> num;
                array.push_back(num);
            }

            break;
        case 2:
            for (unsigned short i = 0; i < len; ++i)
            {
                array.push_back(rand() % 10000);
            }

            break;
        default:
            cout << "Ты дурак?" << endl;
            break;
    }
}

bool IsEven(short num)
{
    if (num % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

short GetMinNumber(mylib::dynamic_array<short>& array)
{
    short min = 10000;
    short number = 0;

    for (unsigned short i = 0; i < array.size(); ++i)
    {
        number = array[i];

        if (number < min && IsEven(number))
        {
            min = number;
        }
    }

    return min;
}
