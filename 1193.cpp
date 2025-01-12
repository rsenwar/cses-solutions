#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n, vector<int>(m,0));
    pair<int,int> start, dest;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            if(ch=='.') {
                mp[i][j] = 0;
            } else if(ch=='#') {
                mp[i][j] = 1;
            } else if(ch=='A') {
                mp[i][j] = -1;
                start = {i,j};
            } else {
                mp[i][j] = -2;
                dest = {i,j};
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<int> dx = {1,  0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
    vector<char> dir = {'D', 'L', 'U', 'R'};
    queue<pair<pair<int,int>, vector<int>>> q;
    q.push({start, {}});
    vis[start.first][start.second] = 1;
    bool destReached = false;
    string destPath = "";
    while(!q.empty()) {
        int sz = q.size();
       
        for(int i=0;i<sz;i++) {
            auto tp = q.front();
            q.pop();
            
            int x = tp.first.first;
            int y = tp.first.second;
            vector<int> path = tp.second;
            
            for(int j=0;j<4;j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                
                if(nx<0 || ny<0 || nx>=n || ny>=m) {
                    continue;
                }
                if(mp[nx][ny]==1 || vis[nx][ny]==1) {
                    continue;
                }
                vis[nx][ny] = 1;
                if(mp[nx][ny]==-2) {
                    destReached = true;
                    for(int k=0;k<path.size();k++) {
                        destPath += dir[path[k]];
                    }
                    destPath += dir[j];
                    break;
                }
                path.push_back(j);
                q.push({{nx, ny},path});
                path.pop_back();
            }
            if(destReached) {
                break;
            }
        }
        if(destReached) {
            break;
        }
    }
    if(destReached) {
        cout<<"YES"<<endl;
        cout<<destPath.size()<<endl;
        cout<<destPath<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}