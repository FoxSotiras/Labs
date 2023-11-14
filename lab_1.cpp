#include <iostream>
#include <cmath>

const double Pi = 3.1416;
const double min = 0;
const double max = 3 * Pi;
const double step = 0.1;

double circle(double x, double y);
void trigFor();
void trigWhile();
void trigDoWhile();
void prog1();
void prog2();
void prog3();

int main()
{
	int task = 0;
	std::cout << "Какую задачу вы хотите решить(1, 2, 3)?: ";
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
        default:
            break;
	}
}

double circle(double x, double y)
{
	return x * x + y * y;
}

void trigFor() {
	double y = 0;

	for (double x = min; x <= max; x += step)
	{
		y = cos(x);
		std::cout << "Значение x: " << x << std::endl;
		std::cout << "Значение y: " << y << std::endl;
	}
}

void trigWhile() {
	double x = min, y = 0;

	while (x <= max)
	{
		y = cos(x);
		std::cout << "Значение x: " << x << std::endl;
		std::cout << "Значение y: " << y << std::endl;
		x += step;
	}
}

void trigDoWhile() {
	double x = min, y = 0;

	do
	{
		y = cos(x);
		std::cout << "Значение x: " << x << std::endl;
		std::cout << "Значение y: " << y << std::endl;
		x += step;
	} while (x <= max);
}

void prog1()
{
	double x = 0;
	std::cout << "Введите x: ";
	std::cin >> x;

	double y = sqrt((2 * x + sin(fabs(3 * x)) + tan(x)) / 10);
	std::cout << "Значение x: " << x << std::endl;
	std::cout << "Значение y: " << y << std::endl;
}

void prog2()
{
	double x = 0, y = 0, r = 1;
	std::cout << "Введите x: ";
	std::cin >> x;
	std::cout << "Введите y: ";
	std::cin >> y;

	if (x < 0 && y > 0 && circle(x, y) < r * r)
	{
		std::cout << "Входит";
	}
	else if (x < 0 && y < x && circle(x, y) < r * r)
	{
		std::cout << "Входит";
	}
	else if (x > 0 && y > x && circle(x, y) < r * r)
	{
		std::cout << "Входит";
	}
	else if (x > 0 && y < x && circle(x, y) > r * r)
	{
		std::cout << "Входит";
	}
	else
	{
		std::cout << "Не входит";
	}
}

void prog3()
{
	int method = 0;
	std::cout << "Выберите способ решения задачи(1 - for, 2 - while, 3 - do while): ";
	std::cin >> method;

	switch (method)
	{
	case 1:
		trigFor();
		break;
	case 2:
		trigWhile();
		break;
	case 3:
		trigDoWhile();
		break;
	default:
		break;
	}
}
