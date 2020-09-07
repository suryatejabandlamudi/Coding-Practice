class Solution {
public:
    string longestWord(vector<string>& words) {
        
        sort(words.begin(), words.end());
        
        unordered_set<string> mp;
        string res;
        
        for(auto word:words)
        {
            if(word.size() ==1 || mp.count(word.substr(0,word.size()-1)))
            {
                res = word.size() > res.size() ? word :res ; 
                mp.insert(word);
            }
            
        }
        
        return res;
    }
};