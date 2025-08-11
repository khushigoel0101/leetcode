class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        int fd = days;
        int end = 0;

        for (auto& meeting : meetings) {
            int start = meeting[0];
            int finish = meeting[1];

            if (start > end) {
                fd -= (finish - start + 1);
                end = finish;
            } else if (finish > end) {
                fd -= (finish - end);
                end = finish;
            }
        }
        return fd;
    }
};

