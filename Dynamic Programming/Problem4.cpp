// spoj problem  PROBLEM4
// min max algorithm
    
    
    #include <iostream>
    #include <string.h>
    #include <stdio.h>
    using namespace std;
    int n;
    int a[34];
    long long int dp[34][34];
    long long int dp1[34][34][2];
    long long int func(int i, int j)
    {
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i>j)
        {
            return 0;
        }
        if(i==j)
        {
            return a[i];
        }
        long long int k,l;
        if(a[i+1]<a[j]){
            k = a[i] + func(i+2,j); 
        }
        else if(a[i+1]>=a[j]){
            k = a[i] + func(i+1,j-1); 
        }
        
        if(a[j-1]<a[i]){
            l = a[j] + func(i,j-2); 
        }
        else if(a[j-1]>=a[i]){
            l = a[j] + func(i+1,j-1); 
        }
        dp[i][j] = max(k,l);
        return dp[i][j];
        
    }
    
     long long int func1(int i,int j,int chance)
    {
        if(dp1[i][j][chance]!=-1)
        {
            return dp1[i][j][chance];
        }
        if(i>j)
        {
            return 0;
        }
        if(i==j && chance== 0)
        {
            return a[i];
        }
        else if(i==j && chance==1)
        {
            return 0;    
        }
        if(chance==0)
        {
            dp1[i][j][chance] = max(a[i]+func1(i+1,j,1),a[j] + func1(i,j-1,1));
            return dp1[i][j][chance];
        }
        if(chance==1)
        {
            dp1[i][j][chance] = min(func1(i+1,j,0),func1(i,j-1,0));
            return dp1[i][j][chance];
        }
        
        
    }
    
    
    
     long long int func4(int i,int j,int chance)
    {
        if(dp1[i][j][chance]!=-1)
        {
            return dp1[i][j][chance];
        }
        if(i>j)
        {
            return 0;
        }
        if(i==j && chance== 0)
        {
            return a[i];
        }
        else if(i==j && chance==1)
        {
            return 0;    
        }
        if(chance==0)
        {
            dp1[i][j][chance] = max(a[i]+func4(i+1,j,1),a[j] + func4(i,j-1,1));
            return dp1[i][j][chance];
        }
        if(chance==1)
        {
            dp1[i][j][chance] = max(func4(i+1,j,0),func4(i,j-1,0));
            return dp1[i][j][chance];
        }
        
        
    }
    
    
    
   
    int main() {
    	int t;
    	cin >> t;
    	while(t--)
    	{
    	    cin >> n;
    	    memset(dp,-1,sizeof(dp));
    	    memset(dp1,-1,sizeof(dp1));
    	    int total = 0;
    	    for (int i = 0; i < n; i++) {
    	        cin >> a[i];
    	        total+=a[i];
    	    }
    	    long long int k = func4(0,n-1,0);
    	    memset(dp1,-1,sizeof(dp1));
    	     printf("%lld ",k);
    	    k = func1(0,n-1,0);
    	    printf("%lld\n",k);
    	}
    	
    	return 0;
    }

