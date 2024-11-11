#include <iostream>
#include <algorithm>

using namespace std;

// Structure to store item details
struct Item {
    double weight;
    double value;
};

// Comparator function to sort items based on value-to-weight ratio
bool compare(Item a, Item b) {
    return (a.value / a.weight) > (b.value / b.weight);
}

// Function to calculate the maximum value in the knapsack
double fractionalKnapsack(Item items[], int n, double capacity) {
    // Sort items based on value-to-weight ratio
    sort(items, items + n, compare);

    double totalValue = 0.0;

    // Iterate through sorted items
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            // Take the whole item
            totalValue += items[i].value;
            capacity -= items[i].weight;
        } else {
            // Take a fraction of the item
            totalValue += (items[i].value / items[i].weight) * capacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n;
    double W;

    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> W;

    // Arrays to store weights and values of items
    Item items[n];

    // Input weights and values of items
    cout << "Enter weights and values of each item:\n";
    for (int i = 0; i < n; i++) {
        cout << "Weight of item " << i + 1 << ": ";
        cin >> items[i].weight;
        cout << "Value of item " << i + 1 << ": ";
        cin >> items[i].value;
    }

    // Calculate maximum value
    double maxValue = fractionalKnapsack(items, n, W);

    // Output the result
    cout << "Maximum value in knapsack: " << maxValue << endl;

    return 0;
}
