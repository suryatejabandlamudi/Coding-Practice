class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> mp;
        
        reverse(arr.begin() , arr.end());
        
        int max_len = 1;
        
        for(int n: arr)
        {
            if(mp[n+difference] != 0)
            {
                mp[n] = mp[n+difference] + 1;
                if(max_len < mp[n])
                    max_len = mp[n];
                
            }
            else
                mp[n] = 1;
        }
        
        
        return max_len;
        
    }
};