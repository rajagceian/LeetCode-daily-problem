class Solution {
public:
    void reBalance(multiset <int>& left,multiset <int>& right) {
        while (right.size() > left.size() + 1) {
            int maxRight = *right.rbegin();
            right.erase(right.find(maxRight));
            left.insert(maxRight);
        }
        while (right.size() < left.size()) {
            int minLeft = *left.begin();
            left.erase(left.find(minLeft));
            right.insert(minLeft);
        }
    }

    double findMedian(multiset <int>& left,multiset <int>& right) {
        if (right.size() == left.size()){
            double m1 = *left.begin(); 
            double m2 = *right.rbegin(); 
            return (m1 + m2) / 2.0;
        }
        return *right.rbegin();
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> ans;
        multiset <int> left,right;
        // left -> all larger element and right -> smaller element

        for (int i = 0; i < k; ++i) {
            if (right.empty() || nums[i] <= *right.rbegin()) {
                right.insert(nums[i]);
            } else {
                left.insert(nums[i]);
            }
            reBalance(left, right);
        }
        ans.push_back(findMedian(left,right));
        for(int i=k;i<n;i++){
            if (nums[i] <= *right.rbegin()) {
                right.insert(nums[i]);
            } else {
                left.insert(nums[i]);
            }
            int toRemove = i-k;
            if(left.find(nums[toRemove])!=left.end()){
                left.erase(left.find(nums[toRemove]));
            }  else if(right.find(nums[toRemove])!=right.end()){
                right.erase(right.find(nums[toRemove]));
            }
            reBalance(left,right);
            ans.push_back(findMedian(left,right));         
        }
        
        return ans;
    }
};
