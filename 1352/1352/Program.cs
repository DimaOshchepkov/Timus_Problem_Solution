﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Numerics;
using System.Threading.Tasks;

namespace _1352
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = int.Parse(Console.ReadLine());
            int[] data = new int[]
            {
                2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607,
                1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937,
                21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433,
                1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583,
                25964951, 30402457, 32582657, 37156667, 42643801, 43112609, 57885161
            };
            int[] result = new int[n];
            for (int i = 0; i < n; ++i)
                result[i] = data[int.Parse(Console.ReadLine()) - 1];
            for (int i = 0; i < n; ++i)
                Console.WriteLine(result[i]);
        }
    }
}
