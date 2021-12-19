class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curr = 0, prev = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                prev += curr;
                curr = 0;
                start = -1;
            }
            else if(curr > 0 and start == -1){
                start = i;
            }
        }
        if(curr + prev >= 0){
            return start;
        }
        return -1;
    }
};
