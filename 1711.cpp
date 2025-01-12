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
        cin>>u>>v;
        rAdj[u].push_back(v);
        rAdj[v].push_back(u);
        cap[u][v] = 1;
    }
    long long maxFlow = 0;
    vector<vector<int>> paths;
    while(bfs(source, rAdj, sink, cap)) {
        int x = sink;
        long long minFlow = LLONG_MAX;
        while(x!=source) {
            int parX = par[x];
            minFlow = min(minFlow, cap[parX][x]);
            x = par[x];
        }
        x = sink;
        vector<int> currPath;
        while(x!=source) {
            int parX = par[x];
            currPath.push_back(x);
            cap[parX][x] -= minFlow;
            cap[x][parX] += minFlow;
            x = par[x];
        }
        currPath.push_back(source);
        reverse(currPath.begin(), currPath.end());
        paths.push_back(currPath);
        maxFlow += minFlow;
    }
    cout<<paths.size()<<endl;
    for(int i=0;i<paths.size();i++) {
        cout<<paths[i].size()<<endl;
        for(int j:paths[i]) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
}



