#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using namespace std;
using namespace __gnu_pbds;
 
 
#define ll long long
#define endl "\n"
#define rep(i,x,y) for(int i=x; i<=y; i++)
const int mxn=1e6+1;
const int mod=1e9+7;
 
 
void task() {
 int n,m;
 cin>>n>>m;
 vector<int>adj[n];
 rep(i,0,m-1){
  int a,b;
  cin>>a>>b;
  --a,--b;
  adj[a].push_back(b);
  adj[b].push_back(a);
 }
vector<int>ans;
vector<int>par(n,-1);
queue<int>q;
q.push(0);
while(!q.empty()){
  int si=q.size();
  while(si--){
    int node=q.front();
    q.pop();
    for(int child:adj[node]){
      if(par[child]!=-1)continue;
       q.push(child);
       par[child]=node;
    }
  }
}
if(par[n-1]==-1){
  cout<<"IMPOSSIBLE"<<endl;
  return;
} 
int node=n-1;
while(node){
  ans.push_back(node);
  node=par[node];
}
ans.push_back(0);
reverse(ans.begin(),ans.end());
cout<<ans.size()<<endl;
for(auto i:ans)cout<<i+1<<" ";
  cout<<endl;
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  int l=1;
  // cin >> l;
  for (int i = 0; i < l; i++) {
    task();
  }
}