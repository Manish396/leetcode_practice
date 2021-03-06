class Solution {
public:
    static bool cmp(vector<int>&p1, vector<int>&p2){
        return ((p1[0]*p1[0] + p1[1] *p1[1]) < (p2[0] * p2[0] + p2[1]*p2[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        int n = points.size();
        sort(points.begin(), points.end(), cmp);
        for(auto it: points){
            if(k == 0) break;
            res.push_back(it);
            k--;
        }
        return res;
    }
};
