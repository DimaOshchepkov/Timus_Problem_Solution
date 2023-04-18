// 1538.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <random>
#include <iostream>
#include <vector>

using ld = long double;
using ll = long long;
ld pi = 3.141592653589793238462643383279502884197169399375105820974;

struct pos { ll x, y; };

pos A[5000];

/// <summary>
/// Checking a polygon for convexity
/// </summary>
/// <param name="v"> pentagon</param>
/// <returns>true, if the pentagon is convex, otherwise false</returns>
bool test(std::vector<ll>& v) {
    ld sum = 0; // Sum of the interior angles
    for (int i = 1; i <= v.size(); i++) {
        ll a = v[i - 1], b = v[i % 5], c = v[(i + 1) % 5];
        ll x1 = A[a].x - A[b].x, x2 = A[c].x - A[b].x;
        ll y1 = A[a].y - A[b].y, y2 = A[c].y - A[b].y;

        if (x1 * y2 - x2 * y1 > 0) // Turns in the wrong direction
            return false;
        sum += std::acos((ld)((x1 * x2 + y1 * y2) / (std::sqrt(x1 * x1 + y1 * y1) * std::sqrt(x2 * x2 + y2 * y2))));
    }
    return std::abs(sum - 3 * pi) < 1e-8; // Interior angle sum needs to be 540 degrees
}

/// <summary>
/// The law of large numbers.
///  The probability that random points form a convex pentagon is high.
///  Therefore, we will choose 5 random points and check them for convexity.
/// </summary>
/// <returns></returns>
int main() {
    int N;
    std::cin >> N;

    std::default_random_engine generator(0);
    std::uniform_int_distribution<int> ngen(0, N - 1);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i].x >> A[i].y;
    }
    for (int i = 0; i < 5000; i++) {
        std::vector<ll> v;
        while (v.size() != 5) {
            int x = ngen(generator);
            if (std::find(v.begin(), v.end(), x) == v.end())
                v.push_back(x);
        }
        if (test(v)) {
            std::cout << "Yes" << std::endl;
            for (auto x : v)
                std::cout << (x + 1) << " ";
            return 0;
        }
    }
    std::cout << "No";
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
