// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n, vector<int>(m,0));
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            if(ch=='.') {
                mp[i][j] = 0;
            } else {
                mp[i][j] = 1;
            }
        }
    }
    vector<vector<int>> vis(n, vector<int>(m,0));
    int totalRooms = 0;
    vector<int> dx = {1,  0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mp[i][j]==1 || vis[i][j]==1) continue;
            queue<pair<int,int>> q;
            q.push({i,j});
            totalRooms++;
            vis[i][j] = 1;
            while(!q.empty()) {
                auto tp = q.front();
                q.pop();
                int x = tp.first;
                int y = tp.second;
                for(int k=0;k<4;k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=m) {
                        continue;
                    }
                    if(mp[nx][ny]==1 || vis[nx][ny]==1) {
                        continue;
                    }
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout<<totalRooms;
}