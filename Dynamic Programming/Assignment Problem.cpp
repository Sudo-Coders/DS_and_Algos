// Assignment problem
// dp+bitmask
// tutorial geeks for geeks



#include <iostream>
#include <string.h>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int a[23][23];
 unsigned long long int dp[1<<20];
 unsigned long long int allmask;
unsigned long long int func( unsigned long long int mask)
{

   
    if(allmask==mask){
        return 1;
    }
    
    
    
    if(dp[mask]!=-1){
        return dp[mask];
    }
    unsigned long long int ways = 0;
    
   int N =__builtin_popcount(mask);
  // cout << N << endl;
    for(int j=0;j<n;j++)
    {
        if(a[N][j]==1){
            if(mask & (1 << j)) continue;
        
            else{
                //cout <<mask << " " << i << endl; 
                ways = ways + func(mask | (1 << j));
                
                
            }
        }
    }
    dp[mask] = ways;
    return dp[mask];
    
}

int main() {
	int t;
	cin >> t;
	while(t--){
	   
	    cin >> n;
	     allmask = (1<<n)-1;
	    memset(dp,-1,sizeof(dp));
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            cin >> a[i][j];
	        }
	    }
	    
	  unsigned   long long int l = func(0); 
	    cout << l << endl;
	}
	return 0;
}
