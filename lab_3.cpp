#include <iostream>
#include <cstdlib>
#include <random>
#include "dynamic_array.h"

void Prog1();
void GetNumbers(DynamicArray* array);
void GetRandomNumbers(DynamicArray* array);
bool IsEven(int number);
int GetMinNumber(DynamicArray* array);

int main()
{
    int task = 0;
	std::cout << "Какую задачу вы хотите решить(1, 2, 3, 4)?: ";
	std::cin >> task;

	switch (task)
	{
        case 1:
            Prog1();
            break;
        // case 2:
        //     Prog2();
        //     break;
        // case 3:
        //     Prog3();
        //     break; 
        // case 4:
        //     Prog4();
        //     break;
        default:
            break;
	}
}

void Prog1()
{
    DynamicArray* numbers = new DynamicArray();
    
    int method = 0;
    std::cout << "Выберите способо ввода чисел(1 - самостоятельно, 2 - рандом): ";
    std::cin >> method;

    switch (method)
    {
        case 1:
            GetNumbers(numbers);
            break;
        case 2:
            GetRandomNumbers(numbers);
            break;
        default:
            break;
    }

    int min = GetMinNumber(numbers);
    std::cout << "Минимальное число последовательности = " << min << std::endl;
    delete numbers; 
}

void GetNumbers(DynamicArray* array)
{
    int len = 0, num = 0;
    std::cout << "Введите количество обрабатываемых чисел: ";
    std::cin >> len;

    for (int i = 0; i < len; ++i)
    {
        std::cout << "Введите число: ";
        std::cin >> num;
        array->push_back(num);
    }
}

void GetRandomNumbers(DynamicArray* array)
{
    int len = 0, num = 0;
    std::cout << "Введите количество обрабатываемых чисел: ";
    std::cin >> len;

    for (int i = 0; i < len; ++i)
    {
        array->push_back(rand() % 10000);
    }
}

bool IsEven(int number)
{
    if (number % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int GetMinNumber(DynamicArray* array)
{
    int min = 10000;
    int number = 0;

    for (int i = 0; i < array->last_item_index; ++i)
    {
        number = (*array)[i];

        if (number < min && IsEven(number))
        {
            min = number;
        }
    }

    return min;
}
