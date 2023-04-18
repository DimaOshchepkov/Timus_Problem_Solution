using System;

namespace _1755
{
    class Program
    {
        static void Main(string[] args)
        {
            double a1, b1, a2, b2, n, m;
            string[] input = Console.ReadLine().Split();
            a1 = double.Parse(input[0]);
            b1 = double.Parse(input[1]);
            a2 = double.Parse(input[2]);
            b2 = double.Parse(input[3]);

            input = Console.ReadLine().Split();
            n = double.Parse(input[0]);
            m = double.Parse(input[1]);
            if (b2 * a2 == 0)
                Console.WriteLine("{0:F10} {1:F10}", a2 != 0 ? n / 2 : n, b2 != 0 ? m / 2 : m);
            else
                Console.WriteLine("{0:F10} {1:F10}", m * b2 < n * a2 ? (b2 / a2 * m + n) / 2 : n, m * b2 < n * a2 ? 0 : (m - n * a2 / b2) / 2);
        }

    }
}