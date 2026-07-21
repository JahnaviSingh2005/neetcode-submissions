class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxheap;
        for(int stone: stones){
            maxheap.push(stone);
        }
        while(maxheap.size() > 1){
            int f = maxheap.top();
            maxheap.pop();
            int s = maxheap.top();
            maxheap.pop();
            if(s < f){
                maxheap.push(f - s);
            }
        }
        maxheap.push(0);
        return maxheap.top();
    }
};