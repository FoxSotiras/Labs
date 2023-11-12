#include <cstring>
#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
struct DynamicArray
{
    int* first_element;
    int last_item_index;
    int size;
    int delta = 10;

    DynamicArray()
    {
        first_element = nullptr;
        last_item_index = 0;
        size = 0;
    }

    DynamicArray(int len)
    {
        size = len;
        last_item_index = 0;
        first_element = new int[size];
    }

    ~DynamicArray()
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
        int* newArray = new int[size];
        std::memcpy(newArray, first_element, sizeof(int) * (size - delta));
        delete[] first_element;
        first_element = newArray;
    }

    void push_back(int num)
    {
        if (last_item_index == size)
        {
            reallocate();
        }
        first_element[last_item_index++] = num;
    }

    void insert(int index, int num)
    {
        if (last_item_index == size)
        {
            reallocate();
        }
        std::memcpy(first_element + index + 1, first_element + index, sizeof(int) * (size - index));
        first_element[index] = num;
        ++last_item_index;
    }
};
#endif
