class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for(int i = 0; i < n - 1; i++)
        {
            int left = 0;
            int right = 1;
            int minL, minR, mini = INT_MAX;
            while(right < n)
            {
                if(arr[left] == -1){
                    left = right;
                    right++;
                }
                else if(arr[right] == -1){
                    right++;
                }
                else{
                    if(mini > arr[left]*arr[right])
                    {
                        minL = left;
                        minR = right;
                        mini = arr[left]*arr[right];
                    }
                    left = right;
                    right++;
                }
            }
            ans += mini;
            if(arr[minL] > arr[minR]) 
                arr[minR] = -1;
            else 
                arr[minL] = -1;
        }
        return ans;
    }
};
