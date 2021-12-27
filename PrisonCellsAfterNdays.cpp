class Solution {
public:
    vector<int>simulate(vector<int> &cells)
    {
        vector<int> tcells = cells;
        for(int i = 0; i < tcells.size(); i++){
            if(i==0 || i==tcells.size()-1) cells[i] = 0;
            else if(tcells[i-1]==tcells[i+1]) cells[i] = 1;
            else cells[i] = 0;
        }
        return cells;
    }
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        vector<vector<int>>res;
        simulate(cells);
        res.push_back(cells);
        int day = 1;
        while(day <= 14){
            simulate(cells);
            res.push_back(cells);
            day++;
        }
        return res[(n-1)%14];
    }
};
