class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        multiset<int>ms;
        int start = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            ms.insert(nums[i]);
            if(ms.size() == k){
                res.push_back(*ms.rbegin());
                multiset<int>::iterator it;
                it = ms.find(nums[start]);
                ms.erase(it);
                start++;
            }
        }
        return res;
    }
};
