#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include <locale.h>

int isPrime(int n)
{
    int d;
    if (n < 2)
        return 0;
    for (d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
            return 0;
    }
    return 1;
}

void task146(void)
{
    int limit, m, p, found, ok = 1;

    printf("Введіть верхню межу перевірки (більше 50): ");
    scanf("%d", &limit);

    for (m = 52; m <= limit; m += 2)
    {
        found = 0;
        p = 2;
        while (p <= m / 2 && found == 0)
        {
            if (isPrime(p) && isPrime(m - p))
                found = 1;
            else
                p++;
        }

        if (found == 1)
            printf("%d = %d + %d\n", m, p, m - p);
        else
        {
            printf("%d - розкладу не знайдено\n", m);
            ok = 0;
        }
    }

    if (ok == 1)
        printf("Гіпотеза Гольдбаха підтвердилась\n");
    else
        printf("Гіпотеза не підтвердилась\n");
}

void task153(void)
{
    int a, b, rest, quotient = 0;

    do
    {
        printf("Введіть a і b (a > b > 0): ");
        scanf("%d %d", &a, &b);
    } while (b <= 0 || a <= b);

    rest = a;
    while (rest >= b)
    {
        rest = rest - b;
        quotient++;
    }

    printf("Результат цілочисельного ділення: %d\n", quotient);
    printf("Залишок від ділення: %d\n", rest);
}

void task172(void)
{
    int n, x, i, place = 1;

    printf("Введіть кількість очок n: ");
    scanf("%d", &n);

    printf("Введіть очки 20 команд за спаданням:\n");
    for (i = 1; i <= 20; i++)
    {
        scanf("%d", &x);
        place += (x > n);
    }

    printf("Команда посіла %d місце\n", place);
}

void task209(void)
{
    double eps, a = 2.0, sum = 0.0;
    int n = 1;

    do
    {
        printf("Введіть eps (більше 0): ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    while (n <= 3 || a >= eps)
    {
        if (a >= eps)
            sum += a;
        a = a * 2 / n;
        n++;
    }

    printf("Сума = %lf\n", sum);
}

void task270(void)
{
    int cur, prev, run = 1, maxRun = 1, distinct = 1;

    printf("Введіть числа (остання - 1000):\n");
    scanf("%d", &cur);
    prev = cur;

    while (cur != 1000)
    {
        scanf("%d", &cur);
        if (cur == prev)
        {
            run++;
            if (run > maxRun)
                maxRun = run;
        }
        else
        {
            distinct++;
            run = 1;
        }
        prev = cur;
    }

    printf("Найдовша група однакових чисел поспіль: %d\n", maxRun);
    printf("Кількість різних чисел: %d\n", distinct);
}

void task81(void)
{
    int i;
    double a, sum = 0.0;

    printf("Введіть 10 чисел:\n");
    for (i = 1; i <= 10; i++)
    {
        scanf("%lf", &a);
        sum += a;
    }

    printf("Сума = %lf\n", sum);
}

void task208(void)
{
    double eps, a = 0.5, sum = 0.0;
    int n = 1;

    do
    {
        printf("Введіть eps (більше 0): ");
        scanf("%lf", &eps);
    } while (eps <= 0);

    while (a >= eps)
    {
        sum += a;
        a = a / (2.0 * (2 * n + 1));
        n++;
    }

    printf("Сума = %.10lf\n", sum);
}

void task97(void)
{
    int athlete, sport, score, sum;

    for (athlete = 1; athlete <= 2; athlete++)
    {
        sum = 0;
        printf("Спортсмен %d, введіть 5 балів:\n", athlete);
        for (sport = 1; sport <= 5; sport++)
        {
            scanf("%d", &score);
            sum += score;
        }
        printf("Сума балів спортсмена %d: %d\n", athlete, sum);
    }
}

void task34(void)
{
    int n, i;
    double x, power, sum = 0.0;

    printf("Введіть n і x: ");
    scanf("%d %lf", &n, &x);

    power = x;
    for (i = 1; i <= n; i++)
    {
        sum += sin(power);
        power *= x;
    }

    printf("Сума = %lf\n", sum);
}

void task25(void)
{
    int n, i;
    double term = 1.0, S = 0.0;

    printf("Введіть n: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        S += term;
        term = -term / 2;
    }

    printf("S = %lf\n", S);
}

int main(void)
{
    int choice;

    system("chcp 65001 > nul");
    setlocale(LC_ALL, "");

    do
    {
        printf("\nЛабораторна робота №4\n");
        printf("1 - завдання 146\n");
        printf("2 - завдання 153\n");
        printf("3 - завдання 172\n");
        printf("4 - завдання 209\n");
        printf("5 - завдання 270\n");
        printf("6 - завдання 81\n");
        printf("7 - завдання 208\n");
        printf("8 - завдання 97\n");
        printf("9 - завдання 34\n");
        printf("10 - завдання 25\n");
        printf("0 - вихід\n");
        printf("Ваш вибір: ");

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n');   // discard the bad input
            printf("Invalid input\n");
            continue;
        }

        switch (choice)
        {
            case 1: task146(); break;
            case 2: task153(); break;
            case 3: task172(); break;
            case 4: task209(); break;
            case 5: task270(); break;
            case 6: task81(); break;
            case 7: task208(); break;
            case 8: task97(); break;
            case 9: task34(); break;
            case 10: task25(); break;
            case 0: break;
            default: printf("Невірний вибір\n");
        }

    } while (choice != 0);

    return 0;
}