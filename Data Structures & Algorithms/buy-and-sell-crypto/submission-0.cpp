class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0; 
        int currProfit = 0;
        int currBuy = 101;
        int index = -1;
        
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < currBuy)
            {
                currBuy = prices[i];
                index = i; 
                currProfit -= prices[i];
                continue;
            }
            if (currProfit < prices[i] - currBuy)
            {
                currProfit = prices[i] - currBuy;
            }
            if (currProfit > maxProfit)
                maxProfit = currProfit;
        }
        return maxProfit;
    }
};
