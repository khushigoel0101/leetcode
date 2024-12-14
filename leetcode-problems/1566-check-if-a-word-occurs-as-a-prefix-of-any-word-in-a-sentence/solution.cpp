class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        sentence = " " + sentence + " ";
        int p =0,f=0;
        for(int i =0;i<sentence.length();i++){
            if(sentence[i]==' '){
                p++;
                if(sentence.substr(i+1).starts_with(searchWord)){
                    f = 1;
                    break;
                }
            }
        }
        if(f==1){
            return p;
        }
        else{
            return -1;
        }
        
    }
};
