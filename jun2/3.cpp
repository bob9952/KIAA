#include <bits/stdc++.h>

using namespace std;

struct Graph{
    int V;
    vector<vector<int>> adj;
    vector<int> degrees;
    vector<int> path;
};

void init_graph(Graph& g, int V)
{
    g.V = V;
    g.adj.resize(V);
    g.degrees.resize(V, 0);
}

void add_edge(Graph& g, int u, int v)
{
    g.adj[u].push_back(v);
    g.degrees[v] += 1;
}

bool khan(Graph& g)
{
    queue<int> q;
    for(int i = 0; i < g.V; i++)
        if(g.degrees[i] == 0)
            q.push(i);
    
    int tmp;
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        
        g.path.push_back(tmp);
        
        for(int v : g.adj[tmp])
        {
            g.degrees[v]--;
            if(g.degrees[v] == 0)
                q.push(v);
        }
    }
    
    for(int i = 0; i < g.V; i++)
        if(g.degrees[i] != 0)
            return false;
    return true;
}

void solve(Graph& g)
{
    bool res = khan(g);
    if(res)
    {
        cout << "DA" << endl;
        //cout << g.s.size() << endl;
        for(int x : g.path)
            cout << x+1 << endl;
    }
    else
        cout << "NE" << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Graph g;
    int V = 0;
    cin >> V;
    init_graph(g, V);
    
    for(int i = 0; i < V; i++)
    {
        int M;
        cin >> M;
        for(int j = 0; j < M; j++)
        {
            int u;
            cin >> u;
            u--;
            add_edge(g, u, i);
        }
    }
    
    solve(g);
    
    return 0;
}
