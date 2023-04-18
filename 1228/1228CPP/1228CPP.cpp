﻿// 1228CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

/// <summary>
/// Here you need to somehow translate s into a mixed number system
/// </summary>
int main()
{
    int n = 0, s = 0;
    std::cin >> n >> s;

    auto multiplier = std::vector<int>(n);
    for (int i = 0; i < n; i++)
        std::cin >> multiplier[i];

    auto ans = std::vector<int>(n);
    s--;
    int j = 0;
    while (s != 0)
    {
        ans[j] = s / multiplier[j];
        s = s % multiplier[j];
        j++;
    }
    for (const int el : ans)
        std::cout << el << ' ';
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