#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <string>
#include <stdexcept>
#include "dynamic_array.h" //my dynamic array in C++, watch https://github.com/FoxSotiras/MyLib-CPP for details
using ushort = unsigned short;
using ullong = unsigned long long;

enum month_type
{
    January = 1, February, March, April, May,
    June, July, August, September, October, November, December
};

struct date
{
    ushort day;
    month_type month;
    ushort year;
};

struct Student
{
    ushort mark;
    ullong mark_book_number;
    std::wstring group_number;
    std::wstring subject_name;
    date mark_date;
    std::wstring teacher_surname;
};

bool print_result();
bool isEmpty(mylib::dynamic_array<Student>& array);
void printStudent(mylib::dynamic_array<Student>& array, ullong index);
void help();
void add(mylib::dynamic_array<Student>& array, bool result);
void print(mylib::dynamic_array<Student>& array, bool result);
void print_number(mylib::dynamic_array<Student>& array, bool result);
void sort(mylib::dynamic_array<Student>& array, bool result);
mylib::dynamic_array<Student> create_marks(mylib::dynamic_array<Student>& array);

int main()
{
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    std::wstring input;
    mylib::dynamic_array<Student> group;
    bool run = true;
    bool result;

    std::wcout << L"Приветствуем вас в этой замечательной программе!" << std::endl;
    std::wcout << L"Для вывода списка команд введите help." << std::endl;
    while (run)
    {
        result = false;
        std::getline(std::wcin >> std::ws, input);
        if (input == L"exit")
        {
            std::wcout << L"До свидания!" << std::endl;
            run = false;
        }
        else if (input == L"help")
        {
            help();
        }
        else if (input == L"add")
        {
            result = print_result();
            add(group, result);
        }
        else if (input == L"print")
        {
            print(group, result);
        }
        else if (input == L"print_number")
        {
            print_number(group, result);
        }
        else if (input == L"sort")
        {
            result = print_result();
            sort(group, result);
        }
        else if (input == L"create_marks")
        {
            create_marks(group);
        }
        else
        {
            std::wcout << L"Такая команда не найдена, повторите попытку." << std::endl;
        }
    }

    return 0;
}

bool print_result()
{
    bool flag;
    std::wstring input;
    std::wcout << L"Выводить результат выполнения комманды? (Да/Нет)" << std::endl;
    loop:
        std::wcin >> input;
        if (input == L"Да" || input == L"да" || input == L"д")
        {
            flag = true;
        }
        else if (input == L"Нет" || input == L"нет" || input == L"н")
        {
            flag = false;
        }
        else
        {
            std::wcout << "Введите Да/Нет" << std::endl;
            goto loop;
        }
    return flag;
}

bool isEmpty(mylib::dynamic_array<Student>& array)
{
    if (array.size() == 0)
    {
        std::wcout << L"Нет ни одной записи о студентах. Чтобы добавить, введите команду add." << std::endl;
        std::wcout << L"Возвращение на главную страницу." << std::endl;
        return true;
    }
}

void printStudent(mylib::dynamic_array<Student>& array, ullong index)
{
    std::wcout << index + 1 << L". Номер зачётной книжки: ";
    std::wcout << array[index].mark_book_number << std::endl;
    std::wcout << L"   Номер группы: ";
    std::wcout << array[index].group_number << std::endl;
    std::wcout << L"   Название дисциплины: ";
    std::wcout << array[index].subject_name << std::endl;
    std::wcout << L"   Дата получения оценки: ";
    std::wcout << array[index].mark_date.day << L'.' << array[index].mark_date.month
    << L'.' << array[index].mark_date.year << std::endl;
    std::wcout << L"   Оценка: ";
    std::wcout << array[index].mark << std::endl;
    std::wcout << L"   Фамилия преподавателя: ";
    std::wcout << array[index].teacher_surname << std::endl;
}

void help()
{
    std::wcout << L"Список основных команд программы:" << std::endl;
    std::wcout << L"     help               Вывод основных команд" << std::endl;
    std::wcout << L"     exit               Выход из программы" << std::endl;
    std::wcout << L"     add                Добавление записи о студенте" << std::endl;
    std::wcout << L"     print              Вывод всех записей о студентах" << std::endl;
    std::wcout << L"     print_number       Вывод записи об определенном студенте" << std::endl;
    std::wcout << L"     sort               Сортировка всех записей по дисциплинам" << std::endl;
    std::wcout << L"     create_marks       Сформировать ведомость оценок по дисциплине." << std::endl;
    std::wcout << L"Возвращение на главную страницу." << std::endl;
}

