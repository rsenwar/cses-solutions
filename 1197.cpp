// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,int>> edges;
    for(int i=0;i<m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    vector<long long> dist(n+1, 1e18);
    vector<int> parent(n+1, -1);
    dist[1] = 0;
    int l_node = -1;
    for(int i=0;i<n;i++) {
        l_node = -1;
        for(auto& [u,v,w]: edges) {
            if(dist[v]> dist[u] + w) {
                dist[v] = dist[u] + w;
                 parent[v] = u;
                 l_node = v;
            }
           
        }
    }
    
    if(l_node == -1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
        int x = l_node;
        for(int i=0;i<n;i++) {
            x = parent[x];
        }
        
        vector<int> cycle;
        for(int c_node = x;;c_node=parent[c_node]) {
            cycle.push_back(c_node);
            if(cycle.size()>1 && c_node == x) {
                break;
            }
        }
        for(int i=cycle.size()-1;i>=0;i--) {
            cout<<cycle[i]<<" ";
        }
    }
}







