class Solution {
public:
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> result;
        vector<string> parts;
        dfs(s, 0, result, parts);
        return result;
        
    }
private:
    void dfs(string s, int start, vector<vector<string>>& result, vector<string>& parts)
    {
        int len = s.size();
        
        if(start >= len)
        {
            result.push_back(parts);
        }
        
        for(int i=start; i<len; i++)
        {
            if(isPalindrome(s, start, i))
            {
                parts.push_back(s.substr(start, i-start+1));
                dfs(s,i+1,result, parts);
                parts.pop_back();
            }
        }
               
    }
    
    bool isPalindrome(string s, int start, int end)
    {
        while(start<=end)
        {
            if( s[start++] != s[end--] )
            {
                return false;
            }
        }
            
        return true;
    }
};





