#include <vector> // Required for using the vector type
#include <cstring> // Required for using the memset function

class Solution {
public:
    // Function to calculate the probability of getting exactly 'target' number of heads.
    double probabilityOfHeads(vector<double>& prob, int target) {
        // Create an array to store the probabilities of getting a certain number of heads
        vector<double> dp(target + 1, 0.0);
      
        // Initialize the probability of getting 0 heads to 1
        dp[0] = 1.0;
      
        // Iterate over the probability of heads for each coin toss
        for (double p : prob) {
            // Update the probabilities in reverse order to avoid overwriting values needed for calculations
            for (int j = target; j >= 0; --j) {
                // When a coin turns up tails, probability is (1 - probability of head) * probability of previous state
                dp[j] *= (1 - p);
              
                // If not the first coin (since we can't have a negative number of coins), 
                // add the probability of getting one less head multiplied by the probability of getting head
                if (j > 0) {
                    dp[j] += p * dp[j - 1];
                }
            }
        }
        // Return the probability of getting exactly 'target' number of heads
        return dp[target];
    }
};
