//Лабораторная работа № 1 - работа с двоичным представлением чисел в памяти ПК
#include <iostream>
#include <climits>
#include <Windows.h>

namespace s // пространство имен s для объединения типов данных для вводимого числа
{
	static union
	{
		short digit;
		float digit_f;
	};
	static union
	{
		int dig_int[2];
		double dig_db;
	};
}

const int NotUsed = system("color 70");

int count_qual = 0; // значение, на которое необходимо изменить заполнение массива
short param_f = 12; // переменная, которая определяет выбранный тип данных
bool format = true;

void SetColor(int text, int bg) //Функция смены цвета, взятая из Интернета
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void mask_digit(const unsigned short qual, int revers_array[])
{
	bool result;
	// делаем слепок числа с помощью побитового сдвига и умножения в цикле
	for (int number_of_bit = 0; number_of_bit < qual - count_qual; number_of_bit++) // номер бита для сдвига, сравниваем номер бита с допустимым значением диапазона массива, добавляем 1 после каждой итерации
	{
		result = s::digit & (1U << number_of_bit); // производим сдвиг числа и записываем бит в переменную
		revers_array[number_of_bit] = result; // записываем в массив полученное значение 
	}
	//std::cout << '\n'; // перевод строки
}

void mask_digit_f(const unsigned short qual, int revers_array[])
{;
	bool result;
	// делаем слепок числа с помощью побитового сдвига и умножения в цикле
	for (int number_of_bit = 0; number_of_bit < 33; number_of_bit++) // номер бита для сдвига, сравниваем номер бита с допустимым значением диапазона массива, добавляем 1 после каждой итерации
	{
		result = s::dig_int[0] & (1U << number_of_bit); // производим сдвиг числа и записываем бит в переменную
		revers_array[number_of_bit] = result; // записываем в массив полученное значение 
	}
	std::cout << '\n'; // перевод строки
	// делаем слепок числа с помощью побитового сдвига и умножения в цикле
	for (int number_of_bit = 33; number_of_bit < 64; number_of_bit++) // номер бита для сдвига, сравниваем номер бита с допустимым значением диапазона массива, добавляем 1 после каждой итерации
	{
		result = s::dig_int[1] & (1U << number_of_bit); // производим сдвиг числа и записываем бит в переменную
		revers_array[number_of_bit] = result; // записываем в массив полученное значение 
	}
}

void print_revers_array(const unsigned short qual, int revers_array[])
{
	std::cout << "Двоичное представление числа: " << '\n';
	bool counter = 0; // значение, которое позволяет контролировать первый значащий разряд числа
	// выводим на экран слепок числа,  перевернув его
	for (int i = qual - 1 - count_qual; i >= 0; i = i - 1) // берем последний бит в допустимом значении диапазона массива, цикл будет проходить до последнего значения бита, снижаем на 1 после каждой итерации
	{
		if (i == qual - 1 - count_qual) // отделяем знак от числа единожды
		{
			std::cout << revers_array[i]; // вывод значения бита
			std::cout << " "; // пробел отделяющий знак числа
		}
		else if (revers_array[i] == 0 and counter == 0) // проверяем выводим бит является ли значащим и вместе с ним равен ли параметр ЛОЖЬ. Необходимо для того, чтобы найти значащие биты и выделить их цветом
		{
			std::cout << revers_array[i]; // вывод значения бита
		}
		else
		{
			counter = 1; // устанавливаем в истину, как только получили первый значащий разряд
			SetColor(3, 7); // устанавливаем цвет шрифта в желтый
			std::cout << revers_array[i]; //вывод значения бита
		}
		if (i % 8 == 0) // отделяем после 8го значения пробелом для удобного восприятия числа
			std::cout << " ";
	}
	SetColor(0, 7); // возвращаем цвет шрифта в белый
}

void print_revers_array_forward(const unsigned short qual, int revers_array[], int leftBorder, int rightBorder)
{
	std::cout << "Двоичное представление числа: " << '\n';
	bool counter = 0; // значение, которое позволяет контролировать первый значащий разряд числа
	// выводим на экран слепок числа,  перевернув его
	for (int i = qual - 1 - count_qual; i >= 0; i = i - 1) // берем последний бит в допустимом значении диапазона массива, цикл будет проходить до последнего значения бита, снижаем на 1 после каждой итерации
	{
		if (i == qual - 1 - count_qual) // отделяем знак от числа единожды
		{
			std::cout << revers_array[i]; // вывод значения бита
			std::cout << " "; // пробел отделяющий знак числа
		}
		else if (i <= (leftBorder) && i >= rightBorder)
		{
			SetColor(4, 7); // устанавливаем цвет шрифта в желтый
			std::cout << revers_array[i]; // вывод значения бита
			SetColor(0, 7);
		}
		else if (revers_array[i] == 0 and counter == 0) // проверяем выводим бит является ли значащим и вместе с ним равен ли параметр ЛОЖЬ. Необходимо для того, чтобы найти значащие биты и выделить их цветом
		{
			std::cout << revers_array[i]; // вывод значения бита
		}
		else
		{
			counter = 1; // устанавливаем в истину, как только получили первый значащий разряд
			SetColor(3, 7); // устанавливаем цвет шрифта в желтый
			std::cout << revers_array[i]; //вывод значения бита
		}
		if (i % 8 == 0) // отделяем после 8го значения пробелом для удобного восприятия числа
			std::cout << " ";
	}
	SetColor(0, 7); // возвращаем цвет шрифта в белый
}

