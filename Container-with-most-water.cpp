class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        int s = 0, e = n-1;
        while(s < e){
            int temp = min(height[s], height[e]) * (e - s);
            ans = max(ans, temp);
            if(height[s] < height[e]){
                s++;
            }
            else{
                e--;
            }
        }
        return ans;
    }
};
