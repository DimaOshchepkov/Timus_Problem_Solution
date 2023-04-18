using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1073
{
    internal class Program
    {
        static void Main(string[] args)
        {

            int[] squares = new int[int.Parse(Console.ReadLine()) + 1];
            for (int i = 0; i < squares.Length; i++)
                squares[i] = 5;
            squares[0] = 0;
            squares[1] = 1;

            for (int i = 2; i < squares.Length; i++)
            {
                for (int j = 1; j <= (int)Math.Sqrt(i); j++)
                    squares[i] = Math.Min(squares[j * j] + squares[i - j * j], squares[i]);

                if (i == (int)Math.Sqrt(i) * (int)Math.Sqrt(i))
                    squares[i] = 1;
            }
            Console.WriteLine(squares[squares.Length - 1]);
            //Console.ReadKey();
        }
    }
}
