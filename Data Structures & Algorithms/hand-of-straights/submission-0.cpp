class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
       if(hand.size() % groupSize != 0){
        return false;
       } 
       map<int,int> mp;
       for(int card : hand){
         mp[card]++;
       }
       for(auto pair : mp){
        int card = pair.first;
        int count = pair.second;
        if(count > 0){
        for(int i = 0;i < groupSize;i++){
           int currentcard  = i + card;
            if(mp[currentcard] < count){
                return false;
            }
            mp[currentcard] -= count;
        }
        }
       }
       return true;
    }
};