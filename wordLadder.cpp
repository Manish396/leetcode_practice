class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        int i, j, k;
        queue<pair<string, int>>qp;
        qp.push({beginWord, 0});
        visited.insert(beginWord);
        while(!qp.empty()){
            pair<string, int> p = qp.front();
            qp.pop();
            string curr = p.first;
            int dist = p.second;
            if(curr == endWord){
                return dist + 1;
            }
            for(i = 0; i < curr.length(); i++){
                string next = curr;
                for(j = 1; j < 26; j++){
                    k = curr[i] - 'a';
                    k += j;
                    k %= 26;
                    next[i] = k + 'a';
                    if(visited.find(next) == visited.end() && wordSet.find(next) != wordSet.end()){
                        visited.insert(next);
                        qp.push({next, dist + 1});
                    }
                }
            }
        }
        return 0;
    }
};
