// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> in_degree(n+1,0);
    vector<int> parent(n+1, -1);
    vector<vector<int> > adj(n+1);
    vector<int> d(n+1,0);

    for(int i=0; i<m; ++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++) {
        if(in_degree[i]==0) {
            q.push(i);
        }
    }
    d[1] = 1;
    int mod = 1e9 + 7;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            d[v]=(d[u]+d[v])%mod;
            in_degree[v]--;
            if(in_degree[v]==0) {
                q.push(v);
            }
        }
    }
    cout<<d[n];
}
int main()
{
    solve();
}