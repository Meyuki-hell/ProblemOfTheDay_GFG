//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX], int n, int m, int k) {
        int l = 0, r = m - 1;
        int u = 0, d = n - 1;
        int cnt = 0;
        
        while (l <= r && u <= d) {
            if (cnt + r - l + 1 >= k)
                return a[u][l + k - cnt - 1];
            
            cnt += r - l + 1;
            u++;
            
            if (cnt + d - u + 1 >= k)
                return a[u + k - cnt - 1][r];
            
            cnt += d - u + 1;
            r--;
            
            if (cnt + r - l + 1 >= k)
                return a[d][r - k + cnt + 1];
            
            cnt += r - l + 1;
            d--;
            
            if (cnt + d - u + 1 >= k)
                return a[d - k + cnt + 1][l];
            
            cnt += d - u + 1;
            l++;
        }
}

};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
