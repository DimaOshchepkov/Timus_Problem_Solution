// 1073CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <cmath>

/// <summary>
/// This problem is reduced to the classical coin problem.
/// We solve using dynamic programming.The following options are possible :
/// 1. The number of squares is 1 if the root of n is an integer
/// 2. The number of squares can be represented as the sum
/// of the quantities of two groups of squares.
///
/// This results in an algorithm
/// </summary>
int main()
{
    int N = 0;
    std::cin >> N;
    std::vector<int> squares = std::vector<int>(N + 1);
    for (int i = 0; i < squares.size(); i++)
        squares[i] = 5;
    squares[0] = 0;
    squares[1] = 1;

    for (int i = 2; i < squares.size(); i++)
    {
        for (int j = 1; j <= (int)std::sqrt(i); j++)
            squares[i] = std::min(squares[j * j] + squares[i - j * j], squares[i]);

        if (i == (int)std::sqrt(i) * (int)std::sqrt(i))
            squares[i] = 1;
    }
    std::cout << squares[squares.size() - 1];
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
