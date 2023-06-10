class Solution
{
    public:
        void Rearrange(int arr[], int n)
        {
            // Your code goes here
            vector<int> pos;
            int j=0;
            for(int i=0; i<n; i++){
                if(arr[i] >= 0){
                    pos.push_back(arr[i]);
                }
                else{
                    arr[j++] = arr[i];
                }
            }
            for(int x : pos){
                arr[j++] = x;
            }
        }
};
