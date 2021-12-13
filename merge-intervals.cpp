class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>>res;
        vector<int>vec;
        sort(intervals.begin(), intervals.end());
        for(auto it: intervals){
            for(auto ii: it){
                vec.push_back(ii);
            }
        }
        int s = vec[0];
        int end = vec[1];
        for(int i = 2; i < vec.size(); i+=2){
            if(vec[i] <= end){
                end = max(vec[i+1], end);
                s = min(s, vec[i]);
            }
            else{
                vector<int>temp = {s, end};
                res.push_back(temp);
                s = vec[i];
                end = max(vec[i+1], end);
            }
        }
        vector<int>temp = {s, end};
        res.push_back(temp);
        return res;
    }
};
