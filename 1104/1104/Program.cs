using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1104
{
    internal class Program
    {
        static void Main(string[] args)
        {

            string number = Console.ReadLine();

            int sumDigits = 0;
            int answer = 0;
            int k = number.Max(x =>
            {
                if (char.IsDigit(x))
                    return x - '0';
                else
                    return x + 10 - 'A';
            });

            foreach (char c in number)
            {
                if (char.IsDigit(c))
                    sumDigits += c - '0';
                else
                    sumDigits += c + 10 - 'A';
            }

            k = Math.Max(k + 1, 2);
            for (; k <= 36 && answer == 0; k++)
            {
                if (sumDigits % (k - 1) == 0)
                    answer = k;
            }

            if (answer != 0)
                Console.WriteLine(answer);
            else
                Console.WriteLine("No solution.");

            //Console.ReadKey();
        }
    }
}
