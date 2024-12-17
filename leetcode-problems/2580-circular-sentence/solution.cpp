class Solution {
public:
    bool isCircularSentence(string sentence) {
        int f = 0;
        for(int i =0; i<sentence.length(); i++){
            if(sentence[i]==' '){
                if(sentence[i-1]!=sentence[i+1]){
                    f=1;
                    break;
                }
            }
        }
        if(f==0 && sentence[0]==sentence[sentence.length()-1]){
            return true;
        }
        else{
            return false;
        }
    }
};
