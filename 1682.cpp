// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void dfs1(int u, stack<int>& st, vector<int>& vis, vector<vector<int>>& adj) {
    vis[u] = 1;
    
    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs1(v, st, vis, adj);
        }
    }
    st.push(u);
}
void dfs2(int u, vector<int>& vis, vector<vector<int>>& adj) {
    vis[u] = 1;
    for(int v: adj[u]) {
        if(!vis[v]) {
            dfs2(v, vis, adj);
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<vector<int>> rAdj(n+1);
    
    for(int i=0; i<m; ++i) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        rAdj[v].push_back(u);
    }
    stack<int> st;
    vector<int> vis(n+1, 0);
    for(int i=1;i<=n;i++)
        if(!vis[i])
            dfs1(i, st, vis, adj);
    int sc = 0;
    vis = vector<int>(n+1, 0);
    int n1 = st.top(), n2 = -1;
    dfs2(st.top(), vis, rAdj);
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            n2 = i;
            break;
        }
    }
    if(n2==-1) {
        cout<<"YES";
    } else {
        cout<<"NO"<<endl;
        cout<<n2<<" "<<n1<<endl;
    }
}


