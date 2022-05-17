#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ar array
#define mxn 1e5+2
 
 
int main() {
  // main idea is if total of node is outside finally it has to be source and vicecersa
  //pair a source with all possible sinks while it's weight is fulfilled
  int n, m;
  cin >> n >> m ;
  vector<ar<int,2>>adj[n];//final graph->first distance and second is the node in adj[i]
  vector<int>total(n,0);//net debt
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a,--b;
    total[a]+=c;
    total[b]-=c;
  }
 //delete the data in whole graph and make it empty if it is passed from main
 // may not be optimal but still... 
 //outnode->total pointing out
 //innode-> total pointing in
 //waste->total==0 so not pointing but still making it a sink by pointing a zero weight edge from one of
 //the outnode 
  vector<int>outnode,innode,waste;
  for(int i=0;i<n;i++){
    if(total[i]<0){
      innode.push_back(i);
      total[i]*=-1; //for easiness of the sol'n
    }
    else if(total[i]>0)outnode.push_back(i);
    else waste.push_back(i);
  }
  if(waste.size()==n){ //edge case where everyone is taking and giving exactly same
     for(auto i=1;i<waste.size();i++){//for the node with total '0' and they act as sink
    adj[0].push_back({0,i});
  }
  cout<<"node1 "<<"node2 "<<"weight "<<endl;
  for(int i=0;i<n;i++){
    for(auto j:adj[i]){
      cout<<i+1<<" "<<j[1]+1<<" "<<j[0]<<endl;
  }
}
exit(0);
}
   int posofoutnode=0,posofinnode=0,left=total[innode[0]];
   //position of the pointer in the vector and left is the amount that can still be accomidated in the innode
  while(posofoutnode<outnode.size()){
    if(total[outnode[posofoutnode]]<=left){
       adj[outnode[posofoutnode]].push_back({total[outnode[posofoutnode]],innode[posofinnode]});
       left-=total[outnode[posofoutnode]];
       posofoutnode++;
    }else{
      adj[outnode[posofoutnode]].push_back({left,innode[posofinnode]});
      total[outnode[posofoutnode]]-=left;
       posofinnode++;
       left=total[innode[posofinnode]];
    }
  }
  int k=outnode[0];
  for(auto i:waste){//for the node with total '0' and they act as sink
    adj[k].push_back({0,i});
  }
  cout<<"node1 "<<"node2 "<<"weight "<<endl;
  for(int i=0;i<n;i++){
    for(auto j:adj[i]){
      cout<<i+1<<" "<<j[1]+1<<" "<<j[0]<<endl;
    }
  }
}