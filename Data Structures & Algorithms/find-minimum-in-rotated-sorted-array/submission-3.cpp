class Solution {
public:
    int findMin(vector<int> &nums) {
        // 2 3 4 5 6 1
        // 2 3 0 1
        // 4 5 6 7 1 2 3

        int start = 0;
        int n = nums.size();
        int end = n-1;
        int ans = nums[n-1];
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(nums[mid]<nums[end]){
                ans = min(nums[mid],ans);
                end = mid-1;
                
            }
            else {
                ans = min(nums[mid],ans);
                start = mid+1;
                
            }
        }
        return ans;
    }
};
