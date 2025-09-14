class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact_words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> case_insensitive;
        unordered_map<string, string> vowel_map;

        auto devowel = [](string s) {
            for (char &c : s) {
                if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') c = '*';
            }
            return s;
        };

        
        for (string word : wordlist) {
            string lower_word = word;
            for (char &c : lower_word) c = tolower(c);

            if (!case_insensitive.count(lower_word))
                case_insensitive[lower_word] = word;

            string vw = devowel(lower_word);
            if (!vowel_map.count(vw))
                vowel_map[vw] = word;
        }

       
        vector<string> ans;
        for (string q : queries) {
            if (exact_words.count(q)) {
                ans.push_back(q);
                continue;
            }

            string lower_q = q;
            for (char &c : lower_q) c = tolower(c);

            if (case_insensitive.count(lower_q)) {
                ans.push_back(case_insensitive[lower_q]);
                continue;
            }

            string vwq = devowel(lower_q);
            if (vowel_map.count(vwq)) {
                ans.push_back(vowel_map[vwq]);
                continue;
            }

            ans.push_back("");
        }

        return ans;
    }
};

