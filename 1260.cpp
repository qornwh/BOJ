#include <iostream>
#include <queue>
using namespace std;

queue<int> q;
int n, m, V;
short adj[1001][1001];
int u, v;
bool visited[1001];

void DFS(int node)
{
    cout << node << " ";
    visited[node] = true;
    for (int i = 1; i <= n; i++)
    {
        if (adj[node][i])
        {
            if (!visited[i])
            {
                DFS(i);
            }
        }
    }
}

void BFS(int node){
    visited[node] = true;
    q.push(node);

    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout << t << " ";

        for(int i=1; i<=n; i++){
            if(adj[t][i]){
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m >> V;
    while (m--)
    {
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    DFS(V);

    for(int i =1; i<=n; i++){
        visited[i] = false;
    }
    cout << endl;

    BFS(V);

    return 0;
}