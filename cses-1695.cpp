#include<bits/stdc++.h>
using namespace std;

int adj[500+1][500+1];
int rAdj[500+1][500+1];
vector<int> par(500+1, 0);
vector<bool> vis;
int n, m;
    
bool bfs(int src, int dest) {
    vis = vector<bool>(501, 0);
    queue<int> q;
    q.push(src);
     vis[src] = true;
    while(!q.empty()) {
        int tp = q.front();
        q.pop();
        for(int j=1;j<=n;j++) {
            if(vis[j] || rAdj[tp][j]==0) continue;
            vis[j] = true;
            if(j==dest) {
                par[dest] = tp;
                return true;
            }
            q.push(j);
            par[j] = tp;
        }
    }
    return vis[dest];
}

int main() {
    cin>>n>>m;
    
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
        rAdj[u][v]=1;
        rAdj[v][u]=1;
    }
    
    while(bfs(1, n)) {
        int target = n;
        int minFlow = n;
        while(par[target]!=0) {
            int parTarget = par[target];
            minFlow = min(minFlow, rAdj[parTarget][target]);
            target = par[target];
        }
        target = n;
        while(par[target]!=0) {
            int parTarget = par[target];
            rAdj[parTarget][target] -= minFlow;
            rAdj[target][parTarget] += minFlow;
            target = par[target];
        }
    }
    bfs(1, n);
    vector<pair<int,int > > res;
    int minCut = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(vis[i] && !vis[j] && adj[i][j]>0) {
                minCut++;
                res.push_back({i,j});
            }
        }
    }
    cout<<minCut<<endl;
    for(int i=0;i<res.size();i++) {
        cout<<res[i].first<<" "<<res[i].second<<endl;
    }
}