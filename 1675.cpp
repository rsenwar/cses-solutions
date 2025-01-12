// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> par;
    vector<int> sz;
  public:
    DSU(int n) {
        par = vector<int>(n, -1);
        for(int i=1;i<n;i++) par[i] = i;
        sz = vector<int>(n, 1);
    }
    int size(int x) {
        return sz[find(x)];
    }
    int find(int x) {
        if(x==par[x]) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    void unionDSU(int x, int y) {
        int px = find(x);
        int py = find(y);
        if(px==py) return;
        
        if(sz[px]<sz[py]) {
            par[px] = py;
            sz[py] += sz[px];
        } else {
            par[py] = px;
            sz[px] += sz[py];
        }
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    DSU dsu(n+1);
    priority_queue<tuple<long long, int,int>, vector<tuple<long long, int,int>>, greater<tuple<long long,int,int>>> pq;
    for(int i=0; i<m; ++i) {
        int u,v,w;
        cin>>u>>v>>w;
        pq.push({w,u,v});
    }
    long long totalCost = 0;
    int totalSize = 0;
    while(!pq.empty()) {
        auto [wt, u, v] = pq.top();
        pq.pop();
        if(dsu.find(u)!=dsu.find(v)) {
            dsu.unionDSU(u,v);
            totalCost += wt;
        }
        totalSize = max(totalSize, dsu.size(u));
    }
    if(totalSize==n) {
        cout<<totalCost;
    } else {
        cout<<"IMPOSSIBLE";
    }
    
}


