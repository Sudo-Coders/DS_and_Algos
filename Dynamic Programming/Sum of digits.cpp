// DP sum of digits problem
// maths + dp
// tutorial geeks for geeks
// http://www.geeksforgeeks.org/count-sum-of-digits-in-numbers-from-1-to-n/



#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
int dp[12];
long long int func(int n)
{
    
        if(n<=9)
        {
            return (n*(n+1))/2;    
        }
    
        int d = log10(n);
        long long int a[d+1];
         a[0] = 0, a[1] = 45;
         for(int i=2;i<=d;i++)
         {
             a[i] = a[i-1]*10 + 45*ceil(pow(10,i-1));    
         }
         
         long long int p = ceil(pow(10,d));
         int msd = n/p;
         
         return msd*a[d] + ((msd*(msd-1))/2)*p + msd*(1+n%p) + func(n%p);
       
}
int main() {
    int a,b;
    cin >> a >> b;
    dp[0] = 0;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <=9; i++) 
    {
        dp[i] = dp[i-1] + i;
    }
    while(a!=-1 && b!=-1)
    {
        if(a==0){
            cout << func(b) << endl;
        }
        else if(a<=9 && b<=9)
        {
            cout << dp[b]-dp[a-1] << endl;
        } 
        else
        {
            long long int l = func(b) - func(a-1);
            printf("%lld\n",l);
            
        }
        
        
         cin >> a >> b;   
    }
	return 0;
}
