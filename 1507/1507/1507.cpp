// 1507.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<bool>> matrix;

public:
    Matrix(const std::vector<std::vector<bool>>& matrix)
        : matrix(matrix)
    {}

    Matrix(int n)
        : matrix(n, std::vector<bool>(n))
    {}

    Matrix(Matrix&& other) noexcept
        : matrix(std::move(other.matrix))
    {}

    Matrix& operator=(Matrix&& other) noexcept
    {
        if (this != &other)
            this->matrix = std::move(other.matrix);
        return *this;
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                int k = 0;
                while (k < matrix.size() && matrix[i][k] * other.matrix[k][j] != 1)
                    k++;

                if (k != matrix.size())
                    result.matrix[i][j] = 1;
                else
                    result.matrix[i][j] = 0;
            }
        }
        return result;
    }
    
    Matrix pow(int n)
    {
        Matrix ans(this->matrix);
        Matrix cur(this->matrix);
        for (int i = 0; i < n - 1; i++)
            ans = ans * cur;
        return ans;
    }

    bool isContainZero() const
    {
        for (int i = 0; i < this->matrix.size(); i++)
            for (int j = 0; j < this->matrix.size(); j++)
                if (this->matrix[i][j] == 0)
                    return true;

        return false;
    }
};


int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<bool>> m(n, std::vector<bool>(n));
    int x;
    for (int i = 0; i < m.size(); i++)
        for (int j = 0; j < m.size(); j++)
        {
            std::cin >> x;
            m[i][j] = (x != 0);
        }

    Matrix A(m);
    Matrix sup = A.pow(n * (n - 1) - 1);
    Matrix B(n);
    for (int k = n * (n - 1); k <= n * (n + 1); k++)
    {
        sup = sup * A;
        B = B + sup;
    }

    if (B.isContainZero())
        std::cout << "No";
    else
        std::cout << "Yes";
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
