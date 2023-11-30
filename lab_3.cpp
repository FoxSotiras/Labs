#include <iostream>
#include <random>
#include <algorithm>
#include <cstring>
#include <string>
#include <limits>
#include "dynamic_array.h" //my dynamic array in C++, watch https://github.com/FoxSotiras/MyLib-CPP for details

void Prog1();
void Prog2();
void Prog3();
void Prog4();
void UserInput(mylib::dynamic_array<int>& array, unsigned long long len);
void RandInput(mylib::dynamic_array<int>& array, unsigned long long len);
void GetNumbers(mylib::dynamic_array<int>& array);
void GetString(std::string& string);
bool IsEven(int num);
bool ThreeOnesInBinary(int num);
bool IsPrime(int num);
void RemoveSymbols(std::string& input);
int GetMinNumber(mylib::dynamic_array<int>& array);
int GetMaxNumber(mylib::dynamic_array<int>& array);
int GetMinEvenNumber(mylib::dynamic_array<int>& array);
mylib::dynamic_array<std::string> SplitString(std::string input, std::string delimiter = " ");
void Convert10ToBaseK(mylib::dynamic_array<std::string>& array);
double GetArithmeticMean(mylib::dynamic_array<int>& array);
void SortArray(mylib::dynamic_array<int>& array);
mylib::dynamic_array<int> GetNumbersByBinary(mylib::dynamic_array<int>& input);
void ErasePrimeNumbers(mylib::dynamic_array<int>& array);

int main()
{
    unsigned short task = 0;
    std::cout << "Какую задачу вы хотите решить?" << std::endl;
    std::cout << "  1. Найти минимальное число среди чисел массива." << std::endl;
    std::cout << "  2. Ввод строки и её сортировка." << std::endl;
    std::cout << "  3. Преобразование чисел из 10 в 2-16 системы." << std::endl;
    std::cout << "  4. Операции над одномерным целочисленным массивом." << std::endl;
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
        case 4:
            Prog4();
            break;
        default:
            std::cout << "Выбери номер задачи, малолетний дебил!" << std::endl;
            break;
    }

    return 0;
}

void Prog1()
{
    mylib::dynamic_array<int> nums;
    GetNumbers(nums);

    int min_num = GetMinEvenNumber(nums);
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
    unsigned short numbers_cnt = 0, symbols_cnt = 0, punctuation_cnt = 0;
    for(unsigned short i = 0; input[i] != '\0'; ++i)
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
    for (unsigned long long i = 0; i < string_array.size(); ++i)
    {
        std::cout << string_array[i] << ' ';
    }
    std::cout << std::endl;
}

void Prog4()
{
    mylib::dynamic_array<int> array_A;
    GetNumbers(array_A);
    std::cout << "Изначальный массив A: ";
    for (int i = 0; i < array_A.size(); ++i)
    {
        std::cout << array_A[i] << ' ';
    }
    std::cout << std::endl;

    int arithmetic_mean = GetArithmeticMean(array_A);
    std::cout << "1. Среднее арифметическое чисел между наибольшим и наименьшим элементами: " << arithmetic_mean << std::endl;

    mylib::dynamic_array<int> array_B = GetNumbersByBinary(array_A);
    std::cout << "2. Сформированный массив B из массива A: ";
    for (unsigned long long i = 0; i < array_B.size(); ++i)
    {
        std::cout << array_B[i] << ' ';
    }
    std::cout << std::endl;

    SortArray(array_A);
    std::cout << "3. Сортировка массива A: ";
    for (unsigned long long i = 0; i < array_A.size(); ++i)
    {
        std::cout << array_A[i] << ' ';
    }
    std::cout << std::endl;

    ErasePrimeNumbers(array_A);
    std::cout << "4. Удаление простых чисел из массива A: ";
    for (unsigned long long i = 0; i < array_A.size(); ++i)
    {
        std::cout << array_A[i] << ' ';
    }
    std::cout << std::endl;
}

void UserInput(mylib::dynamic_array<int>& array, unsigned long long len)
{
    int num = 0;

    for (unsigned long long i = 0; i < len; ++i)
    {
        std::cout << "Введите число: ";
        std::cin >> num;
        array.push_back(num);
    }
}

