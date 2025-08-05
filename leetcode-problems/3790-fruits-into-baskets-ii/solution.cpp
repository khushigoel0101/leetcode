class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unplaced = 0;

        for (int i = 0; i < fruits.size(); i++) {
            bool placed = false;
            for (int j = 0; j < baskets.size(); j++) {
                if (baskets[j] != -1 && fruits[i] <= baskets[j]) {
                    baskets[j] = -1;
                    placed = true;
                    break;
                }
            }
            if (!placed) unplaced++;
        }

        return unplaced;
    }
};

