using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1042CS
{
    class Program
    {
        static void Main(string[] args)
        {
            int n, x = 0;
            n = int.Parse(Console.ReadLine());
            int[,] A = new int[n, n + 1];

            for (int i = 0; i < n; i++)
            {
                string[] line = Console.ReadLine().Split(' ');
                for (int j = 0; j < line.Length; j++)
                {
                    int.TryParse(line[j], out x);
                    if (x != -1)
                    {
                        A[x - 1, i] = 1;
                        A[x - 1, n] = 1;
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                int k = i;
                while (k < n && A[k, i] != 1)
                    k++;

                for (int j = 0; j < n + 1; j++)
                {
                    int tmp = A[k, j];
                    A[k, j] = A[i, j];
                    A[i, j] = tmp;
                }

                for (k = 0; k < n; k++)
                    if (A[k, i] == 1 && k != i)
                        for (int j = i; j < n + 1; j++)                      
                            A[k, j] ^= A[i, j];
   
            }
            for (int i = 0; i < n; i++)
                if (A[i, n] == 1)
                    Console.Write((i + 1) + " ");
        }
    }
}
