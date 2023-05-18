//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

bool dfs(vector<vector<int>> &matrix, int N, int M, int i, int j, vector<vector<bool>> &v){
    if(i < 0 || i >= N || j < 0 || j >= M){
        return false;
    }
    if(v[i][j] || matrix[i][j] == 0){
        return true;
    }
    v[i][j] = true;
    bool l = dfs(matrix, N, M, i, j - 1, v);
    bool r = dfs(matrix, N, M, i, j + 1, v);
    bool u = dfs(matrix, N, M, i - 1, j, v);
    bool d = dfs(matrix, N, M, i + 1, j, v);
    return l && r && u && d;
}

class Solution {
    public:
    int closedIslands(vector<vector<int>>& matrix, int N, int M) {
        // Code here
        vector<vector<bool>>v(N, vector<bool>(M, false));
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(matrix[i][j] == 1 && v[i][j] == false){
                    if(dfs(matrix, N, M, i, j, v)){
                        ans++;
                    }
                }
            }
        }
        return ans;
        
    }
    
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends
