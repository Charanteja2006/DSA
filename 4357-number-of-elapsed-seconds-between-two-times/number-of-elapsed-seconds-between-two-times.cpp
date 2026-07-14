class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int ss = 0;
        int es = 0;

        ss = stoi(startTime.substr(0,2))*60*60 + stoi(startTime.substr(3,2))*60
                                               +  stoi(startTime.substr(6,2));
        es = stoi(endTime.substr(0,2))*60*60 + stoi(endTime.substr(3,2))*60
                                               +  stoi(endTime.substr(6,2));

        return es - ss;
         
    }
};