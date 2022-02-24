using System;
using System.Collections.Generic;
using System.Text;

class Problem
{
    int N = 0;
    List<List<int>> edges = new List<List<int>>();
    int[] parent = new int[100001];
    bool[] visited = new bool[100001];

    void DFS(int node)
    {
        visited[node] = true;

        for (int i = 0; i < edges[node].Count; i++)
        {
            int next = edges[node][i];

            if (!visited[next])
            {
                parent[next] = node;
                DFS(next);
            }
        }
    }

    void Solve()
    {
        N = int.Parse(Console.ReadLine());

        for (int i = 0; i <= N; i++)
            edges.Add(new List<int>());

        for (int i = 0; i < N - 1; i++)

        {   
            var s = Console.ReadLine().Split();

            int a = int.Parse(s[0]);
            int b = int.Parse(s[1]);

            edges[a].Add(b);
            edges[b].Add(a);
        }

        DFS(1);
        
        StringBuilder SB = new StringBuilder();

        for(int i = 2; i <= N; i++)
        {
            SB.Append(parent[i]);
            SB.Append("\n");
        }
        
        Console.Write(SB);
    }

    static void Main()
    {
        Problem P = new Problem();
        P.Solve();
    }
}
