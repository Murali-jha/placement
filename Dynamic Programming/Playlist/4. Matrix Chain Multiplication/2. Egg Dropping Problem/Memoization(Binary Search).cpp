class Solution {
public:
    
    
    int solve(int k,int n,vector<vector<int>> &t){
        if(n==0 || n==1){
            return n;
        }
        
        if(k==1){
            return n;
        }
        if(t[k][n]!=-1)
            return t[k][n];
        
        
        int ans=INT_MAX,l=1,h=n,temp=0;
     
        while(l<=h)
        {
            int mid=(l+h)/2;
            
            int left=solve(k-1,mid-1,t);   
            int right=solve(k,n-mid,t) ;  
            
            temp=1+max(left,right);      
            ans=min(ans,temp);           
            if(left<right){   
              l=mid+1;                     
            }
            else               
            {    
                h=mid-1;
            }
        }
        
        return t[k][n] = ans;
    }
    
    int superEggDrop(int k, int n) {
        vector<vector<int>> t(k+1,vector<int>(n+1,-1));
        return solve(k,n,t);
    }
};
