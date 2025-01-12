#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    vector<int> vis(n+1, 0);
    vector<int> parent(n+1, -1);
    vis[1] = 1;
    q.push(1);
    bool routeFound = false;
    while(!q.empty()) {
        int tp = q.front();
        q.pop();
        for(int j=0;j<adj[tp].size();j++) {
            if(!vis[adj[tp][j]]) {
                parent[adj[tp][j]] = tp;
                vis[adj[tp][j]] = 1;
                q.push(adj[tp][j]);
            }
        }
    }
    if(parent[n]!=-1) {
        vector<int> finalRoute;
        for(int i=n;i!=-1;i = parent[i]) {
            finalRoute.push_back(i);
        }
        cout<<finalRoute.size()<<endl;
        for(int i=finalRoute.size()-1;i>=0;i--) {
            cout<<finalRoute[i]<<" ";
        }
        cout<<endl;
    } else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}