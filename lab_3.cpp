#include <iostream>
#include "dynamic_array.h" //my dynamic array in C++
using std::cout;
using std::cin;
using std::endl;

void Prog1();
void GetNumbers(mylib::dynamic_array<short>& array);
bool IsEven(short num);
short GetMinNumber(mylib::dynamic_array<short>& array);

int main()
{
    unsigned short task = 0;
    cout << "Какую задачу вы хотите решить?" << endl;
    cout << "  1. Найти минимальное число среди чисел массива." << endl;
    cout << "  2." << endl;
    cout << "  3." << endl;
    cout << "  4." << endl;
    cout << "Ваш выбор: ";
    cin >> task;

    switch (task)
    {
        case 1:
            Prog1();
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

void GetNumbers(mylib::dynamic_array<short>& array)
{
    unsigned short len = 0, method = 0;
    cout << "Введите желаемое количество чисел для обработки: ";
    cin >> len;
    if (len <= 0)
    {
        cout << "Длина - это натуральное число, подучи матан";
        return;
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
