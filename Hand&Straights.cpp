class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size() % k){
            return false;
        }
        sort(hand.begin(),hand.end());
        unordered_map<int,int>mp;
        for(int i : hand){
            mp[i]++;
        }
        for(int i : hand){
            if(mp[i]>0){
                for(int j=0;j<k;j++){
                    if(mp[i+j]==0){
                        return false;
                    }
                    mp[i+j]--;
                }
            }
        }
        return true;
    }
};
