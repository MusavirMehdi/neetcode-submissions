class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         int n = nums.size();
        // optimal o of n way;
        // but space complexity o of n.
        unordered_map <int,int> seen;

        for(int i=0;i<n;i++){
            if(seen.count(nums[i])){ //.count() return 1 if key exists and 0 if it doesnt.
                return true;
            }
            seen[nums[i]]; //insert that value
        }

        return false;
       
    }
};