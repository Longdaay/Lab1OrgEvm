//������������ ������ � 1 - ������ � �������� �������������� ����� � ������ ��
#include <iostream>
#include <climits>
#include <Windows.h>

namespace s // ������������ ���� s ��� ����������� ����� ������ ��� ��������� �����
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

int count_qual = 0; // ��������, �� ������� ���������� �������� ���������� �������
short param_f = 12; // ����������, ������� ���������� ��������� ��� ������
bool format = true;

void SetColor(int text, int bg) //������� ����� �����, ������ �� ���������
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));
}

void mask_digit(const unsigned short qual, int revers_array[], int number_of_bit)
{
	bool result;
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (number_of_bit; number_of_bit < qual - count_qual; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::digit & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	std::cout << '\n'; // ������� ������
}

void mask_digit_f(const unsigned short qual, int revers_array[], int number_of_bit)
{;
	bool result;
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (number_of_bit; number_of_bit < 33; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::dig_int[0] & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	std::cout << '\n'; // ������� ������
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (number_of_bit = 33; number_of_bit < 64; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::dig_int[1] & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
}

void print_revers_array(const unsigned short qual, int revers_array[])
{
	std::cout << "�������� ������������� �����: " << '\n' << '\n';
	bool counter = 0; // ��������, ������� ��������� �������������� ������ �������� ������ �����
	// ������� �� ����� ������ �����,  ���������� ���
	for (int i = qual - 1 - count_qual; i >= 0; i = i - 1) // ����� ��������� ��� � ���������� �������� ��������� �������, ���� ����� ��������� �� ���������� �������� ����, ������� �� 1 ����� ������ ��������
	{
		if (i == qual - 1 - count_qual) // �������� ���� �� ����� ��������
		{
			std::cout << revers_array[i]; // ����� �������� ����
			std::cout << " "; // ������ ���������� ���� �����
		}
		else if (revers_array[i] == 0 and counter == 0) // ��������� ������� ��� �������� �� �������� � ������ � ��� ����� �� �������� ����. ���������� ��� ����, ����� ����� �������� ���� � �������� �� ������
		{
			std::cout << revers_array[i]; // ����� �������� ����
		}
		else
		{
			counter = 1; // ������������� � ������, ��� ������ �������� ������ �������� ������
			SetColor(3, 7); // ������������� ���� ������ � ������
			std::cout << revers_array[i]; //����� �������� ����
		}
		if (i % 8 == 0) // �������� ����� 8�� �������� �������� ��� �������� ���������� �����
			std::cout << " ";
	}
	SetColor(0, 7); // ���������� ���� ������ � �����
}

void print_revers_array_db(const unsigned short qual, int revers_array[])
{
	std::cout << "�������� ������������� �����: " << '\n' << '\n';
	// ������� �� ����� ������ �����,  ���������� ���
	for (int i = qual - 1; i >= 0; i = i - 1) // ����� ��������� ��� � ���������� �������� ��������� �������, ���� ����� ��������� �� ���������� �������� ����, ������� �� 1 ����� ������ ��������
	{
		if (i == qual - 1) // �������� ���� �� ����� ��������
		{
			std::cout << revers_array[i]; // ����� �������� ����
			std::cout << " "; // ������ ���������� ���� �����
		}
		else if (i + param_f > qual - 1) // �������� ������ ���� ������� ������������� ������ � �������. ����� ����, ��� ������� ������ ������ - �������� ���� �������� ������ ������ � ������� 
		{
			SetColor(5, 7);
			std::cout << revers_array[i]; // ����� �������� ����
		}
		else
		{
			SetColor(12, 7);
			std::cout << revers_array[i]; //����� �������� ����
		}
		if (i == 52)
			std::cout << " ";
	}
	SetColor(0, 7); // ���������� ���� ������ � �����
}

void checkdigit()
{
	while (true)
	{
		// ������ �����, ������� ����� ����������� � �������� �����
		std::cin >> s::digit; // ����� �����

		if (std::cin.fail()) // ec�� ���������� ����������� �������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � ������� ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
			std::cout << "������������ �������� �����. ������� ����� ���������" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ������� �� ������ �������� ����������� �����
			return;
		}
	}
}

void checkdigit_f()
{
	while (true)
	{
		// ������ �����, ������� ����� ����������� � �������� �����
		if (format)
			std::cin >> s::dig_db; // ����� �����
		else
			std::cin >> s::digit_f;

		if (std::cin.fail()) // ec�� ���������� ����������� �������� ���������,
		{
			std::cin.clear(); // �� ���������� cin � ������� ����� ������
			std::cin.ignore(32767, '\n'); // � ������� �� ������ �������� ����������� ����� 
			std::cout << "������������ �������� �����. ������� ����� ���������" << '\n';
		}
		else
		{
			std::cin.ignore(32767, '\n'); // ������� �� ������ �������� ����������� ����� 
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
			forward = true;
			bIsFind = true;
			break;
		case 2:
			forward = false;
			bIsFind = true;
			break;
		default:
			std::cout << "\n������������ �����. ���������� ����� :\n";
			break;
		}
		if (bIsFind)
			return forward;
	}
}

void MoveBitsByShiftStep(int revers_array[], bool forward, int NumberOlderBit, int CountBits, int ShiftStep)
{

}

int main()
{
	setlocale(0, "");

	int number_of_bit = 0; // ����� ����, ������� ���������� �����
	const unsigned short qual = 64; // ���������� ����������� �������� �����
	int revers_array[qual]; // ������, ������� ������ ������ ����� � ������������ ����
	int NumberOlderBit;
	int CountBits;
	bool forward;
	int ShiftStep;

	std::cout << "___________________ I ����� - _____________________" << '\n';
	std::cout << "                  ����� ����� long         " << '\n';
	std::cout << "������� ����� ����� ��������� ������� (������: 10, -10, 5251, 0): " << '\n';
	checkdigit();
	// �������� ������ ��������
	count_qual = 32; // ������������� ���������� �������� ��� ��������� ��������� �������

	mask_digit(qual, revers_array, number_of_bit); // ������� �������� ������ �����
	print_revers_array(qual, revers_array); // ������� ������ ������� ���������� ��������, ���������� ���
	std::cout << '\n';

	system("pause");


	count_qual = 0; // �������� ��������, �� ������� ���������� �������� ���������� ������� 
	std::cout << "___________________ II ����� - _____________________" << '\n';
	std::cout << "               ������������ ����� double          " << '\n';
	std::cout << "������� ��������������� ������������ ����� ��������� ������� (������: 3.14, 15.0, 5251.432, 0.0): " << '\n';

	checkdigit_f();

	mask_digit_f(qual, revers_array, number_of_bit); // ������� �������� ������ �����
	print_revers_array_db(qual, revers_array); // ������� ������ ������� ���������� ��������, ���������� ���
	std::cout << '\n';

	system("pause");

	std::cout << "___________________ III ����� - _____________________" << '\n';
	std::cout << "               ����������� �����        " << '\n';
	std::cout << "�������� ����������� ������: " << '\n';
	std::cout << "1. ������\n";
	std::cout << "2. �������\n";

	forward = CheckForward();

	std::cout << "������� ����� �������� ����: ";
	std::cin >> NumberOlderBit;
	std::cout << "������� ���������� ���, ������� ���������� �������� ";
	std::cin >> CountBits;
	std::cout << "������� ��� ������: ";
	std::cin >> ShiftStep;

	MoveBitsByShiftStep(revers_array, forward, NumberOlderBit, CountBits, ShiftStep);

	return 0;
}
