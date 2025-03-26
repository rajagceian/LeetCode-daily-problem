class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector <int> arr;
        int n=grid.size();
        int m=grid[0].size();
        for(auto &row : grid){
            for(auto &col : row){
                arr.push_back(col);
            }
        }
        sort(arr.begin(),arr.end());
        int len = arr.size();
        int median = arr[len/2];
        int cnt = 0;
        for(int ele : arr){
            int diff = abs(ele - median);
            if(diff % x != 0) return -1;
            cnt += (diff)/x;
        }
        return cnt;
    }
};
