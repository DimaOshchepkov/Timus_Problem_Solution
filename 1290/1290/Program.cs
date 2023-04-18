using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;

namespace _1290
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int N = int.Parse(Console.ReadLine());
            int[] array = new int[N];
            for (int i = 0; i < array.Length; i++)
                array[i] = int.Parse(Console.ReadLine());

            Array.Sort(array, (x, y) => y.CompareTo(x));
            foreach (int el in array)
                Console.WriteLine(el);
        }
    }
}
