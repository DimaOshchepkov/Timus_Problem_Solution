using System;

class Program
{
    static void Main()
    {
        string str = Console.ReadLine();
        int res = 20;
        string sandro = "Sandro";
        for (int i = 0; i <= str.Length - sandro.Length; i++)
        {
            int count = 0;
            for (int j = 0; j < sandro.Length; j++)
            {
                char s1 = sandro[j];
                char s2 = str[j + i];
                if (s1 != s2)
                {
                    if ((s1 <= 'z' && s1 >= 'a' && s2 <= 'z' && s2 >= 'a') ||
                        (s1 <= 'Z' && s1 >= 'A' && s2 <= 'Z' && s2 >= 'A'))
                        count++;
                    else if (char.ToUpper(s1) == char.ToUpper(s2))
                        count++;
                    else
                        count += 2;
                }
            }
            res = Math.Min(res, count);
        }
        Console.WriteLine(res * 5);
    }
}
