class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> res(n);  // Initialize res with size n
        priority_queue<pair<int, int>> maxh;

        for (int i = 0; i < n; i++) {
            maxh.push({score[i], i});
        }

        if (!maxh.empty()) {
            res[maxh.top().second] = "Gold Medal";
            maxh.pop();
        }
        if (!maxh.empty()) {
            res[maxh.top().second] = "Silver Medal";
            maxh.pop();
        }
        if (!maxh.empty()) {
            res[maxh.top().second] = "Bronze Medal";
            maxh.pop();
        }

        int rank = 4;
        while (!maxh.empty()) {
            res[maxh.top().second] = to_string(rank);
            rank++;
            maxh.pop();
        }

        return res;
    }
};

