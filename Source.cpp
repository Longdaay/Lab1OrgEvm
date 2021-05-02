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

void mask_digit(const unsigned short qual, int revers_array[])
{
	bool result;
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (int number_of_bit = 0; number_of_bit < qual - count_qual; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::digit & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	//std::cout << '\n'; // ������� ������
}

void mask_digit_f(const unsigned short qual, int revers_array[])
{;
	bool result;
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (int number_of_bit = 0; number_of_bit < 33; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::dig_int[0] & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
	std::cout << '\n'; // ������� ������
	// ������ ������ ����� � ������� ���������� ������ � ��������� � �����
	for (int number_of_bit = 33; number_of_bit < 64; number_of_bit++) // ����� ���� ��� ������, ���������� ����� ���� � ���������� ��������� ��������� �������, ��������� 1 ����� ������ ��������
	{
		result = s::dig_int[1] & (1U << number_of_bit); // ���������� ����� ����� � ���������� ��� � ����������
		revers_array[number_of_bit] = result; // ���������� � ������ ���������� �������� 
	}
}

void print_revers_array(const unsigned short qual, int revers_array[])
{
	std::cout << "�������� ������������� �����: " << '\n';
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

void print_revers_array_forward(const unsigned short qual, int revers_array[], int leftBorder, int rightBorder)
{
	std::cout << "�������� ������������� �����: " << '\n';
	bool counter = 0; // ��������, ������� ��������� �������������� ������ �������� ������ �����
	// ������� �� ����� ������ �����,  ���������� ���
	for (int i = qual - 1 - count_qual; i >= 0; i = i - 1) // ����� ��������� ��� � ���������� �������� ��������� �������, ���� ����� ��������� �� ���������� �������� ����, ������� �� 1 ����� ������ ��������
	{
		if (i == qual - 1 - count_qual) // �������� ���� �� ����� ��������
		{
			std::cout << revers_array[i]; // ����� �������� ����
			std::cout << " "; // ������ ���������� ���� �����
		}
		else if (i <= (leftBorder) && i >= rightBorder)
		{
			SetColor(4, 7); // ������������� ���� ������ � ������
			std::cout << revers_array[i]; // ����� �������� ����
			SetColor(0, 7);
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
	std::cout << "�������� ������������� �����: " << '\n';
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
			forward = false;
			bIsFind = true;
			break;
		case 2:
			forward = true;
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
			std::cout << "������� ������� ������� ������ ����� ������������ ����������� � �������� ����. �������������� �� ����� ���������.\n";
			return false;
		}
	}
	else // left
	{
		if (NumberOlderBit + CountBits - 1 > qual)
		{
			std::cout << "������� ������� ������� ������ ����� ������������ ����������� � �������� ����. �������������� �� ����� ���������.\n";
			return false;
		}
	}
	if (CountBits <= 1)
	{
		std::cout << "������������ ���������� ����� (������ ��� ����� 2). �������������� �� ����� ���������.\n";
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
		// ���������� ������ �������� ��� �����

		if (forward)
		{
			bool firstShiftBit = s::digit & (1U << leftBorder);
			stor2 = firstShiftBit;

			for (int i = leftBorder; i >= rightBorder; i--)
			{
				if (i - 1 >= rightBorder)
				{
					//�������� �������� ������� ������
					if (flop)
					{
						stor1 = s::digit & (1U << i - 1);
					}
					else
					{
						stor2 = s::digit & (1U << i - 1);
					}
					flop = !flop;

					// �������� � ������ �������� �������� �� ���������
					if (flop)
					{
						InsertBit(stor1, i - 1);
					}
					else
					{
						InsertBit(stor2, i - 1);
					}
				}
				else // ���� ����� �� �������
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
					//�������� �������� ������� ������
					if (flop)
					{
						stor1 = s::digit & (1U << i + 1);
					}
					else
					{
						stor2 = s::digit & (1U << i + 1);
					}
					flop = !flop;

					// �������� � ������ �������� �������� �� ���������
					if (flop)
					{
						InsertBit(stor1, i + 1);
					}
					else
					{
						InsertBit(stor2, i + 1);
					}
				}
				else // ���� ����� �� �������
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
		std::cout << "\n��� " << ShiftStep << "\n";
		mask_digit(qual, revers_array); // ������� �������� ������ �����
		print_revers_array_forward(qual, revers_array, leftBorder, rightBorder); // ������� ������ ������� ���������� ��������, ���������� ���
		std::cout << "\n";

		ShiftStep--;
	}
}

int main()
{
	setlocale(0, "");

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

	mask_digit(qual, revers_array); // ������� �������� ������ �����
	print_revers_array(qual, revers_array); // ������� ������ ������� ���������� ��������, ���������� ���
	std::cout << '\n';

	//MoveBitsByShiftStep(revers_array, qual, true, 5, 3, 2); //right
	//MoveBitsByShiftStep(revers_array, qual, false, 3, 3, 3); //left

	system("pause");

	std::cout << '\n';
	count_qual = 0; // �������� ��������, �� ������� ���������� �������� ���������� ������� 
	std::cout << "___________________ II ����� - _____________________" << '\n';
	std::cout << "               ������������ ����� double          " << '\n';
	std::cout << "������� ��������������� ������������ ����� ��������� ������� (������: 3.14, 15.0, 5251.432, 0.0): " << '\n';

	checkdigit_f();

	mask_digit_f(qual, revers_array); // ������� �������� ������ �����
	print_revers_array_db(qual, revers_array); // ������� ������ ������� ���������� ��������, ���������� ���
	std::cout << '\n';

	system("pause");
	std::cout << '\n';
	std::cout << "___________________ III ����� - _____________________" << '\n';
	std::cout << "               ����������� �����        " << '\n';

	std::cout << "������� ����� ��������� �������: ";
	checkdigit();
	// �������� ������ ��������
	count_qual = 32; // ������������� ���������� �������� ��� ��������� ��������� �������

	mask_digit(qual, revers_array); // ������� �������� ������ �����
	print_revers_array(qual, revers_array); // ������� ������ ������� ���������� ��������, ���������� ���
	std::cout << '\n';

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

	MoveBitsByShiftStep(revers_array, qual, forward, NumberOlderBit, CountBits, ShiftStep);

	system("pause");

	return 0;
}
