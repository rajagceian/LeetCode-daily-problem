class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqMap;

        // Count frequency of each element
        for (int ele : nums) {
            freqMap[ele]++;
        }

        // Find the element with maximum frequency
        int maxFreq = 0, maxFreqEle = -1;
        for (auto& pair : freqMap) {
            if (pair.second > maxFreq) {
                maxFreq = pair.second;
                maxFreqEle = pair.first;
            }
        }

        int firstHalf = 0; // Count occurrences of maxFreqEle in the first half

        // Iterate and check split condition
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxFreqEle) {
                firstHalf++;
            }

            // Check if maxFreqEle is dominant in both halves
            if ((2 * firstHalf > (i + 1)) && (2 * (maxFreq - firstHalf) > (n - i - 1))) {
                return i;
            }
        }

        return -1;
    }
};
