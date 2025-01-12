#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    vector<int> revAdj[n+1];
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,-w});
        revAdj[v].push_back(u);
    }
    vector<long long> dist(n+1, LLONG_MAX);
    dist[1] = 0;
    set<int> st;
    for(int i=1;i<=n;i++) {
        for(auto& it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=LLONG_MAX && dist[u]+wt<dist[v]) {
                if(i==n) {
                    st.insert(v);
                }
                dist[v] = dist[u] + wt;
            }
        }
    }
    bool posCycle = false;
    if(st.size()>0) {
        vector<int> vis(n+1, 0);
        queue<int> q;
        q.push(n);
        vis[n] = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            if(st.find(u)!=st.end()) {
                posCycle = true;
                break;
            }
            for(auto v: revAdj[u]) {
                if(!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
        if(posCycle) {
            cout<<-1<<endl;
        } else {
            cout<<-dist[n]<<endl;
        }
    } else {
        cout<<-dist[n]<<endl;
    }
}