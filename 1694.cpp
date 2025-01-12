#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> par;
vector<int> vis;
bool bfs(int source, vector<vector<int>>& rAdj, int sink, vector<vector<long long>>& cap) {
    par = vector<int>(n+1,-1);
    queue<int> q;
    q.push(source);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: rAdj[u]) {
            if(cap[u][v]<=0) continue;
            if(par[v]==-1) {
                par[v] = u;
                q.push(v);
            }
        }
    }
    return par[sink]!=-1;
}

int main() {
    cin>>n>>m;
    vector<vector<int>> rAdj(n+1);
    vector<vector<long long>> cap(n+1, vector<long long>(n+1, 0));
    int source = 1, sink = n;
    
    for(int i=0;i<m;i++) {
        int u, v;
        long long d;
        cin>>u>>v>>d;
        rAdj[u].push_back(v);
        rAdj[v].push_back(u);
        cap[u][v] += d;
    }
    long long maxFlow = 0;
    while(bfs(source, rAdj, sink, cap)) {
        int x = sink;
        long long minFlow = LLONG_MAX;
        while(x!=source) {
            int parX = par[x];
            minFlow = min(minFlow, cap[parX][x]);
            x = par[x];
        }
        x = sink;
        while(x!=source) {
            int parX = par[x];
            cap[parX][x] -= minFlow;
            cap[x][parX] += minFlow;
            x = par[x];
        }
        maxFlow += minFlow;
    }
    cout<<maxFlow;
}



