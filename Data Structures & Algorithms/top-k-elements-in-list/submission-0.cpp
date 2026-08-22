class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int,int> m;
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        // 1 : 1;
        // 2 : 2;
        // 3 : 3;
        
        priority_queue<pair<int,int>> q;
        for(auto c:m){
            q.push({c.second,c.first});
        }

        for(int i=0;i<k;i++){
            ans.push_back(q.top().second);
            q.pop();
        }

        return ans;
    }
};
