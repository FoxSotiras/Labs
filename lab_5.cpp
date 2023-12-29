#include <iostream>
#include <random>
#include <fstream>
#include <cstdlib>
using llong = long long;
using ullong = unsigned llong;
using ushort = unsigned short;

ushort delta = 10;

void prog1();
void prog2();
void prog3();
void prog4();
bool isSymmetric(ullong* row, ullong m);
void moveSymmetricRows(ullong** matrix, ullong n, ullong m);
ullong sumBelowSecondaryDiagonal(char** matrix, ullong size);
void IsKnightBeatQueen(char chessboard[8][8]);

int main()
{
    setlocale(LC_ALL, "RU");

    int task = 0;
	std::cout << "Какую задачу вы хотите решить(1, 2, 3, 4)?: ";
	std::cin >> task;

	switch (task)
	{
        case 1:
            prog1();
            break;
        case 2:
            prog2();
            break;
        case 3:
            prog3();
            break;
        case 4:
            prog4();
            break;
        default:
            std::cout << "Введите числа от 1 до 4." << std::endl;
            break;
	}


    return 0;
}

void prog1()
{
    ullong n = 0, m = 0;
    std::cout << "Введите размер двумерного массива n*m:" << std::endl;
    std::cout << "Введите n: ";
    std::cin >> n;
    std::cout << "Введите m: ";
    std::cin >> m;
    ullong** matrix = new ullong*[n+delta];
    for (ullong i = 0; i < n; ++i)
    {
        matrix[i] = new ullong[m+delta];
    }

    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, 100);
    for (ullong i = 0; i < n; ++i)
    {
        for (ullong j = 0; j < m; ++j)
        {
            matrix[i][j] = dist(rd);
        }
    }

    moveSymmetricRows(matrix, n, m);
    for (ullong i = 0; i < n; ++i) {
        for (ullong j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void prog2()
{
    ullong size = 0;
    std::cout << "Введите размер квадратной матрицы символов: " << std::endl;
    std::cout << "Введите size: ";
    std::cin >> size;
    char** matrix = new char*[size+delta];
    for (ullong i = 0; i < size; ++i)
    {
        matrix[i] = new char[size+delta];
    }

    std::random_device rd;
    std::uniform_int_distribution<ushort> dist(33, 127);
    for (ullong i = 0; i < size; ++i)
    {
        for (ullong j = 0; j < size; ++j)
        {
            matrix[i][j] = dist(rd);
        }
    }

    for (ullong i = 0; i < size; ++i) {
        for (ullong j = 0; j < size; ++j) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    ullong sum = sumBelowSecondaryDiagonal(matrix, size);
    std::cout << "Сумма чисел под побочной диагональю: " << sum << std::endl;
}

void prog3()
{
    char position[2], chessboard[8][8];
    std::cout << "Введите координаты коня: ";
    std::cin >> position;
    chessboard[position[0] - 'a'][8 - (position[1] - '0')] = 'N';

    std::cout << "Введите координаты ферзя: ";
    std::cin >> position;
    chessboard[position[0] - 'a'][8 - (position[1] - '0')] = 'Q';

    IsKnightBeatQueen(chessboard);
}

void prog4()
{
    std::string filename;
    std::cout << "Введите имя файла: ";
    std::getline(std::cin >> std::ws, filename);

    std::ifstream sourceFile(filename, std::ios::binary);
    std::string backupFilename = filename + ".bak";
    std::ofstream backupFile(backupFilename, std::ios::binary);
    backupFile << sourceFile.rdbuf();
    sourceFile.close();
    backupFile.close();

    std::cout << "Резервная копия файла создана успешно." << std::endl;
}

bool isSymmetric(ullong* row, ullong m)
{
    for (ullong i = 0; i < m / 2; ++i) 
    {
        if (row[i] != row[m - 1 - i])
        {
            return false;
        }
    }

    return true;
}

void moveSymmetricRows(ullong** matrix, ullong n, ullong m) {
    ullong symmetricRows = 0;

    for (ullong i = 0; i < n; ++i) {
        if (isSymmetric(matrix[i], m)) {
            std::swap(matrix[i], matrix[symmetricRows]);
            ++symmetricRows;
        }
    }
}

ullong sumBelowSecondaryDiagonal(char** matrix, ullong size) {
    ullong sum = 0;

    for (ullong i = 0; i < size; ++i) {
        for (ullong j = 0; j < size; ++j) {
            if (i + j > size - 1) {
                if (matrix[i][j] >= '0' && matrix[i][j] <= '9') {
                    sum += matrix[i][j] - '0';
                }
            }
        }
    }

    return sum;
}

void IsKnightBeatQueen(char chessboard[8][8])
{
    for (ushort i = 0; i < 8; ++i)
    {
        for (ushort j = 0; j < 8; ++j)
        {
            if (chessboard[j][i] == 'N')
            {
                if (chessboard[j + 2][i + 1] == 'Q' || chessboard[j + 1][i + 2] == 'Q' ||
                chessboard[j - 1][i + 2] == 'Q' || chessboard[j + 1][i - 2] == 'Q' ||
                chessboard[j - 1][i - 2] == 'Q' || chessboard[j - 2][i + 1] == 'Q' ||
                chessboard[j - 2][i - 1] == 'Q' || chessboard[j + 2][i - 1] == 'Q')
                {
                    std::cout << "Конь бьет ферзя." << std::endl;
                }
                else
                {
                    std::cout << "Конь не бьет ферзя." << std::endl;
                }
            }
        }
    }
}
