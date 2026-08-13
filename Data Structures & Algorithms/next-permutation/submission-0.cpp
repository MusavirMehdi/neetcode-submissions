class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the pivot element
        int n = nums.size();
        int pivot = -1;
        int p = -1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                p = i-1;
                pivot = nums[i-1];
                break;
            }
        }
        // only reverse array if pivot is still -1
        if(p==-1){
            reverse(nums.begin(),nums.end());
            return ;
        }
        //swap pivot element with a larger than pivot element from the right to left of the array
        for(int i=n-1;i>p;i--){
            if(nums[i]>pivot){
                swap(nums[i],nums[p]);
                break;
            }
        }

        reverse(nums.begin() + p + 1,nums.end());
        ;
    }
};