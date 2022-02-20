using System;

class Problem{
    public static void Main(){
        int N = int.Parse(Console.ReadLine());
        
        int Sum = 0;
        
        string temp = Console.ReadLine();
        
        for(int i = 0; i < N; i++)
            Sum += temp[i]-'0';
        
        Console.Write(Sum);
    }
}