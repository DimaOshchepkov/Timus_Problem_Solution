using System;
using System.Collections.Generic;

class Matrix
{
    private List<List<bool>> matrix;

    public Matrix(List<List<bool>> matrix)
    {
        this.matrix = matrix;
    }

    public Matrix(int n)
    {
        matrix = new List<List<bool>>();
        for (int i = 0; i < n; i++)
        {
            matrix.Add(new List<bool>(n));
            for (int j = 0; j < n; j++)
            {
                matrix[i].Add(false);
            }
        }
    }

    public Matrix(Matrix other)
    {
        matrix = new List<List<bool>>();
        foreach (List<bool> row in other.matrix)
        {
            matrix.Add(new List<bool>(row));
        }
    }

    public Matrix Add(Matrix other)
    {
        Matrix result = new Matrix(matrix.Count);
        for (int i = 0; i < matrix.Count; i++)
        {
            for (int j = 0; j < matrix.Count; j++)
            {
                result.matrix[i][j] = matrix[i][j] || other.matrix[i][j];
            }
        }
        return result;
    }

    public Matrix Multiply(Matrix other)
    {
        Matrix result = new Matrix(matrix.Count);
        for (int i = 0; i < matrix.Count; i++)
        {
            for (int j = 0; j < matrix.Count; j++)
            {
                int k = 0;
                while (k < matrix.Count && (!matrix[i][k] || !other.matrix[k][j]))
                    k++;

                if (k != matrix.Count)
                    result.matrix[i][j] = true;
                else
                    result.matrix[i][j] = false;
            }
        }
        return result;
    }

    public Matrix Pow(int n)
    {
        Matrix ans = new Matrix(matrix);
        Matrix cur = new Matrix(matrix);
        for (int i = 0; i < n - 1; i++)
            ans = ans.Multiply(cur);
        return ans;
    }

    public bool IsContainZero()
    {
        foreach (List<bool> row in matrix)
            foreach (bool value in row)
                if (!value)
                    return true;

        return false;
    }
}

class Program
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        List<List<bool>> m = new List<List<bool>>(n);
        int x;
        for (int i = 0; i < n; i++)
        {
            string[] row = Console.ReadLine().Split();
            m.Add(new List<bool>(n));
            for (int j = 0; j < n; j++)
            {
                x = int.Parse(row[j]);
                m[i].Add(x != 0);
            }
        }

        Matrix A = new Matrix(m);
        Matrix sup = A.Pow(n * (n - 1) - 1);
        Matrix B = new Matrix(n);
        for (int k = n * (n - 1); k <= n * (n + 1); k++)
        {
            sup = sup.Multiply(A);
            B = B.Add(sup);
        }

        if (B.IsContainZero())
            Console.WriteLine("No");
        else
            Console.WriteLine("Yes");
    }
}

