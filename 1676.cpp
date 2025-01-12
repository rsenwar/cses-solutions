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
    int largest = 1, nc = n;
    for(int i=0; i<m; ++i)
    {
        int u,v,w;
        cin>>u>>v;
        if(dsu.find(u)!=dsu.find(v)) {
            nc--;
        }
        dsu.unionDSU(u,v);
        int sz = dsu.size(u);
        largest = max(largest, sz);
        cout<<nc<<" "<<largest<<endl;
    }
    
}


