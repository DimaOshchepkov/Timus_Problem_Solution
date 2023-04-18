// 1755CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//




/*
  Strategy:
  If we think of the domain as an (n,m) rectangle in the first quadrant of the x-y plane, both
  players want to put the coordinate representing their slice in the top right corner. However,
  if the first player does, the second will have him use the reflection of that point about the
  origin instead. The solution then is to place the coordinate along the isoline of the graph
  a_2*x + b_2*y that passes through the origin, at one of two extreme points.

 */

#include <stdio.h>

int main()
{
    double a1, b1, a2, b2, n, m;
    scanf_s("%lf %lf %lf %lf %lf %lf", &a1, &b1, &a2, &b2, &n, &m);
    if (b2 * a2 == 0)
        printf("%.10lf %.10lf", a2 ? n / 2 : n, b2 ? m / 2 : m);
    else
        printf("%.10lf %.10lf", m * b2 < n* a2 ? (b2 / a2 * m + n) / 2 : n, m* b2 < n* a2 ? 0 : (m - n * a2 / b2) / 2);
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
