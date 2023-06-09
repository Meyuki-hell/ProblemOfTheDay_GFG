//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	    
	    void solve(string &S, vector<string> &ans, int i, unordered_map<string, int>& mp){
	        if(i >= S.size()){
	            if(mp.find(S) == mp.end()){
	                ans.push_back(S);
	                mp[S]++;
	            }
	            return;
	        }
	        for(int j = i; j < S.size(); j++){
	            swap(S[i], S[j]);
	            solve(S, ans, i + 1, mp);
	            
	            swap(S[i], S[j]);
	        }
	    }
	    
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> ans;
		    unordered_map<string, int>mp;
		    solve(S, ans, 0, mp);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends
