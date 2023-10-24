
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool flag=true;
vector<vector<int> > dir={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int findstep(int sr,int sc, int dr,int dc){
 queue<pair<int,int>>pq;
 vector<vector<bool> > visited(100,vector<bool>(100,false));
 pq.push({sr,sc});
 visited[sr][sc]=true;
 int ans=0;
 while(!pq.empty()){
    int size=pq.size();
    ans++;
    while(size--){
auto cell=pq.front(); pq.pop();
int cr=cell.first;
int cc=cell.second;

for(int i=0;i<8;i++){
    int r=cr+dir[i][0];
    int c=cc+dir[i][1];
    if(r<0 || c<0 || r>100 || c>100)continue;
    if(r==dr && c==dc)flag=false;
 if(visited[r][c]==true)continue;
else {
    visited[r][c]=true;
    pq.push({r,c});  
}
}}
if(flag==false)break;
 }
 return ans;
}
int main(){
    int sr,sc;
    int dr; int dc;   
    cin>>sr>>sc>>dr>>dc;
cout<<findstep(sr,sc,dr,dc)<<" ";
}