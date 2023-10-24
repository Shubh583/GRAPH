#include<bits/stdc++.h>
using namespace std;
int row,col;
vector<vector<bool> > visited;
queue<pair<int,int>>q;
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
 void dfs(vector<vector<int>>& grid){
    while(q.size()>0){
        auto cell = q.front(); q.pop();
   for(int i=0;i<4;i++){
    int r=cell.first+dir[i][0];
    int c=cell.second+dir[i][1];
    if(r<0 || c<0 || r>=row || c>=col)continue;
    if(grid[r][c]==-1 || visited[r][c]==true)continue;
    visited[r][c]=true;
    grid[r][c]=1+grid[cell.first][cell.second];
    q.push({r,c});
   }
    }
 }
void finddiss(vector<vector<int>>& grid){
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(grid[i][j]==0 and visited[i][j]==false){
            q.push({i,j}); visited[i][j]=true;
           }   
    }
       
    }dfs(grid); 
}

int main(){
    int r,c;
    cin>>r>>c;
    row=r; col=c;
    visited.resize(r,vector<bool>(c,false));
    vector<vector<int>>v(r,vector<int>(c,-1));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    finddiss(v);
     for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<v[i][j]<<" ";
        }cout<<endl;
    }
}