#include <math.h>
#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

/*
* 1.� ����� include ����������� ����������� ������������ ������.
�� ���� ��� ����� ��� ������������ �������. � ����� �� �������
����� ����������� ������������ ���� ���� � �������
*/

//������� ���� �������� ����� ������� �����
void printData();
void EnterDataReturnSum_�();
void EnterDataReturnSum_�PP();
void countFunction();

double doubleInputNumber();
int intInputNumber();

double countH(double a, double b, int n);
double countX(double a, double b, double h);

int main()
{
	setlocale(LC_CTYPE, "");
    //��1
	printData();
    EnterDataReturnSum_�();
    EnterDataReturnSum_�PP();
    //��2

}


/* ��1
* 1. ������� ��� � ����� ������ �� CPP � �� �
* 2. ������ ��� ����� � ����������, �������������� � ���������� ���������
*/

/* ��2
* ������ �������� �������. ����� ������������ ���� for
*/

//� ������ �������, ��� ������ �������
void printData()
{
	std::cout << "��� 123 - ���� ����� ����� C++" << std::endl; //����� ������������ ������������ ���� �� iostream

	printf("��� 123- ���� ����� ����� C\n ");//����� ������������ ������� �� stdio.h

}

void EnterDataReturnSum_�()
{
	double num1, num2;

    /*������������ ������ ������. �������� ������� ���-�� ����� �����
    ��� ���� ���������� ���� � ������������. 
    �� ���� �� ��� ��� ���� �� ������ 1, �� ������������ ����� �������� ������ � ������������ ����� �����*/
    
    while (1) {
        printf("������� ������ �����:\n");
        if (scanf_s("%lf", &num1) == 1) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            printf("������: ������� �����.\n");
            while (getchar() != '\n'); // ������� �������� ������
        }
    }

    while (1) {
        printf("������� ������ �����: ");
        if (scanf_s("%lf", &num2) == 1) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            printf("������: ������� �����.\n");
            while (getchar() != '\n'); // ������� �������� ������
        }
    }

    double sum = num1 + num2;

    printf("����� ���� �����: %lf\n", sum);

    /*
    ����� ����� �������� ���������:
     - �������� ����������� ������ ������������ - ������� ����� N-� ������� - ��������� �� ���������
    */
}

void EnterDataReturnSum_�PP()
{
    double num1, num2;
    std::cout << "���������� C++" << std::endl;
    while (true) {
        std::cout << "������� ������ �����: ";
        if (std::cin >> num1) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            std::cerr << "������: ������� �����." << std::endl;
            std::cin.clear(); // ����� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        }
    }

    while (true) {
        std::cout << "������� ������ �����: ";
        if (std::cin >> num2) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            std::cerr << "������: ������� �����." << std::endl;
            std::cin.clear(); // ����� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        }
    }

    double sum = num1 + num2;

    std::cout << "����� �����: " << sum << std::endl;

/*
* std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); ������� ������ ����� std::cin ������������ 
��� ������� �� ������� ����� ������ ('\n') ��� �� ��� ���, ���� �� ����� ���������� ������������ ���������� ��������, 
������� ����� ���������� ��� std::streamsize. ��� ������� ��� ������� ���������� �������� �� ������� ������ ����� 
��������� ������� ������ �����, ����� �������� ������������� ����� ��� ����������� �������� ����������.
*/
}

void countFunction() {
    double a, b;
    int N;
    //���������������
    N = intInputNumber();
    a = doubleInputNumber();
    b = doubleInputNumber();
    
}



double doubleInputNumber()
{
    double num;
    std::cout << "���������� C++" << std::endl;
    while (true) {
        std::cout << "������� �����: ";
        if (std::cin >> num) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            std::cerr << "������: ������� �����." << std::endl;
            std::cin.clear(); // ����� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        }
    }
}

int intInputNumber()
{
    int num;
    std::cout << "���������� C++" << std::endl;
    while (true) {
        std::cout << "������� �����: ";
        if (std::cin >> num) {
            break; // ����� �� �����, ���� ������� �����
        }
        else {
            std::cerr << "������: ������� �����." << std::endl;
            std::cin.clear(); // ����� ��������� ������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ������� ������ �����
        }
    }
}


//������� ������� H. �� ���� ����������. 
double countH(double a, double b, int n) 
{
    if (n != 0)
    {
        return (b - a) / n;
    }
    else
    {
        return 0;
    }
}

//������� ������� Xi. �� ���� ����������. 
double countX(double a, double i, double h)
{
    return a + i * h;
}