void add(mylib::dynamic_array<Student>& array, bool result)
{
    Student templ;
    ushort month;

    std::wcout << L"Заполните основную информацию о студенте." << std::endl;
    std::wcout << L"Номер зачётной книжки: ";
    std::wcin >> templ.mark_book_number;
    std::wcout << L"Номер группы: ";
    std::getline(std::wcin >> std::ws, templ.group_number);
    std::wcout << L"Название дисциплины: ";
    std::getline(std::wcin >> std::ws, templ.subject_name);
    std::wcout << L"Дата получения оценки: " << std::endl;
    std::wcout << L"Год: ";
    std::wcin >> templ.mark_date.year;
    std::wcout << L"Месяц: ";
    std::wcin >> month;
    templ.mark_date.month = static_cast<month_type>(month);
    std::wcout << L"День: ";
    std::wcin >> templ.mark_date.day;
    std::wcout << L"Оценка: ";
    std::wcin >> templ.mark;
    std::wcout << L"Фамилия преподавателя: ";
    std::getline(std::wcin >> std::ws, templ.teacher_surname);

    array.push_back(templ);
    if (result)
    {
        std::wcout << std::endl << L"Создана запись о студенте." << std::endl;
        printStudent(array, array.size() - 1);
    }

    std::wcout << L"Возвращение на главную страницу." << std::endl;
}

void print(mylib::dynamic_array<Student>& array, bool result)
{
    if (isEmpty)
    {
        return;
    }

    for (ullong i = 0; i < array.size(); ++i)
    {
        printStudent(array, i);
    }

    std::wcout << L"Возвращение на главную страницу." << std::endl;
}

void print_number(mylib::dynamic_array<Student>& array, bool result)
{
    if (isEmpty)
    {
        return;
    }

    ullong number;
    ullong index = 0;
    bool is_found = false;
    std::wcout << L"Введите номер зачётной книжки: ";
    found_number:
        std::wcin >> number;
        for (ullong i = 0; i < array.size(); ++i)
        { 
            if (number == array[i].mark_book_number)
            {
                is_found = true;
            }
        }

    if (is_found == false)
    {
        goto found_number;
    }

    printStudent(array, index);

    std::wcout << L"Возвращение на главную страницу." << std::endl;
}

void sort(mylib::dynamic_array<Student>& array, bool result)
{
    if (isEmpty)
    {
        return;
    }

    std::wstring subject;
    Student elem;

    for (ullong i = 1, j = 0; i < array.size(); i++) {
        elem = array[i];
        subject = array[i].subject_name;
        j = i - 1;

        while (j >= 0 && array[j].subject_name >= subject) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = elem;
    }

    if (result)
    {
        std::wcout << L"Отсортированный записи о студентах:" << std::endl;
        for (ullong i = 0; i < array.size(); ++i)
        {
            printStudent(array, i);
        }
    }

    std::wcout << L"Возвращение на главную страницу." << std::endl;
}

mylib::dynamic_array<Student> create_marks(mylib::dynamic_array<Student>& array)
{
    if (isEmpty)
    {
        return;
    }

    mylib::dynamic_array<Student> marks;
    std::wstring subject;

    bool is_found = false;
    std::wcout << L"Введите название дисциплины: ";
    found_subject:
        std::wcin >> subject;
        for (ullong i = 0; i < array.size(); ++i)
        { 
            if (subject == array[i].subject_name)
            {
                is_found = true;
            }
        }

    if (is_found == false)
    {
        std::wcout << L"Такая дисциплина не найдена, попробуйте снова." << std::endl;
        goto found_subject;
    }

    for (ullong i = 0; i < array.size(); ++i)
    {
        if (array[i].subject_name == subject)
        {
            marks.push_back(array[i]);
        }
    }

    for (ullong i = 0; i < marks.size(); ++i)
    {
        printStudent(marks, i);
    }
}
