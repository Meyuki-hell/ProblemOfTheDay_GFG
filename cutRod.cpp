//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int m;
    int solve(int len[], int price[], int n, int index, vector<int> &dp){
        if(n == 0 || index == m){
            return 0;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        int temp = 0;
        if(n - len[index] >= 0){
            temp = price[len[index] - 1] + solve(len , price, n - len[index], index, dp);
        }
        int temp1 = solve(len, price, n, index + 1, dp);
        return dp[n] = max(temp, temp1);
    }
    
    int cutRod(int price[], int n) {
        //code here
        int len[n];
        vector<int> dp(n+1, -1);
        for(int i = 0; i < n; i++){
            len[i] = i + 1;
        }
        m = n;
        solve(len, price,n, 0, dp);
        return dp[n];
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
