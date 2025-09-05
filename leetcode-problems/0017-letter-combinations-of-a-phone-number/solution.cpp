class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        
        vector<string> mapping = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };

        
        vector<string> result;
        result.push_back("");  
        
        for (char digit : digits) {
            vector<string> temp; 
            string letters = mapping[digit - '0'];

            for (string combination : result) {  
                for (char letter : letters) {    
                    temp.push_back(combination + letter);
                }
            }

            result = temp; 
        }

        return result;
    }
};

