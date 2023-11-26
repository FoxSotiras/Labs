#include <iostream>
#include <cstring>
#ifndef INT_DYNAMIC_ARRAY_H
#define INT_DYNAMIC_ARRAY_H
struct IntDynamicArray
{
    int* first_element;
    unsigned int last_item_index;
    unsigned int size;
    unsigned const short delta = 10;

    IntDynamicArray()
    {
        first_element = nullptr;
        last_item_index = 0;
        size = 0;
    }

    IntDynamicArray(int len)
    {
        size = len;
        last_item_index = 0;
        first_element = new int[size];
    }

    ~IntDynamicArray()
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

    void remove(int num)
    {
        int temp = last_item_index;
        
        for (int i = 0; i < temp; ++i)
        {
            if (first_element[i] == num)
            {
                std::memcpy(first_element + i, first_element + i + 1, sizeof(int) * (size - i - 1));
                --last_item_index;
                break;
            }
        }
    }

    void remove_all(int num)
    {
        int temp = last_item_index;

        for (int i = 0, j = 0; i <= temp; ++i, ++j)
        {
            if (first_element[j] == num)
            {
                std::memcpy(first_element + j, first_element + j + 1, sizeof(int) * (size - i - 1));
                --last_item_index;
                --j;
            }
        }
    }
};

// struct CharDynamicArray
// {
//     char* first_element;
//     int last_item_index;
//     int size;
//     int delta = 20;

//     CharDynamicArray()
//     {
//         size = 20;
//         last_item_index = 0;
//         first_element = new char[size];
//     }

//     ~CharDynamicArray()
//     {
//         delete[] first_element;
//     }

//     int operator [] (int index)
//     {
//         return first_element[index];
//     }

//     std::istream& operator >> (std::istream& input)
//     {
//         unsigned int input_size = input.gcount();



//         for (last_item_index; last_item_index < input_size; ++last_item_index)
//         {
//             if (last_item_index == size)
//             {
//                 reallocate();
//             }
//             first_element[last_item_index] = ;
//         }

//         return input;
//     }

//     std::ostream& operator << (std::ostream& output)
//     {
//         return output;
//     }

//     void reallocate()
//     {
//         size += delta;
//         char* newArray = new char[size];
//         std::memcpy(newArray, first_element, sizeof(int) * (size - delta));
//         delete[] first_element;
//         first_element = newArray;
//     }

//     void push_back(char symbol)
//     {
//         if (last_item_index == size)
//         {
//             reallocate();
//         }
//         first_element[last_item_index++] = symbol;
//     }

//     void insert(int index, char symbol)
//     {
//         if (last_item_index == size)
//         {
//             reallocate();
//         }
//         std::memcpy(first_element + index + 1, first_element + index, sizeof(int) * (size - index));
//         first_element[index] = symbol;
//         ++last_item_index;
//     }
// };
#endif
