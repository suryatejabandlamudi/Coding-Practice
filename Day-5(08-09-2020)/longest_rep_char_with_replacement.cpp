class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int start = 0, end = 0, str_len = s.length(), sub_len = 0;
        int max_rep_len = 0, res =0;    
        
        int count[26] = {0};
        while(end < str_len)
        {
            max_rep_len = max(max_rep_len, ++count[s[end] - 'A']);
            sub_len = end-start+1;
            if(sub_len  > k + max_rep_len)
            {
                count[s[start] - 'A']-- ;
                start++;
            }
            res = max(res,end-start+1);
            end++;
        }
        return res;
    }
};