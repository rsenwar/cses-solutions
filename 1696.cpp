#include <bits/stdc++.h>
using namespace std;

int n,m,k;
vector<int> par;
vector<int> vis;
bool bfs(int src, vector<vector<int>>& rAdj, int dest) {
    vis = vector<int>(n+m+2,0);
    par = vector<int>(n+m+2,-1);
    
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v=0;v<=n+m+1;v++) {
            if(rAdj[u][v]==0) continue;
            if(!vis[v]) {
                par[v] = u;
                vis[v] = 1;
                if(v == dest) {
                    return true;
                }
               q.push(v);
            }
        }
    }
    return vis[dest];
}

int main() {
    cin>>n>>m>>k;
    vector<vector<int>> adj(n+m+2, vector<int>(n+m+2, 0));
    vector<vector<int>> rAdj(n+m+2, vector<int>(n+m+2, 0));
    int source = 0, sink = n+m+1;
    for(int i=1;i<=n;i++) {
        adj[0][i] = 1;
        rAdj[0][i] = 1;
    }
    for(int i=n+1;i<=n+m;i++) {
        adj[i][n+m+1] = 1;
        rAdj[i][n+m+1] = 1;
    }
    for(int i=0;i<k;i++) {
        int u, v;
        cin>>u>>v;
        adj[u][v+n] = 1;
        rAdj[u][v+n] = 1;
    }
    
    while(bfs(source, rAdj, sink)) {
        int x = n+m+1;
        int minFlow = INT_MAX;
        while(x!=0) {
            int parX = par[x];
            minFlow = min(minFlow, rAdj[parX][x]);
            x = par[x];
        }
        x = n+m+1;
        while(x!=0) {
            int parX = par[x];
            rAdj[parX][x] -= minFlow;
            rAdj[x][parX] += minFlow;
            x = par[x];
        }
    }
    bfs(source, rAdj, sink);
    vector<pair<int,int>> res;
    for(int i=1;i<=n;i++) {
        for(int j=n+1;j<=n+m;j++) {
            if(adj[i][j]>0 && rAdj[j][i]>0) {
                res.push_back({i,j-n});
            }
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++) {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
}