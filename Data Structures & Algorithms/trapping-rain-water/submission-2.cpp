class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        // min(largest left ,largest right) - h[i]
        // approach 1 (oofn tc but oofn sc)
        vector<int> maximumL;

        // 0 1 0 2 1 0 1 3 2 1 2 1
        int maxL = 0;
        for(int i=0;i<n;i++){
            maximumL.push_back(maxL);
            if(maxL<height[i]){
                maxL = height[i];
            }
        }
        
        vector<int> maximumR (n,0);
        int maxR = 0;
        for(int i=n-1;i>=0;i--){
            maximumR[i] = maxR;
            if(maxR<height[i]){
                maxR = height[i];
            }
        }

        vector<int>ans (n,0);
        for(int i=0;i<n;i++){
            if(maximumL[i]<maximumR[i]){
                ans[i] = maximumL[i] - height[i]; 
            }
            else{
                ans[i] = maximumR[i] - height[i];
            }
        }

        int total = 0;
        for(int i=0;i<n;i++){
            if(ans[i]<0){
                continue;
            }
            else{
                total = total + ans[i];
            }
        }

        return total;
    }
};
