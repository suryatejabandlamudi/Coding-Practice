class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int mp[26] = {0};
        
        
        for(auto ch:s1)
        {
            mp[ch - 'a']++;
        }
        
        int start = 0, end =0;
        int count = s1.length();
        
        while(end < s2.length())
        {
            if(mp[s2[end++]-'a']-- > 0)
                count--;
            
            if(count == 0 && end-start==s1.length())
                return true;
            
            if(end-start == s1.length())
            {
                if(mp[s2[start++]-'a']++ >= 0)
                    count++;
            }
        }
        return false;
    }
};