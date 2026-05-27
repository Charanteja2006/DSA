class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int> mp1,mp2;
        int n = word.size();

        for(int i=n-1;i>=0;i--){
            mp1[word[i]]++;
        }

        int count = 0;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                mp2[word[i]]++;
            }
            else{
                if(mp2[word[i]]) continue;
                char c = char(word[i]+32);
                int freq = mp1[c] - mp2[c];
                if(!freq && mp2[c]) count++;
                mp2[word[i]]++;
            }

        }
        return count;
    }
};