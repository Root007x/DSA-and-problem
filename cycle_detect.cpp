#include <bits/stdc++.h>

using namespace std;

int arr[9] = {0, -1, -1, -1, -1, -1, -1, -1, -1};

int find_parent(int val)
{
    int par = val;
    while (arr[par] > 0)
    {
        par = arr[par];
    }
    return par;
}

void join(int x, int y)
{
    if (arr[x] > arr[y])
    {
        arr[y] = arr[y] + arr[x];
        arr[x] = y;
    }
    else
    {
        arr[x] = arr[x] + arr[y];
        arr[y] = x;
    }
}

void cycle_detect(int x, int y)
{
    int p1 = find_parent(x);
    int p2 = find_parent(y);
    if (p1 != p2)
    {
        join(p1, p2);
        cout << "No cycle detect at " << x << "," << y << endl;
    }
    else
    {
        cout << "Cycle detect ar " << x << "," << y << endl;
    }
}

int main()
{
    int n = 6;
    int graph[n][n] = {
        {0, 0, 0, 0, 0, 0},  // 0
        {0, 0, 1, 0, 0, 1},  // 1
        {0, 1, 0, 1, 0, 0},  // 2
        {0, 0, 1, 0, 1, 0},  // 3
        {0, 0, 0, 1, 0, 1},  // 4
        {0, 1, 0, 0, 1, 0}}; // 5

    int visited[n] = {0};

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (graph[i][j] == 1)
            {
                if (visited[i] == 0 && visited[j] == 0)
                {
                    cycle_detect(i, j);
                }
            }
        }
        visited[i] = 1;
    }
    return 0;
}