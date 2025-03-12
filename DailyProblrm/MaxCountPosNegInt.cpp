class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int n=0,p=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]<0){
                    n++;
                }
                if(nums[i]>0){
                    p++;
    
                }
                
    
    
            }
            if(n>p)
            {
                return n;
            }
            return p;
            
        }
    };