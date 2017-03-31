#include <stdio.h>

void Ex01();
void Ex02();
void Ex03();
void Ex04_01();
void Ex04_02();
void Ex04_03();
void Select(int select);
void Grade(int score);
void Sum();
void LeapYear(int year);
void Pyramid(int height);
void GuGuStairs(int start, int last);
void GuGuThree(int start, int last);

void main()
{
	int iselect;

	while (1)
	{
		printf("--------------------------- ���� ���� ��� --------------------------\r\n\n");

		printf("0.���� ��         1.���� 1          2.���� 2          3.���� 3 \r\n");
		printf("4.���� 4-1        5.���� 4-2        6.���� 4-3     "), scanf_s("%i", &iselect), printf("\r\n");

		printf("--------------------------------------------------------------------\r\n\n");

		if (1 <= iselect && iselect <= 6)
			Select(iselect);

		else if (iselect == 0)
			break;

		else
		{
			printf("��ȣ�� �߸� �Է� �ϼ̽��ϴ�!!\r\n");
			printf("�ٽ� �Է��� �ּ���.\r\n\n");
			continue;
		}
	}
}

void Select(int iselect)
{
	switch (iselect)
	{
	case 1:
		Ex01();
		break;
	case 2:
		Ex02();
		break;
	case 3:
		Ex03();
		break;
	case 4:
		Ex04_01();
		break;
	case 5:
		Ex04_02();
		break;
	case 6:
		Ex04_03();
		break;
	default:
		break;
	}
}

void Ex01() // 1�� ���� -> ���� ���
{
	int score;

	printf("���� �Է�(-1���� ��) : "), scanf_s("%i", &score), printf("\r\n");

	while (1)
	{
		printf("���� "), Grade(score);

		printf("--------------------------------------------------------------------\r\n\n");

		printf("���� �Է�(-1���� ��) : "), scanf_s("%i", &score), printf("\r\n");

		if (score == -1)
			break;
	}
}
void Grade(int score)
{
	if (100 >= score && score >= 0)
	{
		if (100 >= score && score > 90)
			printf(": A \r\n\n");

		else if (90 >= score && score > 80)
			printf(": B \r\n\n");

		else if (80 >= score && score > 70)
			printf(": C \r\n\n");

		else if (70 >= score && score > 60)
			printf(": D \r\n\n");

		else
			printf(": F \r\n\n");
	}
	else
	{
		printf("������ �߸� �Է��ϼ̽��ϴ�! \r\n\n");
	}
}

void Ex02() // 2�� ���� -> 2, 3, 5, 7�� ���� �Ҽ� ���
{
	printf("2, 3, 5, 7 �� ���� ��Ÿ���� �Ҽ��� 100���� ��� \r\n\n");

	Sum();
}
void Sum()
{
	int inum, idiv_2, idiv_3, idiv_5, idiv_7, icount = 0;

	for (int i = 2; i <= 100; ++i)
	{
		idiv_2 = i % 2, idiv_3 = i % 3,
			idiv_5 = i % 5, idiv_7 = i % 7;

		if ((idiv_2 != 0 && idiv_3 != 0 &&
			idiv_5 != 0 && idiv_7 != 0) || (i == 2 || i == 3 || i == 5 || i == 7))
		{
			printf("%i\t", i);
			icount++;
		}

		if (icount == 5)
		{
			printf("\r\n");
			icount = 0;
		}
	}
	printf("\r\n");
}

void Ex03() // 3�� ���� -> ���� ����
{
	int year;

	printf("----- ���� ���� -----\r\n\n");

	printf("�˻��� ������ �Է��ϼ��� (1900 ~ 9999��) : "), scanf_s("%i", &year), printf("\r\n");

	while (1)
	{
		if (1900 <= year && year <= 9999)
		{
			LeapYear(year);
			break;
		}
		else
		{
			printf("--------------------------------------------------------------------\r\n\n");
			printf("������ �ٽ� �Է��� �ּ��� (1900 ~ 9999��)\r\n\n");
			printf("�˻��� ������ �Է��ϼ��� : "), scanf_s("%i", &year), printf("\r\n");
		}
	}
}
void LeapYear(int year)
{
	printf("--------------------------------------------------------------------\r\n\n");

	int first = 1897;

	while (first <= year)
	{
		for (int count = 1; first <= year; ++first)
		{
			if (count == 4 && first == year)
				printf("[ %i ]���� �����Դϴ�. \r\n\n", year);

			else if (count == 4 && first != year)
				count = 1;

			else if (count < 4 && first == year)
				printf("[ %i ]���� ������ �ƴմϴ�. \r\n\n", year);

			else if (count < 4 && first != year)
				count++;
		}
	}
}

void Ex04_01() // 4-1�� ���� -> �Ƕ�̵�
{
	int height;

	printf("�Ƕ�̵��� ���� : "), scanf_s("%i", &height), printf("\r\n");

	Pyramid(height);
}
void Pyramid(int height)
{
	for (int y = 1; y <= height; ++y)
	{
		for (int space = height - 1; space >= y; --space)
			printf("  ");

		for (int star_L = 1; star_L <= y; ++star_L)
			printf("��");

		for (int star_R = 2; star_R <= y; ++star_R)
			printf("��");

		printf("\r\n");
	}
	printf("\r\n");
}

void Ex04_02() // 4-2�� ���� -> ��ܽ� ������
{
	int start, last;

	printf("----------------------- ��� �� �ܼ� �Է��ϱ� -----------------------\r\n\n");

	printf("���� �� : "), scanf_s("%i", &start), printf("\r\n");

	printf("������ �� : "), scanf_s("%i", &last), printf("\r\n");

	printf("--------------------------------------------------------------------\r\n\n");

	GuGuStairs(start, last);
}
void GuGuStairs(int start, int last)
{
	int One, sta, las, ibreak = 0;

	for (int i = start, j = 0; i <= last; ++i, ++j)
	{
		sta = i;
		las = sta + j;

		for (int Two = 1; Two <= 9; ++Two)
		{
			for (One = sta; One <= las; ++One)
			{
				if (One > last)
					break;

				printf("%i * %i = %i\t", One, Two, One*Two);
			}
			printf("\r\n");
		}
		i = las;

		printf("\r\n");
	}
}

void Ex04_03() // 4-3�� ���� -> 3x3 ������
{
	int start, last;

	printf("----------------------- ��� �� �ܼ� �Է��ϱ� -----------------------\r\n\n");

	printf("���� �� : "), scanf_s("%i", &start), printf("\r\n");

	printf("������ �� : "), scanf_s("%i", &last), printf("\r\n");

	printf("--------------------------------------------------------------------\r\n\n");

	GuGuThree(start, last);
}
void GuGuThree(int start, int last)
{
	for (int One = start; One <= last; One += 3)
	{
		for (int Two = 1; Two <= 9; ++Two)
		{
			for (int Thr = One; Thr <= One + 2; ++Thr)
			{
				if (Thr > last)	break;
				printf("%i * %i = %i \t", Thr, Two, Thr*Two);
			}
			printf("\r\n");
		}
		printf("\r\n");
	}
}