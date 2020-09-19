class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> result;
        
        int left, right,n = intervals.size();
        
        if(intervals.empty())
            return intervals;
        
        left = intervals[0][0];
        right = intervals[0][1];
        
        for(int i=0 ; i<n; i++)
        {
            vector<int> tmp;

            if(intervals[i][0] > right)
            {
                tmp.push_back(left);
                tmp.push_back(right);
            
                result.push_back(tmp);
                
                left = INT_MAX;
                right = INT_MIN;
            }
            
            left = min(left , intervals[i][0]);
            right = max(right, intervals[i][1]);
            
            
        }
        vector<int> tmp;

        tmp.push_back(left);
        tmp.push_back(right);
            
        result.push_back(tmp);
        
        return result;
    }
};






