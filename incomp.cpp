#include <bits/stdc++.h>
using namespace std;
 


vector<int> stableMariage(const vector<vector<int>> &menPreff, const vector<vector<int>> &womenPreff)
{                             ///small                              //large
    const int N = menPreff.size();//n is always small 
    const int M= womenPreff.size();
    vector<vector<int>> mapWomanToMan(M);//mapWomanToMan gives the pos of man in womens list and vice versa
 
    for (int i = 0; i < M; ++i)
        mapWomanToMan[i].resize(N);
 
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            mapWomanToMan[i][ womenPreff[i][j] ] = j; //more size preference
 
    vector<int> womanMatch(M, -1);
    vector<int> manMatch(N, -1);
 
    queue<int> bachelors;//push all those in queue whose grp has small size
 
    for (int i = 0; i < N; ++i)
        bachelors.push(i);
 
    while (!bachelors.empty())
    {
        int man = bachelors.front();
        bachelors.pop();
 
        for (int woman : menPreff[man])
        {
            if (womanMatch[woman] == -1) /// woman is free
            {
                womanMatch[woman] = man;
                manMatch[man] = woman;
                break;
            }
            else
            {
                int otherMan = womanMatch[woman];
 
                if (mapWomanToMan[woman][otherMan] > mapWomanToMan[woman][man])
                {
                    manMatch[otherMan] = -1; /// free the other man and check
                    bachelors.push(otherMan);
 
                    womanMatch[woman] = man;
                    manMatch[man] = woman;
                    break;
                }
            }
        }
    }
 ///////////////
    ///TIME COMPLEXITY of the algo is (min(n,m))^2 from the loops and also from logic
//////////////////

    return manMatch;
}
 

int main()
{
 
 
        int N,M;//no of men and women respectively
        cin>>N>>M;
 
        vector<vector<int>> menPreffs(N), womenPreffs(M);
 //womwnpreffs[i] is the preference list of women i and vice versa

        for (int i = 0; i < M; ++i)//input of womens preference list
        {
            womenPreffs[i].resize(N);
       
 
            for (int j = 0; j < N; ++j)
            {
               cin>> womenPreffs[i][j];
                womenPreffs[i][j]--;
            }
        }
 
        for (int i = 0; i < N; ++i)
        {
            menPreffs[i].resize(M);
            
 
            for (int j = 0; j < M; ++j)//input of mens preference list
            {
               cin>> menPreffs[i][j];
                menPreffs[i][j]--;
            }
        }
        vector<int> marriages;//stores who will be married to 
        if(N<=M)
        marriages = stableMariage(menPreffs, womenPreffs);
      else
        marriages = stableMariage(womenPreffs,menPreffs);
      // printing order is mens first and womens second
     if(N<=M)
      for (int i = 0; i < min(N,M); ++i)
            printf("%d %d\n", i + 1, marriages[i] + 1);
      else
        for (int i = 0; i < min(N,M); ++i)
            printf("%d %d\n", marriages[i] + 1, i + 1);
 
    return 0;
}
 