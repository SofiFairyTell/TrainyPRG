#include <math.h>
#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

/*
* 1.В блоке include выполняется подключение заголовочных файлов.
По сути это файлы где содержжаться функции. И чтобы их вызвать
нужно обязательно подсоединить этот файл к проекту
*/

//Сначала надо объявить какие функции будут
void printData();
void EnterDataReturnSum_С();
void EnterDataReturnSum_СPP();
void countFunction();

double doubleInputNumber();
int intInputNumber();

double countH(double a, double b, int n);
double countX(double a, double b, double h);
double FunctionY(double x);

int main()
{
	setlocale(LC_CTYPE, "");
    //ТЗ1
	printData();
    EnterDataReturnSum_С();
    EnterDataReturnSum_СPP();
    //ТЗ2
    countFunction();
}


/* ТЗ1
* 1. Вывести ФИО и номер группы на CPP и на С
* 2. Ввести два числа с клавиатуры, проссумировать и отобразить результат
*/

/* ТЗ2
* Найдем значение функции. Будем использовать цикл for
*/

//А теперь напишем, что внутри функций
void printData()
{
	std::cout << "ФИО 123 - этот текст вывел C++" << std::endl; //здесь используется пространство имен из iostream

	printf("ФИО 123- Этот текст вывел C\n ");//здесь используется функция из stdio.h

}

void EnterDataReturnSum_С()
{
	double num1, num2;

    /*Пользователи бывают разные. Запретим вводить что-то кроме чисел
    При этом используем цикл с предусловием. 
    То есть до тех пор пока не придет 1, то пользователю будет выведена ошибка о неправильном вводе числа*/
    
    while (1) {
        printf("Введите первое число:\n");
        if (scanf_s("%lf", &num1) == 1) {
            break; // Выход из цикла, если введено число
        }
        else {
            printf("Ошибка: Введите число.\n");
            while (getchar() != '\n'); // Очистка входного буфера
        }
    }

    while (1) {
        printf("Введите второе число: ");
        if (scanf_s("%lf", &num2) == 1) {
            break; // Выход из цикла, если введено число
        }
        else {
            printf("Ошибка: Введите число.\n");
            while (getchar() != '\n'); // Очистка входного буфера
        }
    }

    double sum = num1 + num2;

    printf("Сумма двух чисел: %lf\n", sum);

    /*
    Здесь можно улучшить следующее:
     - Добавить возможность выхода пользователю - наприер после N-й попытки - выбросить из программы
    */
}

void EnterDataReturnSum_СPP()
{
    double num1, num2;
    std::cout << "Используем C++" << std::endl;
    while (true) {
        std::cout << "Введите первое число: ";
        if (std::cin >> num1) {
            break; // Выход из цикла, если введено число
        }
        else {
            std::cerr << "Ошибка: Введите число." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
    }

    while (true) {
        std::cout << "Введите второе число: ";
        if (std::cin >> num2) {
            break; // Выход из цикла, если введено число
        }
        else {
            std::cerr << "Ошибка: Введите число." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
    }

    double sum = num1 + num2;

    std::cout << "Сумма чисел: " << sum << std::endl;

/*
* std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); говорит потоку ввода std::cin игнорировать 
все символы до символа новой строки ('\n') или до тех пор, пока не будет достигнуто максимальное количество символов, 
которое может обработать тип std::streamsize. Это полезно для очистки оставшихся символов во входном буфере после 
неудачной попытки чтения числа, чтобы избежать некорректного ввода при последующих попытках считывания.
*/
}

void countFunction() {
    double a, b,h;
    int N;
    //Ининициализация
    N = intInputNumber();
    a = doubleInputNumber();
    b = doubleInputNumber();
    h = countH(a,b, N); //шаг от а до b

    double maxValue = FunctionY(a); //предполагаем, что максимум в начале интервала

    int count = 1; //это для того, чтобы посчитать элементы в массиве
    double sum = 0.0; //это для того, чтобы рассчитать потом средее значение

    for (double x = a + h; x <= b; x += h) {
        double value = FunctionY(x);

        // Вычисление максимального значения
        if (value > maxValue) {
            maxValue = value;
        }

        // Вычисление суммы для среднего значения
        sum += value;
        count++;

        std::cout << "Y: " << value << "X: " << std::endl;
    }

    double average_value = sum / count;

    std::cout << "Максимальное значение: " << maxValue << std::endl;
    std::cout << "Среднее значение: " << average_value << std::endl;

}



double doubleInputNumber()
{
    double num;
    std::cout << "Используем C++" << std::endl;
    while (true) {
        std::cout << "Введите число: ";
        if (std::cin >> num) {
            break; // Выход из цикла, если введено число
        }
        else {
            std::cerr << "Ошибка: Введите число." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
    }
    return num;
}

int intInputNumber()
{
    int num;
    std::cout << "Используем C++" << std::endl;
    while (true) {
        std::cout << "Введите число: ";
        if (std::cin >> num) {
            break; // Выход из цикла, если введено число
        }
        else {
            std::cerr << "Ошибка: Введите число." << std::endl;
            std::cin.clear(); // Сброс состояния потока
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка буфера ввода
        }
    }
    return num;
}


//Функция расчета H. На вход переменные. 
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

//Функция расчета Xi. На вход переменные. 
double countX(double a, double i, double h)
{
    return a + i * h;
}

double FunctionY(double x)
{
    if (x > 0)
    {
        return (x) / (pow(x, 2) - 1) + (log(x)/log(3.0));
    }
}