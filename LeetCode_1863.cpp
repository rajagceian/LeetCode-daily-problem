//--------------------------- Approach - 1 (T.C = O(2^n) and S.C = O(n) ) -----------------------
class Solution {
public:
    int sum=0;
    void generateSubsets(vector<int>& nums, int index, vector<int>& currentSubset) {
    if (index == nums.size() && currentSubset.size() ) {
        int xor_opt = 0;
        for(int ele : currentSubset){
            xor_opt ^= ele;
        }
        sum += xor_opt;
        return;
    }
    if(index >= nums.size()) return;
    // Include the current element in the subset
    currentSubset.push_back(nums[index]);
    generateSubsets(nums, index + 1, currentSubset);
    
    // Exclude the current element from the subset
    currentSubset.pop_back();
    generateSubsets(nums, index + 1, currentSubset);
}
    int subsetXORSum(vector<int>& nums) {
        vector <int> v;
        generateSubsets(nums,0,v);
        return sum;
    }
};

//------------------- Approach-2 (T.C = O(n) and S.C = O(1) ) ----------------------
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        // Step 1: Compute bitwise OR of all elements
        int or_all = 0;
        for (int num : nums) {
            or_all |= num;
        }

        // Step 2: Compute number of subsets that include each bit
        // 2^(n-1) subsets will include each bit
        int multiplier = 1 << (nums.size() - 1);

        // Step 3: Final result
        return or_all * multiplier;
    }
};
