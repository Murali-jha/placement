class Solution {
public:
    
     int subset_sumTD(vector<int> &a, int n, int sum)
{

    int dp[n + 1][sum + 1];


    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
  
            if(j==0){
                dp[i][j]=1;
            }
            else if(i==0){
                dp[i][j]=0;
            }

            else if (a[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }

            else
            {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - a[i - 1]]);
            }
        }
    }
         return dp[n][sum];
     }
    
    
    int findTargetSumWays(vector<int>& nums, int S) {
         int tsum=0;
        int zero=0;
        
        vector<int> a;
        for(int i=0;i<nums.size();i++)
        {
            tsum+=nums[i];
            
            if(nums[i]==0) zero++;
            
            if(nums[i]!=0)
            {
                a.push_back(nums[i]);
            }
        }
        
                int n=a.size();

        if(S<0){
            S = -1*S;
        }
        
        //if(tsum<S) return 0;
         int sum;
        
        if((tsum+S)%2!=0)
         return 0;
        

         sum=(tsum+S)/2;
        
        int mul=1;
        mul=pow(2,zero);
        

         return mul*subset_sumTD(a,n,sum);
    }
};
