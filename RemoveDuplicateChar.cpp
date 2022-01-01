class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        unordered_map<char ,bool> visited;  
        string res;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]]--;
            
            if(visited[s[i]]) continue; 
            
            while(res.empty() == false && res.back() > s[i] && freq[res.back()] > 0 )
            {
                visited[res.back()] =false; // not visited
                res.pop_back();
            }
            
            visited[s[i]] =true;
            res+=s[i];
            
                      
        }
        
        return res;
    }
};
