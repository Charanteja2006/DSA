class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        if(words[startIndex] == target ) return 0;
        
        int i = (startIndex + 1)%n;
        int count = 1;
        int mini = INT_MAX;
        while(i!=startIndex){
            if(words[i] == target){
                mini = count;
                break;
            }
            count++;
            i = (i+1)%n;
        }
        count = 1;
        i = (startIndex - 1 + n)%n;
        while(i != startIndex){
             if(words[i] == target){
                mini = min(mini,count);
                break;
            }
            count++;
            i = (i- 1 +n)%n;
        }

        return mini==INT_MAX?-1:mini;
    }
};