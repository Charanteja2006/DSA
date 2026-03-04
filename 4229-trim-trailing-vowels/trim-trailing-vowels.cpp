class Solution {
public:
    bool vowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string trimTrailingVowels(string s) {
        int n = s.size();
        int i = n-1;
        while(i>=0&&vowel(s[i])) i--;

        return s.substr(0,i+1); 
    }
};