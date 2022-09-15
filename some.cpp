#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
  vector<int> p;
  
  for(int i=0;i<24;i++)
  p.push_back(i);
  for(auto i=p.rbegin();i!=p.rend();i++)
  cout<<*i<<" ";
  
return 0;
}