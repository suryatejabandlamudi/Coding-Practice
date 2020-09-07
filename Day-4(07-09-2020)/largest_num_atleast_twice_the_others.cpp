class Solution {
public:
    int dominantIndex(vector<int>& nums) {
      
        int second_max = -1;
        int first_max = -1;
        int max_index = -1;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] > first_max)
            {
                second_max = first_max;
                first_max = nums[i];
                max_index = i;

            }
            else if(nums[i] > second_max)
            {
                second_max = nums[i];
            }
        }
                
        return second_max * 2 <= first_max ? max_index : -1;
    }
};