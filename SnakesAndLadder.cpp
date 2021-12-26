class Solution {
public:
    pair<int, int> getCoordinates(int val, int n) {
        int quotient = (val-1)/n;
        int remainder = (val-1)%n;
        int r = n - 1 - quotient;
        int c = quotient % 2 == 0 ? remainder : n- 1 - remainder;
        return {r, c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> vis(n*n+1,0);
        queue<int> que;
        que.push(1);
        vis[1] = 1;
        int ans = -1;
        while(!que.empty()){
            ans++;
            int n1 = que.size();
            while(n1--){
                int s=que.front();
                que.pop();
                if(s==(n*n)) 
                    return ans;
                for(int i=1;i<=6;i++){
                    if((s+i) <= (n*n)){
                        pair<int, int> ns = getCoordinates(s+i, n);
                        int x = ns.first;
                        int y = ns.second;
                        int fis = board[x][y] == -1 ? (s+i) : (board[x][y]);
                        if(!vis[fis]){
                            vis[fis]=1;
                            que.push(fis);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
