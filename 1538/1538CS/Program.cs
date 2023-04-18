using System;
using System.Collections.Generic;

public class pos
{
    public long x, y;
}

public class Program
{
    static double pi = 3.141592653589793238462643383279502884197169399375105820974;
    static pos[] A = new pos[5000];

    static bool test(List<long> v)
    {
        double sum = 0;
        for (int i = 1; i <= v.Count; i++)
        {
            long a = v[i - 1], b = v[i % 5], c = v[(i + 1) % 5];
            long x1 = A[a].x - A[b].x, x2 = A[c].x - A[b].x;
            long y1 = A[a].y - A[b].y, y2 = A[c].y - A[b].y;

            if (x1 * y2 - x2 * y1 > 0)
                return false;
            sum += Math.Acos((double)((x1 * x2 + y1 * y2) / (Math.Sqrt(x1 * x1 + y1 * y1) * Math.Sqrt(x2 * x2 + y2 * y2))));
        }
        return Math.Abs(sum - 3 * pi) < 1e-8;
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        Random rand = new Random(0);

        for (int i = 0; i < N; i++)
        {
            string[] line = Console.ReadLine().Split(' ');
            A[i] = new pos { x = long.Parse(line[0]), y = long.Parse(line[1]) };
        }
        for (int i = 0; i < 5000; i++)
        {
            List<long> v = new List<long>();
            while (v.Count != 5)
            {
                int x = rand.Next(N);
                if (!v.Contains(x))
                    v.Add(x);
            }
            if (test(v))
            {
                Console.WriteLine("Yes");
                foreach (long x in v)
                    Console.Write((x + 1) + " ");
                return;
            }
        }
        Console.WriteLine("No");
    }
}