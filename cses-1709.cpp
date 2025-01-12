#include<bits/stdc++.h>
using namespace std;

int adj[500+1][500+1];
int rAdj[500+1][500+1];
vector<int> par(500+1, -1);
vector<bool> vis;
int n, m;
    
bool bfs(int src, int dest) {
    vis = vector<bool>(501, 0);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()) {
        int tp = q.front();
        q.pop();
        for(int j=1;j<=201;j++) {
            if(vis[j] || rAdj[tp][j]==0) continue;
            vis[j] = true;
            if(j==dest) {
                par[dest] = tp;
                return true;
            }
            q.push(j);
            par[j] = tp;
        }
      
    }
    return vis[dest];
}

int main() {
    cin>>n;
    
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            char ch;
            cin>>ch;
            if(ch!='.') {
                adj[0][i] = 1;
                // adj[i][0] = 1;
                // rAdj[i][0]=1;
                rAdj[0][i]=1;
                
                adj[100+j][201] = 1;
                // adj[201][100+j] = 1;
                rAdj[100+j][201]=1;
                // rAdj[201][100+j]=1;
                
                adj[i][100+j]=1e8;
                // adj[100+j][i]=1e8;
                rAdj[i][100+j]=1e8;
                // rAdj[100+j][i]=1e8;
            }
        }
    }
    int maxFlow = 0;
    vector<vector<int>> res;
    int ptr = 0;
    while(bfs(0, 201)) {
        vector<int> res1;
        int target = 201;
        int minFlow = 1e8;
        while(par[target]!=-1) {
            int parTarget = par[target];
            minFlow = min(minFlow, rAdj[parTarget][target]);
            target = par[target];
        }
        target = 201;
        while(par[target]!=-1) {
            res1.push_back(par[target]);
            int parTarget = par[target];
            if(rAdj[parTarget][target]!=1e8) 
                rAdj[parTarget][target]-= minFlow;
            if(rAdj[target][parTarget]!=1e8) 
                rAdj[target][parTarget] += minFlow;
            target = par[target];
        }
        maxFlow += minFlow;
        res.push_back(res1);
    }
    bfs(0, 201);
    
    cout<<maxFlow<<endl;
    for(int i=0;i<=201;i++) {
        for(int j=i+1;j<=201;j++) {
            if(vis[i] && !vis[j] && adj[i][j]) {
                if(j>=1 && j<=n) {
                    cout<<1<<" "<<j<<endl;
                } else if(j==201) {
                    cout<<2<<" "<<i-100<<endl;
                }
            }
        }
    }

}