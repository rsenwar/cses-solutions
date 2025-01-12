#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> p;
    vector<int> sz;
    public:
    DSU(int n) {
        p = vector<int>(n+1, -1);
        for(int i=1;i<=n;i++) p[i] = i;
        sz = vector<int>(n+1, 1);
    }
    int find(int x) {
        if(p[x]==x) {
            return x;
        }
        return p[x] = find(p[x]);
    }
    vector<int> findReps() {
        vector<int> reps;
        for(int i=1;i<p.size();i++) {
            if(p[i]==i) {
                reps.push_back(i);
            }
        }
        return reps;
    }
    void unionDSU(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if(rx==ry) return;
        if(sz[rx]<sz[ry]) {
            p[rx] = ry;
            sz[rx] += sz[ry];
        } else {
            p[ry] = rx;
            sz[ry] += sz[rx];
        }
    }
};

int main() {
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        dsu.unionDSU(u,v);
    }
    int rep1 = -1, rep2 = -1;
    if(dsu.findReps().size()>2) {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        for(int i=1;i<=n;i++) {
            int rep = dsu.find(i);
            if(rep1==-1 || rep1 == rep) {
                rep1 = rep;
                cout<<1<<" ";
            } else if(rep2 == -1 || rep2 == rep) {
                rep2 = rep;
                cout<<2<<" ";
            }
        }
    }
   
}