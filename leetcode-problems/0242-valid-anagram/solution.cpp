class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26];
        if(s.length()!=t.length())return false;
        for(int i = 0; i<s.length(); i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;
        }
        for(int n: arr){
            if(n!=0) return false;
        }
        return true;
    }
};
