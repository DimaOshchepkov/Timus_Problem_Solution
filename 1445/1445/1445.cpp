// 1445.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/* 1445.
 *
 * Strategy:
 * The worst case happens when the members of the biggest group all come first, in which case
 * one gift for each member is required. In the best case, we keep exchange presents between
 * the two current biggest remaining groups (we remove one person from each group each time we
 * exchange presents), in which case we end up with zero remaining members at the end unless
 * the biggest group contains more members than all other groups combined. In the latter case,
 * the result is the difference in the number of members between the initial size of the majority
 * group and the rest of the groups.
 *
 * Performance:
 * Linear in the size of the input, runs in 0.015s using 256KB memory.
 */

#include <iostream>
#include <algorithm>

int main()
{
    int N, x, max = 0, sum = 0;
    std::cin >> N;
    while (N--)
    {
        std::cin >> x;
        sum += x;
        max = std::max(x, max);
    }
    std::cout << std::max(2 * max - sum, 1) << " " << max;
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
