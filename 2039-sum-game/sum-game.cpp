class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int sum1 = 0, sum2 = 0;
        int q1 = 0, q2 = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    q1++;
                else
                    q2++;
            } 
            else {
                if (i < n / 2)
                    sum1 += num[i] - '0';
                else
                    sum2 += num[i] - '0';
            }
        }

        // Alice has an extra move
        if ((q1 + q2) % 2 == 1)
            return true;

        int diff = sum1 - sum2;

        // Bob can force equality
        if (diff == 9 * (q2 - q1) / 2)
            return false;

        return true;
    }
};