class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int max_ele = *max_element(nums.begin(),nums.end());
        vector <int> freq(max_ele+1 , 0);
        for(int ele : nums){
            freq[ele]++;
        }

        for(int f : freq){
            if(f%2) return false;
        }
        return true;
    }
};
