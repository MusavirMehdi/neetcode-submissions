class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //-4 -1 -1  0  1  2
        // nums[i] = -(nums[j] + nums[k])
        int n = nums.size();
        vector<vector<int>> ans;

        for(int i=0;i<n-1;i++){
           if(i>0 && nums[i] == nums[i-1]) {
            continue;
           }

           int target = -nums[i];
           int start = i+1;
           int end = n-1;
           
           while(start<end){
            int sum = nums[start]+nums[end];
            if(sum == target){
                ans.push_back({nums[start],nums[i],nums[end]});
                start++;
                end--;

                while(nums[start] == nums[start-1] && start<end){
                    start++;
                }
                while(nums[end] == nums[end+1] && start<end){
                    end--;
                }
            }
            else if(sum < target){
                start++;
            }
            else{
                end--;
            }
           }
        }
        
        return ans;
    }
};
