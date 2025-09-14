class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};  

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string vowels = "aeiou";
        int maxVowel = 0, maxConsonant = 0;

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;
            if (freq[i] > 0) {
                if (vowels.find(c) != string::npos) {
                    maxVowel = max(maxVowel, freq[i]);
                } else {
                    maxConsonant = max(maxConsonant, freq[i]);
                }
            }
        }

        return maxVowel + maxConsonant;
    }
};

