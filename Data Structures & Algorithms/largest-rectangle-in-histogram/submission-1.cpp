class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int,int>> s;
        int maxarea = 0;

        for(int i =0;i<n;i++){
            int start = i;
            while(!s.empty() && s.top().second > heights[i]){
                pair <int,int> top = s.top();
                int height = top.second;
                int index = top.first;
                maxarea = max(maxarea, height * (i - index));
                start = index;
                s.pop();
            }
            s.push({start,heights[i]});
        
        } 

        while(!s.empty()){
            maxarea = max(maxarea, s.top().second * (n - s.top().first));
            s.pop();
        }
        return maxarea;
    }
};