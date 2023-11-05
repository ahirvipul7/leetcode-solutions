class Solution {
public:
    
    // int f(vector<int> & prices,int idx,int n,bool able,int count,vector<vector<vector<int>>>& dp){
        
    //     if(idx==n || count==0){
    //         return 0;
    //     }
        
    //     if(dp[idx][able][count-1]!=-1){
    //         return dp[idx][able][count-1];
    //     }
        
    //     if(able){
    //         return dp[idx][able][count-1]=max(f(prices,idx+1,n,false,count,dp) - prices[idx],f(prices,idx+1,n,true,count,dp));
    //     }
    //     return dp[idx][able][count-1]=max(f(prices,idx+1,n,true,count-1,dp)+prices[idx],f(prices,idx+1,n,false,count,dp));
    // }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3)));
        for(int i=n;i>=0;i--){
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    if(i==n||k==0){
                        dp[i][j][k]=0;
                    }
                    else{

                        if(j){
                            dp[i][j][k]=max(dp[i+1][0][k]-prices[i],dp[i+1][1][k]);
                        }
                        else{
                            dp[i][j][k]=max(dp[i+1][1][k-1]+prices[i],dp[i+1][0][k]);
                        }
                    }
                }
            }
        }

        return dp[0][1][2];
    }
};