class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
        vector<pair<int, int>>vp;
        vector<vector<int>> res;
        for(auto it : buildings){
            vp.push_back({it[0], it[2]*-1});
            vp.push_back({it[1], it[2]});
        }
        sort(vp.begin(), vp.end());
        multiset<int, greater<int>> ms;
        ms.insert(0);
        int currHeight = 0;
        for(int i = 0; i < vp.size(); i++){
            if(vp[i].second < 0){
                ms.insert(vp[i].second * -1);
            }
            else{
                ms.erase(ms.find(vp[i].second));
            }
            if(currHeight != *ms.begin()){
                vector<int>temp = {vp[i].first, *ms.begin()};
                res.push_back(temp);
                currHeight = *ms.begin(); 
            }
        }
        return res;
    }
};
