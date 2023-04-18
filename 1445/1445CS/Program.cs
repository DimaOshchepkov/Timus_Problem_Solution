using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1445CS
{
    using System;

    class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int x, max = 0, sum = 0;

            string[] groups = Console.ReadLine().Split();
            foreach(string group in groups)
            {
                x = int.Parse(group);
                sum += x;
                max = Math.Max(x, max);
            }

            Console.WriteLine($"{Math.Max(2 * max - sum, 1)} {max}");
        }
    }
}
