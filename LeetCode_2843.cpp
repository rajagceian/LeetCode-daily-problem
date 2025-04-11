class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        while (low <= high) {
            string s = to_string(low);
            int n = s.length();
            if (n % 2 == 0) {
                int first = 0;
                for (int i = 0; i < n / 2; i++)
                    first += s[i] - '0';
                int second = 0;
                for (int i = n / 2; i < n; i++)
                    second += s[i] - '0';
                if (first == second)
                    cnt++;
            }
            low++;
        }
        return cnt;
    }
};
