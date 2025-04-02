// ********************* Brute Force Approach ****** O(n^3) ************
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long value = 0;
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    long long v = (static_cast<long long>(nums[i]) - nums[j]) * nums[k];  // static_cast<long long> is used to handle overflow condition
                    value = max(value,v);
                }
            }
        }
        return value;
    }
};
// **********************Omptimized Approach ***** O(n) ***************
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long maxTriplet = 0, maxElement = 0, maxDiff = 0;
        for (long num : nums) {
            maxTriplet = max(maxTriplet, maxDiff * num);
            maxDiff = max(maxDiff, maxElement - num);
            maxElement = max(maxElement, num);
        }
        return maxTriplet;
    }
};
