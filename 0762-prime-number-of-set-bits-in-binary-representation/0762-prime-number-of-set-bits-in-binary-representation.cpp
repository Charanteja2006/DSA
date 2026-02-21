class Solution {
public:
    int countSet(int n){
        int count = 0;
        while(n>0){
            if(n%2) count++;
            n/=2;
        }

        return count;
    }

    int countPrimeSetBits(int left, int right) {
        set<int> s({2,3,5,7,11,13,19,17,23,29,31});
        int count = 0;
        for(int i=left;i<=right;i++){
            if(s.count(countSet(i))) count++;
        }
        
        return count;
    }
};