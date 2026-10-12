class Solution {
public:
    int lastRemaining(int n) {
        if (n == 1) {
            return 1;
        }
        int winnerOfHalf = lastRemaining(n / 2);
        int rightToLeftWinner = (n / 2) + 1 - winnerOfHalf;
        return 2 * rightToLeftWinner;
    }
};