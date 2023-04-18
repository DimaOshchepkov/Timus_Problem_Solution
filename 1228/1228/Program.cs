using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1228
{
    internal class Program
    {
        static void Main(string[] args)
        {
            string[] ns = Console.ReadLine().Split();
            int n = int.Parse(ns[0]);
            int s = int.Parse(ns[1]);

            int[] multiplier = new int[n];
            for (int i = 0; i < n; i++)
                multiplier[i] = int.Parse(Console.ReadLine());

            int[] ans = new int[n];
            s--;
            int j = 0;
            while (s != 0)
            {
                ans[j] = s / multiplier[j];
                s = s % multiplier[j];
                j++;
            }
            foreach (int el in ans)
                Console.Write("{0} ", el);

            //Console.ReadKey();
        }
    }
}
