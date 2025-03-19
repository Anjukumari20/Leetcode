class Solution {
    public:
        int minOperations(vector<int>& nums) {
         int o=0,n=nums.size();
         for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                o++;
    
                nums[i]=not nums[i];
                nums[i+1]=not nums[i+1];
                nums[i+2]=not nums[i+2];
            }
         }
         if(not nums[n-1] or not nums[n-2]) return -1;
    
         return o;
        }
    };