void print_revers_array_db(const unsigned short qual, int revers_array[])
{
	std::cout << "Двоичное представление числа: " << '\n';
	// выводим на экран слепок числа,  перевернув его
	for (int i = qual - 1; i >= 0; i = i - 1) // берем последний бит в допустимом значении диапазона массива, цикл будет проходить до последнего значения бита, снижаем на 1 после каждой итерации
	{
		if (i == qual - 1) // отделяем знак от числа единожды
		{
			std::cout << revers_array[i]; // вывод значения бита
			std::cout << " "; // пробел отделяющий знак числа
		}
		else if (i + param_f > qual - 1) // выделяем первые биты порядка вещественного цветом и выводим. После того, как условие станет ложным - выделяем биты мантиссы другим цветом и выводим 
		{
			SetColor(5, 7);
			std::cout << revers_array[i]; // вывод значения бита
		}
		else
		{
			SetColor(12, 7);
			std::cout << revers_array[i]; //вывод значения бита
		}
		if (i == 52)
			std::cout << " ";
	}
	SetColor(0, 7); // возвращаем цвет шрифта в белый
}

void checkdigit()
{
	while (true)
	{
		// вводим число, которое хотим представить в двоичной форме
		std::cin >> s::digit; // число целое

		if (std::cin.fail()) // ecли предыдущее извелечение оказлось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в обычный режим работы
			std::cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
			std::cout << "Недопустимое заданное число. Введите число правильно" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем из буфера значения предыдущего ввода
			return;
		}
	}
}

void checkdigit_f()
{
	while (true)
	{
		// вводим число, которое хотим представить в двоичной форме
		if (format)
			std::cin >> s::dig_db; // число целое
		else
			std::cin >> s::digit_f;

		if (std::cin.fail()) // ecли предыдущее извелечение оказлось неудачным,
		{
			std::cin.clear(); // то возвращаем cin в обычный режим работы
			std::cin.ignore(32767, '\n'); // и удаляем из буфера значения предыдущего ввода 
			std::cout << "Недопустимое заданное число. Введите число правильно" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // удаляем из буфера значения предыдущего ввода 
			return;
		}
	}
}

bool CheckForward()
{
	bool forward;
	int cinValue;

	while (true)
	{
		bool bIsFind = false;
		std::cin >> cinValue;
		switch (cinValue)
		{
		case 1:
			forward = false;
			bIsFind = true;
			break;
		case 2:
			forward = true;
			bIsFind = true;
			break;
		default:
			std::cout << "\nНекорректное число. Попробуйте снова :\n";
			break;
		}
		if (bIsFind)
			return forward;
	}
}

void InsertBit(bool Container, int BitIndex)
{
	if (Container)
	{
		s::digit |= (1U << BitIndex);
	}
	else
	{
		s::digit &= ~(1U << BitIndex);
	}
}

bool IsPossibleMoveBits(int qual, bool forward, int NumberOlderBit, int CountBits)
{
	if (forward) // right
	{
		if (NumberOlderBit - CountBits + 1 < 0)
		{
			std::cout << "Выбрана слишком большая группа битов относительно направления и старшего бита. Преобразование не будет выполнено.\n";
			return false;
		}
	}
	else // left
	{
		if (NumberOlderBit + CountBits - 1 > qual)
		{
			std::cout << "Выбрана слишком большая группа битов относительно направления и старшего бита. Преобразование не будет выполнено.\n";
			return false;
		}
	}
	if (CountBits <= 1)
	{
		std::cout << "Некорректное количество битов (больше или равно 2). Преобразование не будет выполнено.\n";
		return false;
	}

	return true;
}

