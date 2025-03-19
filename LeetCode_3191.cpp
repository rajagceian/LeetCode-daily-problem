class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int steps =0;
        for(int i=0;i<=(n-3);i++){
            if(nums[i]==0){
                int j=i;
                while(j<(i+3)){
                    nums[j] = nums[j]==0;
                    j++;
                }
                steps++;
            }
        }
        
        for(int ele : nums){
            if(ele == 0) return -1;
        }

        return steps;
    }
};
