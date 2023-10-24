#include<bits/stdc++.h>
using namespace std;
int n;
vector<unordered_map<int, int> >mp;
void addG(int src, int dest,  int wet,bool bid=true){
    mp[src][dest]=wet;
    if(bid){
        mp[dest][src]=wet;
    }
}
 void display(){
    for(int i=0;i<mp.size();i++){
        cout<<i<<" -> ";
        for(auto x: mp[i]){
            cout<<x.first<<","<<x.second<<",";
        } cout<<endl;
    }
 }
int main(){
    cin>>n;
    mp.resize(n,unordered_map<int,int>());
    int e;
    cin>>e;
    while(e--){
        int s,d,w;
        cin>>s>>d>>w;
        addG(s,d,w);
    }
    display(); 
}