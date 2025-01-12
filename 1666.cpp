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
    vector<int> reps;
    int totalComp = 0;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            totalComp++;
            vis[i] = 1;
            reps.push_back(i);
            q.push(i);
            while(!q.empty()) {
                int tp = q.front();
                q.pop();
                for(int j=0;j<adj[tp].size();j++) {
                    if(!vis[adj[tp][j]]) {
                        vis[adj[tp][j]] = 1;
                        q.push(adj[tp][j]);
                    }
                }
            }
        }
    }
    cout<<totalComp-1<<endl;
    for(int i=0;i<reps.size()-1;i++) {
        cout<<reps[i]<<" "<<reps[i+1]<<endl;
    }
}