class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        int n = instructions.size();
        vector<bool> isJump(n, false);
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (instructions[i] == "jump") {
                isJump[i] = true;
            }
        }

        long long score = 0;
        int i = 0;

        while (i >= 0 && i < n) {
            if (visited[i]) break; 
            visited[i] = true;

            if (isJump[i]) {
                i += values[i];
            } else {
                score += values[i];
                i++;
            }
        }

        return score;
    }
};