void RandInput(mylib::dynamic_array<int>& array, unsigned long long len)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 10000);

    for (unsigned long long i = 0; i < len; ++i)
    {
        array.push_back(dist(rd));
    }
}

void GetNumbers(mylib::dynamic_array<int>& array)
{
    unsigned long long len = 0;
    unsigned short method = 0;
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

    switch (method)
    {
        case 1:
            UserInput(array, len);
            break;
        case 2:
            RandInput(array, len);
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

bool IsEven(int num)
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

bool ThreeOnesInBinary(int num)
{
    int cnt = 0;

    while (num != 0)
    {
        num = num & (num - 1);
        ++cnt;
    }

    if (cnt > 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool IsPrime(int num)
{
    int cnt = 0;

    for (int j = 1; j <= sqrt(num); ++j)
    {
        if (num % j == 0)
        {
            cnt += 2;
        }
    }

    if (cnt == 2 && num != 1)
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

int GetMinNumber(mylib::dynamic_array<int>& array)
{
    int num = 0, min = 10000;

    for (unsigned short i = 0; i < array.size(); ++i)
    {
        num = array[i];

        if (num < min)
        {
            min = num;
        }
    }

    return min;
}

int GetMaxNumber(mylib::dynamic_array<int>& array)
{
    int num = 0, max = -10000;

    for (unsigned short i = 0; i < array.size(); ++i)
    {
        num = array[i];

        if (num > max)
        {
            max = num;
        }
    }

    return max;
}

int GetMinEvenNumber(mylib::dynamic_array<int>& array)
{
    int min = 10000;
    int num = 0;

    for (unsigned short i = 0; i < array.size(); ++i)
    {
        num = array[i];

        if (num < min && IsEven(num))
        {
            min = num;
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
    for (unsigned long long i = 0; i < array.size(); ++i)
    {
        num = std::stoll(array[0]);

        if (num < 0)
        {
            temp += '-';
        }

        while (num != 0)
        {
            digits.insert(0, abs(num % k));
            num /= k;
        }

        for (unsigned long long j = 0; j < digits.size(); ++j)
        {
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

double GetArithmeticMean(mylib::dynamic_array<int>& array)
{
    int cnt = 0, min = 0, max = 0;
    double sum = 0;
    min = GetMinNumber(array);
    max = GetMaxNumber(array);

    unsigned long long min_index = 0, max_index = 0;
    for (unsigned long long i = 0; i < array.size(); ++i)
    {
        if (array[i] == min)
        {
            min_index = i;
        }
        if (array[i] == max)
        {
            max_index = i;
        }
    }

    if (min_index > max_index)
    {
        while (max_index <= min_index)
        {
            sum += array[max_index++];
            ++cnt;
        }
    }
    else
    {
        while (min_index <= max_index)
        {
            sum += array[min_index++];
            ++cnt;
        }
    }

    return sum / cnt;
}

void SortArray(mylib::dynamic_array<int>& array)
{
    for(unsigned long long i = 0; i < array.size(); ++i)
    {
        int a = array[i];
        if (array[i] > 0)
        {
            array.insert(0, array[i]);
            array.erase(i + 1, 1);
        }
    }
    for(unsigned long long i = 0; i < array.size(); ++i)
    {
        int a = array[i];
        if (array[i] < 0)
        {
            array.insert(0, array[i]);
            array.erase(i + 1, 1);
        }
    }
}

mylib::dynamic_array<int> GetNumbersByBinary(mylib::dynamic_array<int>& input)
{
    mylib::dynamic_array<int> output;

    for (unsigned long long i = 0; i < input.size(); ++i)
    {
        if (ThreeOnesInBinary(input[i]))
        {
            output.push_back(input[i]);
        }
    }

    return output;
}

void ErasePrimeNumbers(mylib::dynamic_array<int>& array)
{
    for (unsigned long long i = 0; i < array.size(); ++i)
    {
        if (IsPrime(array[i]))
        {
            array.erase(i, 1);
        }
    }
}
