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
using std::string;
using std::getline;
using std::stol;
using std::to_string;

void Prog1();
void Prog2();
void Prog3();
void GetNumbers(mylib::dynamic_array<short>& array);
void GetString(string& string);
bool IsEven(short num);
short GetMinNumber(mylib::dynamic_array<short>& array);
mylib::dynamic_array<string> SplitString(string input, string delimiter = " ");
void Convert10ToBaseK(mylib::dynamic_array<string>& array);

int main()
{
    unsigned short task = 0;
    cout << "Какую задачу вы хотите решить?" << endl;
    cout << "  1. Найти минимальное число среди чисел массива." << endl;
    cout << "  2. Ввод строки и её сортировка." << endl;
    cout << "  3. Преобразование чисел из 10 в 2-16 системы." << endl;
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
    const unsigned short input_len = 512;

    char input[input_len];
    cout << "Введите строку: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(input, input_len);

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

    sort(numbers, numbers + numbers_cnt);
    sort(symbols, symbols + symbols_cnt);
    sort(punctuation, punctuation + punctuation_cnt);

    char output[input_len];
    memcpy(output, numbers, sizeof(char) * numbers_cnt);
    memcpy(output + numbers_cnt, symbols, sizeof(char) * symbols_cnt);
    memcpy(output + numbers_cnt + symbols_cnt, punctuation, sizeof(char) * punctuation_cnt);

    cout << "Отсортированная строка: " << output << endl;
}

void Prog3()
{
    string input;
    GetString(input);

    mylib::dynamic_array<string> string_array = SplitString(input);
    
    unsigned short flag = 0;
    cout << "Желаете перевести полученные числа в систему с другим основанием?" << endl;
    cout << "  1. Да" << endl << "  2. Нет" << endl;
    cout << "Ваш выбор: ";
    cin >> flag;
    switch (flag)
    {
        case 1:
            Convert10ToBaseK(string_array);
            break;
        case 2:
            break;
        default:
            cout << "Ну попросили же 1 или 2..." << endl;
            break;
    }

    cout << "Итоговые числа: ";
    for (unsigned int i = 0; i < string_array.size(); ++i)
    {
        cout << string_array[i] << ' ';
    }
    cout << endl;
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

void GetString(string& string)
{
    cout << "Введите строку чисел: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, string);
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

mylib::dynamic_array<string> SplitString(string input, string delimiter)
{
    mylib::dynamic_array<string> array;
    string temp;

    while (input.find(delimiter) != string::npos)
    {
        temp = input.substr(0, input.find(delimiter));
        array.push_back(temp);
        input.erase(0, input.find(delimiter) + 1);
    }
    array.push_back(input);

    return array;
}

void Convert10ToBaseK(mylib::dynamic_array<string>& array)
{
    unsigned short k = 0;
    cout << "Какое основание для системы хотите выбрать?" << endl << "Ваш выбор: ";
    cin >> k;

    long long num = 0;
    mylib::dynamic_array<unsigned short> digits;
    string temp;
    for (unsigned int i = 0; i < array.size(); ++i)
    {
        num = stol(array[0]);

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
        array.erase(0);
        digits.clear();
        temp.clear();
    }
}
