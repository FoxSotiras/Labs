#include <cmath>
#include "int_dynamic_array.h"

void Prog1();
void Prog2();
void GetNumbers(IntDynamicArray* array);
void PrintNumbers(IntDynamicArray* array);
IntDynamicArray* GetPrimeNumbers(IntDynamicArray* input_array);
IntDynamicArray* GetSpecialNumbers(IntDynamicArray* input_array);
int GetMaxNumber(IntDynamicArray* array);
int GetFirstDigit(int num);
int GetLastDigit(int num);
bool HaveZero(int num);

int main()
{
    int task = 0;
    std::cout << "Какую задачу вы хотите решить(1, 2): ";
    std::cin >> task;

    switch (task)
    { 
        case 1:
            Prog1();
            break;
        case 2:
            Prog2();
            break;
        default:
            std::cout << "Введите числа от 1 до 2." << std::endl;
            break;
    }
    
    return 0;
}

void Prog1()
{
    IntDynamicArray* numbers = new IntDynamicArray();
    GetNumbers(numbers);

    IntDynamicArray* prime_numbers = new IntDynamicArray();
    prime_numbers = GetPrimeNumbers(numbers);
    delete numbers;

    int max_prime_number = GetMaxNumber(prime_numbers);

    std::cout << "Количество простых чисел = " << prime_numbers->last_item_index << std::endl << "Максимальное из них = " << max_prime_number << std::endl;
    delete prime_numbers;
}

void Prog2()
{
    IntDynamicArray* numbers = new IntDynamicArray();
    GetNumbers(numbers);

    IntDynamicArray* special_numbers = new IntDynamicArray();
    special_numbers = GetSpecialNumbers(numbers);
    delete numbers;

    std::cout << "Числа, удовлетворяющие условию: ";
    PrintNumbers(special_numbers);
    delete special_numbers;
}

void GetNumbers(IntDynamicArray* array)
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

void PrintNumbers(IntDynamicArray* array)
{
    for (int i = 0; i < array->last_item_index; ++i)
    {
        std::cout << (*array)[i] << " ";
    }
    std::cout << std::endl;
}

IntDynamicArray* GetPrimeNumbers(IntDynamicArray* input_array)
{
    int cnt = 0, num = 0;
    IntDynamicArray* output_array = new IntDynamicArray();

    for (int i = 0; i < input_array->last_item_index; ++i)
    {
        cnt = 0;
        num = (*input_array)[i];

        for (int j = 1; j <= sqrt(num); ++j)
        {
            if (num % j == 0)
            {
                cnt += 2;
            }
        }

        if (cnt == 2 && num != 1)
        {
            output_array->push_back(num);
        }
    }

    return output_array;
}

IntDynamicArray* GetSpecialNumbers(IntDynamicArray* input_array)
{
    int num = 0;
    IntDynamicArray* output_array = new IntDynamicArray();

    for (int i = 0; i < input_array->last_item_index; ++i)
    {
        num = (*input_array)[i];

        if (GetFirstDigit(num) != GetLastDigit(num) && !HaveZero(num))
        {
            output_array->push_back(num);
        }
    }

    return output_array;
}

int GetMaxNumber(IntDynamicArray* array)
{
    int max = 0, num = 0;

    for (int i = 0; i < array->last_item_index; ++i)
    {
        num = (*array)[i];
        if (num > max)
        {
            max = num;
        }
    }

    return max;
}

int GetFirstDigit(int num)
{
    int first = 0;

    while (num > 10)
    {
        first = num / 10;
        num /= 10;
    }

    return first;
}

int GetLastDigit(int num)
{
    return num % 10;
}

bool HaveZero(int num)
{
    bool stat = false;
    int digit = 0;

    while (num != 0)
    {
        digit = num % 10;

        if (digit == 0)
        {
            stat = true;
            break;
        }

        num /= 10;
    }

    return stat;
}
