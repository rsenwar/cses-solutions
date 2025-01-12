// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int> > adj[n+1];
    vector<long long> d(n+1,LLONG_MAX);
    vector<int> min_f(n+1, INT_MAX);
    vector<int> max_f(n+1, INT_MIN);
    vector<int> total_f(n+1, 0);

    for(int i=0; i<m; ++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }

    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>> > pq;
    pq.push({0,1});
    d[1] = 0;
    min_f[1] = 0;
    max_f[1] = 0;
    total_f[1] = 1;
    int mod = 1e9 + 7;
    while(!pq.empty())
    {
        auto [price, u] = pq.top();
        pq.pop();
        if(price>d[u]) continue;
        
        for(auto& [v, wt]: adj[u]) {
            if(d[u] + wt == d[v]) {
                min_f[v] = min(min_f[v], 1+min_f[u]);
                max_f[v] = max(max_f[v], 1+max_f[u]);
                total_f[v] = (total_f[v] + total_f[u])%mod;
            } else if(d[u]+wt<d[v]) {
                min_f[v] = min_f[u] + 1;
                max_f[v] = max_f[u] + 1;
                total_f[v] = total_f[u];
                d[v] = d[u] + wt;
                pq.push({d[v],v});
            }
        }
    }
    cout<<d[n]<<" "<<total_f[n]<<" "<<min_f[n]<<" "<<max_f[n];
}


