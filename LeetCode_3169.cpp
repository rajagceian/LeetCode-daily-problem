class Solution {
public:
int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int n = meetings.size();
        int cnt = 0;
        int end = meetings[0][1];
        if(meetings[0][0] != 1){
            cnt = meetings[0][0] - 1;
        }
        for(int i=1;i<n;i++){
            if(meetings[i][0] > end){
                cnt += meetings[i][0] - end - 1;
            } 
            end =max(end,meetings[i][1]);
        }
        if(end<days) cnt += days - end;
        return cnt;
    }
};
