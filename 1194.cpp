#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> mp(n, vector<int>(m, 0));
    queue<pair<int,pair<int,int>>> q;
    int path[1000][1000];
    int stX = -1, stY = -1;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            if(ch=='#') {
                mp[i][j] = 1;
            } else if(ch == 'A') {
                mp[i][j] = -1;
                stX = i, stY = j;
                path[i][j] = -1;
            } else if(ch=='M') {
                mp[i][j] = -2;
                q.push({2, {i,j}});
            }
        }
    }
    q.push({1, {stX, stY}});
    vector<int> dx = {1,0,-1,0};
    vector<int> dy = {0,1,0,-1};
    vector<char> dir = {'D', 'R', 'U', 'L'}; 
    pair<int,int> destXY;
    bool pathFound = false;
    while(!q.empty()) {
        int sz = q.size();
        
        for(int i=0;i<sz;i++) {
            auto tp = q.front();
            q.pop();
            int character = tp.first;
            pair<int,int> pos = tp.second;
            for(int j=0;j<4;j++) {
                int nx = pos.first + dx[j];
                int ny = pos.second + dy[j];
                if(nx<0 || ny<0 || nx>=n || ny>=m || mp[nx][ny]==1) {
                    continue;
                }
                if(character==2) {
                    if(mp[nx][ny]==-2) continue;
                    mp[nx][ny] = -2;
                    q.push({2, {nx,ny}});
                } else {
                    
                    if(mp[nx][ny]==-1 || mp[nx][ny]==2 || mp[nx][ny]==-2) continue;
                    path[nx][ny] = j;
                    if(nx==0 || ny==0 || nx==n-1 || ny==m-1) {
                        pathFound = true;
                        destXY = {nx, ny};
                        break;
                    }
                    mp[nx][ny] = 2;
                    q.push({1,{nx, ny}});
                }
            }
            if(pathFound) {
                break;
            }
        }
    }
    if(stX==0 || stX==n-1 || stY==0 || stY==m-1) {
        cout<<"YES"<<endl;
        cout<<0<<endl;
    } else if(!pathFound) {
        cout<<"NO"<<endl;
    } else {
        vector<char> pathRoute;
        cout<<"YES"<<endl;
        while(path[destXY.first][destXY.second]!=-1) {
            int pathDir = path[destXY.first][destXY.second];
            pathRoute.push_back(dir[pathDir]);
            destXY.first -= dx[pathDir];
            destXY.second -= dy[pathDir];
        }
        cout<<pathRoute.size()<<endl;
        for(int i=pathRoute.size()-1;i>=0;i--) {
            cout<<pathRoute[i];
        }
    }
}