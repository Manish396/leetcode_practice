class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>res;
        int n = points.size();
        vector<pair<double, pair<int, int>>>mp;
        for(int i = 0; i < n; i++){
            double dist = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            mp.push_back({dist, make_pair(points[i][0], points[i][1])});
        }
        sort(mp.begin(), mp.end());
        for(auto it: mp){
            if(k == 0) break;
            vector<int>temp = {it.second.first, it.second.second};
            res.push_back(temp);
            k--;
        }
        return res;
    }
};
