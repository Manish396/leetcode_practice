class Solution {
public:
    void swap(int *a, int *b){
        int temp = *b;
        *b = *a;
        *a = temp;
    }
    void countPerm(vector<int>&perm, int idx, int size, int &res){
        if(idx == size){
            res++;
            return;
        }
        for(int i = idx; i < size; i++){
            if((idx+1)%perm[i] == 0 or perm[i]%(idx+1) == 0){
                swap(&perm[idx], &perm[i]);
                countPerm(perm, idx + 1, size, res);
                swap(&perm[idx], &perm[i]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int>perm(n);
        for(int i = 0; i < n; i++){
            perm[i] = i+1;
        }
        int res = 0;
        countPerm(perm, 0, n, res);
        return res;
    }
};
