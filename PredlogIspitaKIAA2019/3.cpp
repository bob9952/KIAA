#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 5;

typedef pair<int,int> pii;

struct Graph{
    int V;
    vector<vector<pii>> adj;   
};

struct compare{
    bool operator()(const pii& a, const pii& b)
    {
        return a.second > b.second;
    }
};

void init_graph(Graph &g, int V)
{
    g.V=V;
    g.adj.resize(V);
}

void add_edge(Graph& g, int u,int v, int w)
{
    g.adj[u].push_back({v,w});
    g.adj[v].push_back({u, w});
}

void prim(Graph& g)
{
    priority_queue<pii, vector<pii>, compare> pq;
    vector<int> key(g.V, INF);
    vector<int> parent(g.V, -1);
    vector<bool> inMST(g.V, false);
    
    long total = 0;
    pq.push({0, 0});
    key[0] = 0;
    
    while(!pq.empty())
    {
        int u = pq.top().first;
        pq.pop();

        inMST[u] = true;

        for(auto nei : g.adj[u])
        {
            int v = nei.first;
            int wei = nei.second;
            
            if(!inMST[v] && key[v] > wei)
            {
                key[v] = wei;
                pq.push({v, key[v]});
                parent[v] = u;
            }
        }
    }
    
    for(int i = 1; i < g.V; i++)
    {    
        cout << parent[i]+1 << " " << i+1 << endl;
        total += (-key[i]);
    }   
    cout << total << endl;
}


int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Graph g;
    int V, M;
    cin >> V >> M;
    
    init_graph(g, V);
    
    for(int i = 0; i < M; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        add_edge(g, u, v, -w);
    }
    
    prim(g);
    
    return 0;
}
