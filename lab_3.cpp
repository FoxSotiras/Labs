#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits>
#include "dynamic_array.h" //my dynamic array in C++, watch https://github.com/FoxSotiras/MyLib-CPP for details

void Prog1();
void Prog2();
void Prog3();
void GetNumbers(mylib::dynamic_array<short>& array);
void GetString(std::string& string);
bool IsEven(short num);
void RemoveSymbols(std::string& input);
short GetMinNumber(mylib::dynamic_array<short>& array);
mylib::dynamic_array<std::string> SplitString(std::string input, std::string delimiter = " ");
void Convert10ToBaseK(mylib::dynamic_array<std::string>& array);

int main()
{
    unsigned short task = 0;
    std::cout << "Какую задачу вы хотите решить?" << std::endl;
    std::cout << "  1. Найти минимальное число среди чисел массива." << std::endl;
    std::cout << "  2. Ввод строки и её сортировка." << std::endl;
    std::cout << "  3. Преобразование чисел из 10 в 2-16 системы." << std::endl;
    std::cout << "  4." << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> task;

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
            std::cout << "Выбери номер задачи, малолетний дебил!" << std::endl;
            break;
    }

    return 0;
}

void Prog1()
{
    mylib::dynamic_array<short> nums;
    GetNumbers(nums);

    short min_num = GetMinNumber(nums);
    std::cout << "Минимальное чётное число в массиве: " << min_num << std::endl;
}

void Prog2()
{
    const unsigned short input_len = 512;

    char input[input_len];
    std::cout << "Введите строку: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.getline(input, input_len);

    char numbers[input_len], symbols[input_len], punctuation[input_len];
    unsigned short i = 0, numbers_cnt = 0, symbols_cnt = 0, punctuation_cnt = 0;
    while(input[i] != '\0')
    {
        if (input[i] >= 48 && input[i] <= 57)
        {
            numbers[numbers_cnt++] = input[i];
        }
        else if (input[i] == '!' || input[i] == '"' || input[i] == '\'' || input[i] == '?'
        || input[i] == '.' || input[i] == ',' || input[i] == '-' || input[i] == ':' || input[i] == ';'
        || input[i] == '[' || input[i] == ']' || input[i] == '(' || input[i] == ')')
        {
            punctuation[punctuation_cnt++] = input[i];
        }
        else if (input[i] > 32)
        {
            symbols[symbols_cnt++] = input[i];
        }

        ++i;
    }

    std::sort(numbers, numbers + numbers_cnt);
    std::sort(symbols, symbols + symbols_cnt);
    std::sort(punctuation, punctuation + punctuation_cnt);

    char output[input_len];
    std::memcpy(output, numbers, sizeof(char) * numbers_cnt);
    std::memcpy(output + numbers_cnt, symbols, sizeof(char) * symbols_cnt);
    std::memcpy(output + numbers_cnt + symbols_cnt, punctuation, sizeof(char) * punctuation_cnt);

    std::cout << "Отсортированная строка: " << output << std::endl;
}

void Prog3()
{
    std::string input;
    GetString(input);

    mylib::dynamic_array<std::string> string_array = SplitString(input);
    
    unsigned short flag = 0;
    std::cout << "Желаете перевести полученные числа в систему с другим основанием?" << std::endl;
    std::cout << "  1. Да" << std::endl << "  2. Нет" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> flag;
    switch (flag)
    {
        case 1:
            Convert10ToBaseK(string_array);
            break;
        case 2:
            break;
        default:
            std::cout << "Ну попросили же 1 или 2..." << std::endl;
            break;
    }

    std::cout << "Итоговые числа: ";
    for (unsigned int i = 0; i < string_array.size(); ++i)
    {
        std::cout << string_array[i] << ' ';
    }
    std::cout << std::endl;
}

void GetNumbers(mylib::dynamic_array<short>& array)
{
    unsigned short len = 0, method = 0;
    std::cout << "Введите желаемое количество чисел для обработки: ";
    std::cin >> len;
    if (len <= 0)
    {
        std::cout << "Длина - это натуральное число, подучи матан." << std::endl;
        exit(0);
    }
    
    std::cout << "Как вы хотите ввести числа?" << std::endl;
    std::cout << "  1. Самостоятельно." << std::endl << "  2. C помощью рандома (лень всему голова)." << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> method;

    short num = 0;
    switch (method)
    {
        case 1:
            for (unsigned short i = 0; i < len; ++i)
            {
                std::cout << "Введите число: ";
                std::cin >> num;
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
            std::cout << "Ты дурак?" << std::endl;
            break;
    }
}

void GetString(std::string& string)
{
    std::cout << "Введите строку чисел: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, string);
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

void RemoveSymbols(std::string& input)
{
    int len = input.size();
    for (unsigned long long i = 0, j = 0; i < len; ++i, ++j)
    {
        if (input[j] < 48 || input[j] > 57)
        {
            input.erase(j--, 1);
        }
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

mylib::dynamic_array<std::string> SplitString(std::string input, std::string delimiter)
{
    mylib::dynamic_array<std::string> array;
    std::string temp;

    while (input.find(delimiter) != std::string::npos)
    {
        temp = input.substr(0, input.find(delimiter));

        RemoveSymbols(temp);
        if (temp != "")
        {
            array.push_back(temp);
        }

        input.erase(0, input.find(delimiter) + 1);
    }

    RemoveSymbols(input);
    if (input != "")
    {
        array.push_back(input);
    }

    return array;
}

void Convert10ToBaseK(mylib::dynamic_array<std::string>& array)
{
    unsigned short k = 0;
    std::cout << "Какое основание для системы хотите выбрать?" << std::endl << "Ваш выбор: ";
    std::cin >> k;

    long long num = 0;
    mylib::dynamic_array<unsigned short> digits;
    std::string temp;
    for (unsigned int i = 0; i < array.size(); ++i)
    {
        num = std::stol(array[0]);

        if (num < 0)
        {
            temp += '-';
        }

        while (num != 0)
        {
            digits.insert(0, abs(num % k));
            num /= k;
        }

        for (unsigned int j = 0; j < digits.size(); ++j) {
            switch (digits[j])
            {
                case 0: temp += '0'; break;
                case 1: temp += '1'; break;
                case 2: temp += '2'; break;
                case 3: temp += '3'; break;
                case 4: temp += '4'; break;
                case 5: temp += '5'; break;
                case 6: temp += '6'; break;
                case 7: temp += '7'; break;
                case 8: temp += '8'; break;
                case 9: temp += '9'; break;
                case 10: temp += 'A'; break;
                case 11: temp += 'B'; break;
                case 12: temp += 'C'; break;
                case 13: temp += 'D'; break;
                case 14: temp += 'E'; break;
                case 15: temp += 'F'; break;
            }
        }

        array.push_back(temp);
        array.erase(0, 1);
        digits.clear();
        temp.clear();
    }
}
