using System;

class Program
{
    static void Main(string[] args)
    {
        const int p = 10000;
        double xs, ys;
        int x, y, ans;

        string[] input = Console.ReadLine().Split();
        xs = double.Parse(input[0]);
        ys = double.Parse(input[1]);
        ans = 1;
        x = y = 0;

        ys -= 1E-10;
        xs += 1E-10;

        while (x == y)
        {
            ans++;
            x = (int)(ans * xs) / 100;
            y = (int)(ans * ys) / 100;
        }

        Console.WriteLine(ans);
    }
}
