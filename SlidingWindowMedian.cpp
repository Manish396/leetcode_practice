class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<long long>m1, m2;
        vector<double>res;
        for(int i = 0; i < k; i++){
            m1.insert(nums[i]);
            m2.insert(*(m1.rbegin()));
            auto it = m1.rbegin();
            m1.erase(m1.find(*(m1.rbegin())));
            if(m2.size() > m1.size()){
                m1.insert(*(m2.begin()));
                m2.erase(m2.find(*(m2.begin())));
            }
        }
        
        if(m1.size() > m2.size()){
            res.push_back(*(m1.rbegin()));
        }
        else{
            res.push_back((*(m1.rbegin()) + *(m2.begin()))/2.0);
        }
        int s = 0;
        for(int i = k; i < n; i++){
            if(m2.find(nums[s])!=m2.end()){
                m2.erase(m2.find(nums[s]));
                s++;
            }
            else{
                m1.erase(m1.find(nums[s]));
                s++;
            }
            m1.insert(nums[i]);
            m2.insert(*(m1.rbegin()));
            auto it = m1.rbegin();
            m1.erase(m1.find(*(m1.rbegin())));
            if(m2.size() > m1.size()){
                m1.insert(*(m2.begin()));
                m2.erase(m2.find(*(m2.begin())));
            }
            if(m1.size() > m2.size()){
                res.push_back(*(m1.rbegin()));
            }
            else{
                res.push_back((*(m1.rbegin()) + *(m2.begin()))/2.0);
            }
        }
        return res;
    }
};
