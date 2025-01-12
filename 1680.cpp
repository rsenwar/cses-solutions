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
    vector<int> d(n+1,INT_MIN);

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
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : adj[u])
        {
            if(d[u]+1>d[v])
            {
                d[v]=1+d[u];
                parent[v]=u;
            }
            in_degree[v]--;
            if(in_degree[v]==0) {
                q.push(v);
            }
        }
    }
    if(d[n]<0)
    {
        cout<<"IMPOSSIBLE"<<endl;
    } else {
        vector<int> ans;
        for(int x=n;;x=parent[x]) {
            ans.push_back(x);
            if(x==1) {
                break;
            }
        }
        cout<<ans.size()<<endl;
        for(int i=ans.size()-1; i>=0; i--)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}
int main()
{
    solve();
}