void MoveBitsByShiftStep(int revers_array[], int qual, bool forward, int NumberOlderBit, int CountBits, int ShiftStep)
{
	int leftBorder = NumberOlderBit;
	int rightBorder;
	bool bufferBit = false;

	if (!IsPossibleMoveBits(qual, forward, NumberOlderBit, CountBits))
	{
		return;
	}

	if (forward) // right
	{
		leftBorder = NumberOlderBit;
		rightBorder = leftBorder - CountBits + 1;
	}
	else // left
	{
		rightBorder = NumberOlderBit;
		leftBorder = rightBorder + CountBits - 1;
	}

	while (ShiftStep > 0)
	{
		bool stor1, stor2;
		bool flop = true; // 1 stor1 , 0 stor2 
		// записываем первое значение вне цикла

		if (forward)
		{
			bool firstShiftBit = s::digit & (1U << leftBorder);
			stor2 = firstShiftBit;

			for (int i = leftBorder; i >= rightBorder; i--)
			{
				if (i - 1 >= rightBorder)
				{
					//записали значение стоящее справа
					if (flop)
					{
						stor1 = s::digit & (1U << i - 1);
					}
					else
					{
						stor2 = s::digit & (1U << i - 1);
					}
					flop = !flop;

					// записали в правое значение значение из хранилища
					if (flop)
					{
						InsertBit(stor1, i - 1);
					}
					else
					{
						InsertBit(stor2, i - 1);
					}
				}
				else // если дошли до границы
				{
					if (flop)
					{
						InsertBit(stor2, leftBorder);
					}
					else
					{
						InsertBit(stor1, leftBorder);
					}
				}

			}
		}
		else
		{
			bool firstShiftBit = s::digit & (1U << rightBorder);
			stor2 = firstShiftBit;

			for (int i = rightBorder; i <= leftBorder; i++)
			{
				if (i + 1 <= leftBorder)
				{
					//записали значение стоящее справа
					if (flop)
					{
						stor1 = s::digit & (1U << i + 1);
					}
					else
					{
						stor2 = s::digit & (1U << i + 1);
					}
					flop = !flop;

					// записали в правое значение значение из хранилища
					if (flop)
					{
						InsertBit(stor1, i + 1);
					}
					else
					{
						InsertBit(stor2, i + 1);
					}
				}
				else // если дошли до границы
				{
					if (flop)
					{
						InsertBit(stor2, rightBorder);
					}
					else
					{
						InsertBit(stor1, rightBorder);
					}
				}

			}
		}
		std::cout << "\nШаг " << ShiftStep << "\n";
		mask_digit(qual, revers_array); // функция создания слепка числа
		print_revers_array_forward(qual, revers_array, leftBorder, rightBorder); // функция вывода массива полученный значений, перевернув его
		std::cout << "\n";

		ShiftStep--;
	}
}

int main()
{
	setlocale(0, "");

	const unsigned short qual = 64; // обозначает разрядность будущего числа
	int revers_array[qual]; // массив, который хранит слепок числа в перевернутом виде
	int NumberOlderBit;
	int CountBits;
	bool forward;
	int ShiftStep;

	std::cout << "___________________ I ЧАСТЬ - _____________________" << '\n';
	std::cout << "                  Целое число long         " << '\n';
	std::cout << "Введите целое число арабскими цифрами (Пример: 10, -10, 5251, 0): " << '\n';
	checkdigit();
	// выбираем формат значения
	count_qual = 32; // устанавливаем глобальное значение для изменения диапазона массива

	mask_digit(qual, revers_array); // функция создания слепка числа
	print_revers_array(qual, revers_array); // функция вывода массива полученный значений, перевернув его
	std::cout << '\n';

	//MoveBitsByShiftStep(revers_array, qual, true, 5, 3, 2); //right
	//MoveBitsByShiftStep(revers_array, qual, false, 3, 3, 3); //left

	system("pause");

	std::cout << '\n';
	count_qual = 0; // обнуляем значение, на которое необходимо изменить заполнение массива 
	std::cout << "___________________ II ЧАСТЬ - _____________________" << '\n';
	std::cout << "               Вещественное число double          " << '\n';
	std::cout << "Введите неотрицательное вещественное число арабскими цифрами (Пример: 3.14, 15.0, 5251.432, 0.0): " << '\n';

	checkdigit_f();

	mask_digit_f(qual, revers_array); // функция создания слепка числа
	print_revers_array_db(qual, revers_array); // функция вывода массива полученный значений, перевернув его
	std::cout << '\n';

	system("pause");
	std::cout << '\n';
	std::cout << "___________________ III ЧАСТЬ - _____________________" << '\n';
	std::cout << "               Циклический сдвиг        " << '\n';

	std::cout << "Введите число арабскими цифрами: ";
	checkdigit();
	// выбираем формат значения
	count_qual = 32; // устанавливаем глобальное значение для изменения диапазона массива

	mask_digit(qual, revers_array); // функция создания слепка числа
	print_revers_array(qual, revers_array); // функция вывода массива полученный значений, перевернув его
	std::cout << '\n';

	std::cout << "Выберите направление сдвига: " << '\n';
	std::cout << "1. Налево\n";
	std::cout << "2. Направо\n";

	forward = CheckForward();

	std::cout << "Введите номер старшего бита: ";
	std::cin >> NumberOlderBit;
	std::cout << "Введите количество бит, которое необходимо сдвинуть ";
	std::cin >> CountBits;
	std::cout << "Введите шаг сдвига: ";
	std::cin >> ShiftStep;

	MoveBitsByShiftStep(revers_array, qual, forward, NumberOlderBit, CountBits, ShiftStep);

	system("pause");

	return 0;
}
