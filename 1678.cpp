// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, int u, vector<int>& vis, vector<int>& cycle, vector<int>& parent) {
    
    if(vis[u]==2) return;
    if(vis[u] == 1 && cycle.size()==0) {
        for(int x = u;;x=parent[x]) {
            cycle.push_back(x);
            if(cycle.size()>1 && x==u) {
                break;
            }
        }
        return;
    }
    if(vis[u]==1) return;
    vis[u] = 1;
    for(auto v: adj[u]) {
        parent[v] = u;
        dfs(adj, v, vis, cycle, parent);
    }
    
    vis[u] = 2;
}
int main() {
    int n,m,k;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> cycle;
    vector<int> vis(n+1, 0);
    vector<int> parent(n+1, -1);
    for(int i=1;i<=n;i++)
        if(vis[i]==0 && cycle.size()==0)
            dfs(adj, i, vis, cycle, parent);
    if(cycle.size()>0) {
        cout<<cycle.size()<<endl;
        for(int i=cycle.size()-1;i>=0;i--) {
            cout<<cycle[i]<<" ";
        }
    } else {
        cout<<"IMPOSSIBLE";
    }
   
}
