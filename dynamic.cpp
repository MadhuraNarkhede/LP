#include <iostream>
using namespace std;

// Function to find the maximum value that can be put in a knapsack of capacity W
int knapsack(int weights[], int values[], int n, int W) {
    // Create a 2D array to store the maximum value for each sub-problem
    int dp[n + 1][W + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            // Base case: if no items or weight is 0, value is 0
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (weights[i - 1] <= j) {
                // Include the item or exclude it, choose the maximum value
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                // Exclude the item
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    // The maximum value is stored in dp[n][W]
    return dp[n][W];
}

int main() {
    int n, W;

    // Input number of items and knapsack capacity
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Arrays to store weights and values of items
    int weights[n], values[n];

    // Input weights and values of items
    cout << "Enter weights and values of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> weights[i];
        cout << "Value of item " << i + 1 << ": ";
        cin >> values[i];
    }

    // Call the knapsack function and display the result
    int maxValue = knapsack(weights, values, n, W);
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
