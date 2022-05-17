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
const int dx[4]={1,0,-1,0};
const int dy[4]={0,-1,0,1};
const char dc[4]={'D','L','U','R'};

//this can be done by bfs 
// from the initial point find the min dist to all points in the grid using queue
// by traversing all possible directions
//store how you came here to retrace the path 
void task() {
  int n,m;//no of rows and cols respectively
  cin>>n>>m;
  char s[n][m];
  rep(i,0,n-1){
    rep(j,0,m-1)cin>>s[i][j];
  }
int sx,sy,ex,ey; //source and destination
cin>>sx>>sy;
cin>>ex>>ey;
s[sx][sy]='#';
if(s[ex][ey]=='#'){
  cout<<"can't reach"<<endl;
  return;
}

int par[n][m]; //how u came here is stored here
rep(i,0,n-1)
rep(j,0,m-1)par[i][j]=-1;
queue<pair<int,int>>q;
q.push({sx,sy});
while(!q.empty()){
  int si=q.size();
  while(si--){
    pair<int,int>x=q.front();
    q.pop();
    rep(k,0,3){
      int nx=x.first+dx[k],ny=x.second+dy[k];
      if(nx>=0 && nx<n && ny>=0 && ny<m  && s[nx][ny]=='_'){
         s[nx][ny]='#';
         par[nx][ny]=k;
         q.push({nx,ny});
      }
    }
  }  
 }
if(par[ex][ey]==-1){
  cout<<"can't reach"<<endl;
  return;
} 
string ans;
while(sx^ex || sy^ey){
  int num=par[ex][ey];
  ans+=dc[num];
  ex-=dx[num];ey-=dy[num];
}
cout<<"Shortest distance is "<<ans.size()<<endl;
reverse(ans.begin(),ans.end());
cout<<"order of steps to reach it is "<<ans<<endl;
}
 
int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
    task();
  }
