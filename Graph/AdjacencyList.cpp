#include<bits/stdc++.h>
using namespace std;
int n; // no. of vertices
vector<list<int> > graph;
 void addGraph(int src, int dest, bool bidi=true){
  
    graph[src].push_back(dest);
    if(bidi){
        graph[dest].push_back(src);
    }

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
}
