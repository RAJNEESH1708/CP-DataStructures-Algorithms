class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n==0) return 0;
        vector<vector<int>> dp(k+1,vector<int>(n,0));  
        for(int i=1;i<=k;i++){
            //int maxx = dp[i-1][0]+prices[j]-prices[0]; 
            for(int j=1;j<n;j++){  
                    dp[i][j] = dp[i][j-1]; // previous day ans
                    for(int z=0;z<j;z++){  
            // i-1 transactions done now for ith take max of all the 
                possibilities 
                        dp[i][j] = max(dp[i][j],dp[i-1][z]+prices[j]
                            -prices[z]);
                    }             
            }
        }
        
        return dp[k][n-1];
    }
};
