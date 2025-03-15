class Solution {
public:
    bool isPossible(vector<int>& arr, int k, int mid) {
        int count = 0;
        int n=arr.size();
        for (int i=0;i<n;i++) {
            if (arr[i] <= mid) {
                count++;
                i++;
            }
        }
        return count>=k;
    }

    int minCapability(vector<int>& arr, int k) {
        int left = *min_element(arr.begin(), arr.end());
        int right = *max_element(arr.begin(), arr.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (isPossible(arr, k, mid)) {
                result = mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return result;
    }
};
