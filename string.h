#include <iostream>
#include <cstring>
#include "int_dynamic_array.h"
#ifndef STRING_H
#define STRING_H

struct String
{
    char* first_element;
    unsigned int last_item_index;
    unsigned int size;
    unsigned const short delta = 512;

    String()
    {
        size = 512;
        last_item_index = 0;
        first_element = new char[size];
    }

    ~String()
    {
        delete[] first_element;
    }

    int operator [] (int index)
    {
        return first_element[index];
    }

    void reallocate()
    {
        size += delta;
        char* newArray = new char[size];
        std::memcpy(newArray, first_element, sizeof(char) * (size - delta));
        delete[] first_element;
        first_element = newArray;
    }

    void push_back(char symbol)
    {
        if (last_item_index == size)
        {
            reallocate();
        }
        first_element[last_item_index++] = symbol;
    }

    void insert(int index, char symbol)
    {
        if (last_item_index == size)
        {
            reallocate();
        }
        std::memcpy(first_element + index + 1, first_element + index, sizeof(char) * (size - index));
        first_element[index] = symbol;
        ++last_item_index;
    }

    void remove(char symbol)
    {
        int temp = last_item_index;

        for (int i = 0; i <= temp; ++i)
        {
            if (first_element[i] == symbol)
            {
                std::memcpy(first_element + i, first_element + i + 1, sizeof(char) * (size - i - 1));
                --last_item_index;
                break;
            }
        }
    }

    void remove_all(char symbol)
    {
        int temp = last_item_index;

        for (int i = 0, j = 0; i <= temp; ++i, ++j)
        {
            if (first_element[j] == symbol)
            {
                std::memcpy(first_element + j, first_element + j + 1, sizeof(char) * (size - i - 1));
                --last_item_index;
                --j;
            }
        }
    }

    int find(char symbol)
    {
        for (int i = 0; i <= last_item_index; ++i)
        {
            if (first_element[i] == symbol)
            {
                return i;
                break;
            }
        }
    }

    IntDynamicArray* find_all(char symbol)
    {
        IntDynamicArray* array = new IntDynamicArray();

        for (int i = 0; i <= last_item_index; ++i)
        {
            if (first_element[i] == symbol)
            {
                array->push_back(i);
            }
        }

        return array;
    }
};
#endif
