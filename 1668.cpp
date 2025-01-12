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
    vector<int> col(n+1, -1);
    queue<int> q;
    
    vector<int> vis(n+1, 0);
    
    bool canAssign = true;
    int totalAssigned = 0;
    for(int j=1;j<=n;j++) {
        if(!vis[j]) {
            vis[j] = 1;
            col[j] = 1;
            q.push(j);
            totalAssigned++;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                
                for(int i=0;i<adj[u].size();i++) {
                    int v = adj[u][i];
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = 1;
                        col[v] = !col[u];
                        totalAssigned++;
                    } else if(col[v]==col[u]) {
                        canAssign = false;
                        break;
                    }
                }
                if(!canAssign) {
                     break;
                }
            }
            if(!canAssign) {
                     break;
            }
        }
    }
    if(!canAssign || totalAssigned<n) {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        for(int i=1;i<=n;i++) {
            if(!col[i]) {
                cout<<2<<" ";
            } else {
                cout<<1<<" ";
            }
        }
        cout<<endl;
    }
    
   
}