class Solution {
public:
    int maxProfit(vector<int>& price) {
        int min = price[0];
        int profit = 0;

        for(int i =0; i< price.size();i++){
            if(price[i] < min){
                min = price[i];
            }
            profit = fmax(profit, price[i]-min);
        }
        return profit;
        
    }
};