

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Step 1: Sort points by x ascending, y descending
        sort(points.begin(), points.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0]) return a[1] > b[1];
                 return a[0] < b[0];
             });

        int pairCount = 0;
        int n = points.size();      // Correct C++ syntax
        int lowerYLimit;

        // Step 2: Iterate each point as upper-left
        for (int i = 0; i < n; i++) {
            int upperY = points[i][1];
            lowerYLimit = INT_MIN;  // Use INT_MIN

            for (int j = i + 1; j < n; j++) {
                int currentY = points[j][1];

                if (currentY <= upperY && currentY > lowerYLimit) {
                    pairCount++;
                    lowerYLimit = currentY;

                    if (currentY == upperY) break;  // stop early
                }
            }
        }

        return pairCount;
    }
};


