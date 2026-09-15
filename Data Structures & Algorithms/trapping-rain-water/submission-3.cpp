class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // min(largest left ,largest right) - h[i]
        // approach 1 (oofn tc but oofn sc)
        vector<int> maximumL (n);
        vector<int> maximumR (n);

        // 0 1 0 2 1 0 1 3 2 1 2 1

        maximumL[0] = height[0];
        for(int i=1;i<n;i++){
            maximumL[i] = max(maximumL[i-1],height[i]);
        }
        
        maximumR[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            maximumR[i] = max(maximumR[i+1],height[i]);
        }

        int water = 0;
        int watertotal = 0;
        for(int i=0;i<n;i++){
            water = min(maximumR[i],maximumL[i]) - height[i];
            watertotal = watertotal + max(0,water);
        }

        return watertotal;
    }
};
