class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 0;
        int maxCap = 0;
        
        // Find the boundary for binary search
        for (int weight : weights) {
            minCap = max(minCap, weight); // The ship must be at least as large as the heaviest package
            maxCap += weight;                  // The maximum possible capacity is the sum of all packages
        }

        // Apply binary search to find the minimum capacity
        while (minCap < maxCap) {
            int mid = minCap + (maxCap - minCap) / 2;
            
            // Try to ship with "mid" capacity
            int d = 1;
            int sum = 0;
            for (int weight : weights) {
                if (sum + weight > mid) {
                    d++;
                    sum = 0;
                }
                sum += weight;
            }
            
            // If more days are required, it means the capacity is too low
            if (d > days ) {
                minCap = mid + 1; // Increase capacity
            } else {
                maxCap = mid;     // Try to look for a smaller capacity
            }
        }
        
        return minCap;
    }
};