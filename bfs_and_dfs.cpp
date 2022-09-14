#include <iostream>

using namespace std;

void enqueue(int value);
int dequeue();
bool isEmpty();
void BFS(int graph[][9], int start, int n);
void DFS(int graph[][9], int start, int n);

struct queue
{
    int *arr;
    int size;
    int front;
    int rear;
};

queue qt;

int main()
{
    qt.size = 9; // queue size
    qt.arr = new int[qt.size];
    qt.front = qt.rear = -1;

    // use fucntion here
    int graph[9][9] = {{0, 1, 0, 0, 0, 0, 0, 0, 1},
                       {1, 0, 0, 0, 0, 0, 0, 0, 0},
                       {0, 0, 0, 1, 1, 1, 0, 0, 1},
                       {0, 0, 1, 0, 0, 0, 0, 0, 0},
                       {0, 0, 1, 0, 0, 0, 0, 1, 0},
                       {0, 0, 1, 0, 0, 0, 1, 0, 0},
                       {0, 0, 0, 0, 0, 1, 0, 1, 1},
                       {0, 0, 0, 0, 1, 0, 1, 0, 0},
                       {1, 0, 1, 0, 0, 0, 1, 0, 0}};
    cout << "DFS : ";
    DFS(graph, 0, 9);
    cout << endl;
    cout << "BFS : ";
    BFS(graph, 0, 9);
}

void BFS(int graph[][9], int start, int n) // bfs code
{
    int st = start;
    int visited[9] = {0};

    cout << st << " ";
    visited[st] = 1;
    enqueue(st);

    while (!isEmpty())
    {
        st = dequeue();
        for (int i = 0; i < n; i++)
        {
            if (graph[st][i] == 1 && visited[i] == 0)
            {
                cout << i << " ";
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

void DFS(int graph[][9], int start, int n) // dfs code
{
    static int visited[9] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (int i = 0; i < n; i++)
        {
            if (graph[start][i] == 1 && visited[i] == 0)
            {
                DFS(graph, i, n);
            }
        }
    }
}

void enqueue(int value)
{
    if (qt.rear == qt.size - 1)
    {
        cout << "Queue Full" << endl;
    }
    else
    {
        qt.rear++;
        qt.arr[qt.rear] = value;
    }
}

int dequeue()
{
    int value = -1;
    if (qt.rear == -1)
    {
        cout << "Queue Empty" << endl;
    }
    else
    {
        qt.front++;
        value = qt.arr[qt.front];
    }

    return value;
}

bool isEmpty()
{
    if ((qt.front == -1) && (qt.rear == -1))
    {
        return true;
    }
    return false;
}