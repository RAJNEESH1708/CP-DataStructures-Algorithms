class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if (k <= 1) return 0;
        int prod = 1, ans = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            prod *= nums[right];
            while (prod >= k) prod /= nums[left++];
            ans += right - left + 1;
        }
        return ans;
        
       /** 
        int  n = nums.size();
        int i=0,j=0,z=0;
        int ans = 0;
        int prod = 1;
        while(j<n){
            prod *= nums[j];
            if(prod>=k)
            {
                while(i<=j and prod>=k)
                {  
                    ans += (n-j);
                    prod /= nums[i];
                    i++;
                    
                }
            }
            j++;
                   
        }
        z = (n*(n+1))/2;
        return (z-ans)>0?(z-ans):0;
        */
    }
};