#include<bits/stdc++.h>
using namespace std;

int adj[500+1][500+1];
long rAdj[500+1][500+1];
vector<int> par(500+1, -1);
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
    
    for(int i=1;i<=m;i++) {
       int u,v,d;
       cin>>u>>v>>d;
       adj[u][v] += d;
       rAdj[u][v] += d;
    }
    long maxFlow = 0;
    vector<vector<int>> res;
    int ptr = 0;
    while(bfs(1, n)) {
        vector<int> res1;
        int target = n;
        long minFlow = LONG_MAX;
        while(par[target]!=-1) {
            int parTarget = par[target];
            minFlow = min(minFlow, rAdj[parTarget][target]);
            target = par[target];
        }
        target = n;
        while(par[target]!=-1) {
            res1.push_back(par[target]);
            int parTarget = par[target];
            rAdj[parTarget][target]-= minFlow;
            rAdj[target][parTarget] += minFlow;
            target = par[target];
        }
        maxFlow += minFlow;
        res.push_back(res1);
    }
    
    cout<<maxFlow<<endl;
    // for(int i=0;i<=201;i++) {
    //     for(int j=i+1;j<=201;j++) {
    //         if(vis[i] && !vis[j] && adj[i][j]) {
    //             if(j>=1 && j<=n) {
    //                 cout<<1<<" "<<j<<endl;
    //             } else if(j==201) {
    //                 cout<<2<<" "<<i-100<<endl;
    //             }
    //         }
    //     }
    // }

}