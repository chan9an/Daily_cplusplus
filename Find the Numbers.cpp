#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool sol(int ind,int p,int s,int k, vector<int> &fact, vector<int> &ans){
    if(s==0&&p==1&&k==0)
    return 1;
    
    else if(p==0||s<0||k<0||ind==fact.size())
    return 0;
    
    if(p%fact[ind]==0&&sol(ind,p/fact[ind],s-fact[ind],k-1,fact,ans)){
        ans.push_back(fact[ind]);
        return 1;
    }
    else if(sol(ind+1,p,s,k,fact,ans))
    return 1;
    
    else
    return 0;
    
}

int main() {
	  int s,p,k;
	  cin>>s>>p>>k;
	  
	  vector<int>fact,ans;
	  for(int i=1;i<s;i++){
	      if(p%i==0)
	      fact.push_back(i);
	  }
	  if(sol(0,p,s,k,fact,ans))
	  {
	      for(int i=0;i<ans.size();i++)
	      cout<<ans[i]<<" ";
	  }
	  else
	  cout<<"NO";
	
	  return 0;
}
