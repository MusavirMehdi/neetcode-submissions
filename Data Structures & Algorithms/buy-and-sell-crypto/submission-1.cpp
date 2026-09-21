class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = prices[0];
        int maxprofit = 0;

        for(int i=1;i<n;i++){
            if(prices[i]<buy){
                buy = prices[i];
            }
            else if(prices[i]>=buy){
                maxprofit = max(maxprofit,prices[i]-buy);
            }
        }
        return maxprofit;
    }
};
