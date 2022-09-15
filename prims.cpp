#include <bits/stdc++.h>
using namespace std;
#define V 9
int minKey(int key[], bool Set[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (Set[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}
void print_span_tree(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << char(97+parent[i]) << " - " << char(97+i) << " \t" << graph[i][parent[i]] << " \n";
}
void prim_minnimum_span(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool Set[V];
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, Set[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, Set);
        Set[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && Set[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    print_span_tree(parent, graph);
}
int main()
{

    int G[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 14, 10, 0, 2, 0, 0},
                   {0, 0, 0, 0, 0, 2, 0, 1, 2},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 2, 7, 0}};
    prim_minnimum_span(G);
    return 0;
}
