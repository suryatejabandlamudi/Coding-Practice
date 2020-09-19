class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty())
            return false;
        unordered_set<string> dict;
        
        for(string str: wordDict)
            dict.insert(str);
        
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        string tmp;
        
        for(int i=1; i<=s.length(); i++)
        {
            for(int j=i-1; j>=0; j--)
            {
                if(dp[j])
                {
                    tmp = s.substr(j, i-j);
                    if(dict.find(tmp) != dict.end())
                    {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        
        return dp[s.length()];
        
    }
};