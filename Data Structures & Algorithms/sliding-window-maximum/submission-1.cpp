class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque <int> d;

        for(int i=0;i<n;i++){
            // check if prev elements are in window 
            if(!d.empty() && d.front()<=i-k){
                d.pop_front();
            }
            while(!d.empty() && nums[d.back()] <= nums[i]){
                d.pop_back();
            }
            d.push_back(i);

            if(i>=k-1){
                ans.push_back(nums[d.front()]);
            }
        }

        return ans;
    }
};

/*
Deque (Push and pop ON both sides).
FIFO 
in a descending order so we can get the max of each window

store values in deque by their index
check if the prev value < curr value :  eg 1 2 1
      then pop prev value : eg in deuqe 1X 2 1

to get the top of the window
      d.front
      d.pop

to check past values from prev window dont remain
*/

// problem of prev value remaining in the queue 

// 4 2 4 1 0
// 4 2   q 4 2
// 2 4   q 2 4
// 4 1   q 2 4 1
// 1 0   q 2 1 0
