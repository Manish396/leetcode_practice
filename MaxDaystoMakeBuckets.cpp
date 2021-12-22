class Solution {
public:
    bool bucketPossible(vector<int>arr, int m, int k, int days){
        int size = 0, count = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] <= days){
                size++;
            }
            else{
                size = 0;
            }
            if(size == k) size = 0, count++;
            if(count == m) return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int days = -1;
        int buck = 0;
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());
        int s = 0, e = maxi;
        while(s <= e){
            int mid = (s + e)/2;
            if(bucketPossible(bloomDay, m, k, mid)){
                days = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }
        return days;
    }
};
