using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _1197
{
    internal class Program
    {
        static void Main(string[] args)
        {
            const int SIZE = 8;
            const int COUNT_SUGGESTED_LOCATION = 8;
            int[] dx = new int[] { -2, -1, 1, 2, 2, 1, -1, -2 };
            int[] dy = new int[] { 1, 2, 2, 1, -1, -2, -2, -1 };

            int N = int.Parse(Console.ReadLine());
            int[] answer = new int[N];
            for (int i = 0; i < N; i++)
            {
                string position = Console.ReadLine();
                int x = position[0] - 'a' + 1;
                int y = position[1] - '0';

                int ans = 0;
                for (int j = 0; j < COUNT_SUGGESTED_LOCATION; j++)
                    if (x + dx[j] > 0 && x + dx[j] <= SIZE &&
                        y + dy[j] > 0 && y + dy[j] <= SIZE)
                        ans++;

                answer[i] = ans;
            }
            foreach (int el in answer)
                Console.WriteLine(el);

            //Console.ReadKey();
        }
    }
}
