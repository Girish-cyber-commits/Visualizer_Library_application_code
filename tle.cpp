#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
#define rep(i,x,y) for(ll i=x;i<=y;i++)
#define yy pair<ll,ll>
int main() {
  int n,m;
  cin>>n>>m;
  vector<yy>adj[n];
  rep(i,0,m-1){
    int a,b,c;
    cin>>a>>b>>c;
    --a,--b;
    adj[a].push_back({c,b});
  }
vector<ll>dist(n,1e18);
dist[0]=0;
priority_queue<yy,vector<yy>,greater<yy>>pq;
pq.push({0,0});//dist ,node
while(!pq.empty()){
  auto node=pq.top();
  pq.pop();
  if(dist[node.second]<node.first)
      continue;
    for(auto child:adj[node.second]){
       if(dist[child.second]>node.first+child.first){
          dist[child.second]=node.first+child.first;
        pq.push({dist[child.second],child.second});
      }
    }
} 
rep(i,0,n-1)cout<<dist[i]<<" ";
}