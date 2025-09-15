class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int c = 0; 
        for (int i = 0; i < text.length(); i++) {
            string t = "";         
            bool broken = false;   

            
            while (i < text.length() && text[i] != ' ') {
                t += text[i];
                if (brokenLetters.find(text[i]) != string::npos) {
                    broken = true;  
                }
                i++;
            }

            if (!broken && !t.empty()) {
                c++;  
            }
        }
        return c;
    }
};

