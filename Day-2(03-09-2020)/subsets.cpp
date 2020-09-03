class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sub;
        
        subset_recur(nums,0, sub,result);
        
        
        return result;
        
        
    }
    
    void subset_recur(vector<int>& nums,int i , vector<int>& sub ,vector<vector<int>>& result)
    {
        result.push_back(sub);
        
        for(int j=i; j< nums.size(); j++)
        {
            sub.push_back(nums[j]);
            subset_recur(nums, j+1, sub, result);
            sub.pop_back();
        }
        
        
        
        
    }
};