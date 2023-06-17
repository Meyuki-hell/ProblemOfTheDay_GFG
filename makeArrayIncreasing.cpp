class Solution {
public:

    int solve(int i, int j, vector<int>& arr1, vector<int>& arr2, vector<unordered_map<int, int>>&dp){
        if(i == arr1.size()) return 0;

        if(dp[i].find(j) != dp[i].end()) return dp[i][j];

        int incl, excl;
        if(arr1[i] > j) {
            excl = solve(i+1, arr1[i], arr1, arr2, dp);
        }
        else{
            excl = INT_MAX;
        }

        int r = upper_bound(arr2.begin(),arr2.end(), j) - arr2.begin();

        if(r == arr2.size()){
            incl = INT_MAX;
        }
        else{
            incl = solve(i+1, arr2[r], arr1, arr2, dp);
        }
            if(incl == INT_MAX){
                dp[i][j] = excl;
            }
            else {
                dp[i][j] = min(excl, incl + 1);
            }
        
        return dp[i][j];

    }

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        
        vector<unordered_map<int, int>>dp(2001);
        int val = solve(0, INT_MIN, arr1, arr2, dp);

        if(val == INT_MAX){
            return -1;

        }
        else return val;
    }
};
