class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

    
      unordered_set<int> s;
      for(int i =0;i<nums.size();i++){
        s.insert(nums[i]);
      }   
      
      int count = 1;
      int longest = 0;
      for(int i=0;i<nums.size();i++){
          int x = nums[i];
          if(s.count(x-1)){
            continue;
          }

          thisblock: 
          if(s.count(x+1)==1){
            count++;
            ++x;
            goto thisblock;
          }

          longest = max(longest,count);
          count = 1;
      }

      return longest;
    }
};
/*
2 20 4 10 3 4 5

2 if 1 exists then skip 
if not then check if 3 exists
if 3 exists count++ and check if 4 exists 
if 4 exists count++ and check if 4 exists 



*/