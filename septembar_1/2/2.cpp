#include <bits/stdc++.h>

using namespace std;

int V, M;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> disc;
vector<int> low;
set<int> s;
int t = 0;

void DFS(int u, int p = -1)
{
    visited[u] = true;
    disc[u] = low[u] = t++;
    
    int children = 0;
    for(int v : adj[u])
    {
        if(v == p)
            continue;
        
        if(!visited[v])
        {
            DFS(v, u);
            
            low[u] = min(low[u], low[v]);
            if(disc[u] <= low[v] && p != -1)
                s.insert(u);
            children++;
        }
        else
        {
            low[u] = min(low[u], disc[v]);
        }
    }
    
    if(p == -1 && children > 1)
       s.insert(u);
}

void articulation_points()
{
    for(int i = 0; i < V; i++)
    {
        if(!visited[i])
            DFS(i);
    }
    
    for(auto x : s)
        printf("%d ", x);
    printf("\n");
}

int main()
{
    freopen("in_6.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V >> M;
    adj.resize(V);
    visited.resize(V, false);
    disc.resize(V, -1);
    low.resize(V, -1);
    
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    articulation_points();
    
    
    return 0;
}
