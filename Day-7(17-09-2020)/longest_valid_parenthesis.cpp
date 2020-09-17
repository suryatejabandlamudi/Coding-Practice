class Solution {
public:
    int longestValidParentheses(string s) {
        
        int i = 0, max_len =0, top_index;
        stack<int> stk;
        while(i < s.length())
        {
            if(s[i] == '(')
            {
                stk.push(i);
            }
            else if(s[i] == ')')
            {
                if(!stk.empty() && s[stk.top()] == '(')
                {
                    stk.pop();
                    top_index = stk.empty() ? -1 : stk.top();
                    if(max_len < i- top_index)
                    {
                        max_len = i - top_index;
                    }
                }
                else
                {
                    stk.push(i);
                }
                
            }
            i++;
        }
        return max_len;
    }
};