internal class Program
{
    private static void Main(string[] args)
    {
        var x = Console.ReadLine().Split().Select(int.Parse).ToArray();
        int n = x[0], k = x[1];

        int[] arr = new int[n];
        int changer = 1;
        for (int i = 0; i < k - 1; i++)
        {
            arr[i] = changer * PowForMinusOne(i);
            changer += i % 2;
        }

        foreach (int i in arr)
            Console.Write($"{i} ");
    }

    private static int PowForMinusOne(int pow)
    {
        if (pow % 2 == 0)
            return 1;
        else
            return -1;
    }
}