class Solution {
public:
  string GiveWord(string &s ,int &idx){
    string answer;
    for(; idx < s.size(); idx++)
      if((s[idx] <= 'z' && s[idx] >= 'a') || (s[idx] <= 'Z' && s[idx] >= 'A')) 
          break;
    
    for(;idx < s.size();idx++)
      if((s[idx] <= 'z' && s[idx] >= 'a') || (s[idx] <= 'Z' && s[idx] >= 'A')){
        char t = s[idx];
        if(s[idx] <= 'Z') t += 32;
        answer.push_back(t);
      }
      else break;
    
    return answer;
  }
  
  string mostCommonWord(string paragraph, vector<string>& banned){
    unordered_set<string> ban(banned.begin(), banned.end());
    unordered_map<string, int> mp;
    string answer;
    int t = 0;
    for(int i = 0; i < paragraph.size(); i++){
      string tmp = GiveWord(paragraph , i);
      if(!ban.count(tmp)){
        if(mp.count(tmp)) {
          mp[tmp]++;
          if(mp[tmp] > t){
              t = mp[tmp]; 
              answer = tmp;
          }
        }
        else mp[tmp] = 1;
      }
    }
    if(t) 
        return answer;
    return mp.begin()->first;
  }
};
