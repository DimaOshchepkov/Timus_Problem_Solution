using System;

class Program
{
    static void Main()
    {
        int n = int.Parse(Console.ReadLine());

        int[] arr = new int[n];
        string[] supArr = Console.ReadLine().Split();
        for (int i = 0; i < n; i++)
            arr[i] = int.Parse(supArr[i]);


        int maxSum = -1, midleElOfMaxSum = -1;
        for (int i = 1; i < n - 1; i++)
        {
            int curMaxSum = arr[i - 1] + arr[i] + arr[i + 1];
            if (curMaxSum > maxSum)
            {
                midleElOfMaxSum = i;
                maxSum = curMaxSum;
            }
        }
        Console.WriteLine($"{maxSum} {midleElOfMaxSum + 1}");
    }
}