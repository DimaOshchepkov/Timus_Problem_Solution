﻿// 1910.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::cin >> n;
    
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    
    int maxSum = -1, midleElOfMaxSum = -1;
    for (int i = 1; i < n - 1; i++)
    {
        int curMaxSum = arr[i - 1] + arr[i] + arr[i + 1];
        if (curMaxSum > maxSum)
        {
            midleElOfMaxSum = i;
            maxSum = curMaxSum;
        }
    }
    std::cout << maxSum << " " << midleElOfMaxSum + 1;
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
