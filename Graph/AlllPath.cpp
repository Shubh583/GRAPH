#include<bits/stdc++.h>
using namespace std;
int n; // no. of vertices
vector<list<int> > graph;
vector<int>ans;
vector<vector<int> > path;
unordered_set<int>visited;
 void addGraph(int src, int dest, bool bidi=true){
    graph[src].push_back(dest);
    // if(bidi){
    //     graph[dest].push_back(src);
    // }

 }
 void anypa(int curr, int dest){
  if(curr==dest){
  ans.push_back(curr);
  path.push_back(ans);
  ans.pop_back();
  return;
 // for(int i=0;i<ans.size();i++)cout<<ans[i]<<"-> "; cout<<endl;
    }
    visited.insert(curr);
     ans.push_back(curr);
       
        for(auto x:graph[curr]){
       if(! visited.count(x)){
            anypa(x,dest);
        }
        }
        ans.pop_back();
        visited.erase(curr); return ;
    }
  void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"-> ";
        for(auto x:graph[i]){
            cout<<x<<" ";
        }
         cout<<endl;
    }
  }
int main(){
 cin>>n;
graph.resize(n, list<int>());
int e ; // no. of edges
cin>>e;
while(e--){
    int s,d;
    cin>>s>>d;
    addGraph(s,d);

}
display();
cout<<endl<<endl;
anypa(0,6);
cout<<endl<<endl;
for(int i=0;i<path.size();i++){
    for(int j=0;j<path[i].size();j++){
        cout<<path[i][j]<<" ";
    } cout<<endl;
}
}
