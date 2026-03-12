
#include <stdio.h>

// Structure to store item details
struct Item {
    int weight;     // weight of the item
    int profit;     // profit of the item
    float ratio;    // profit/weight ratio
};

// Function to sort items based on profit/weight ratio (Descending order)
void sort(struct Item items[], int n)
{
    struct Item temp;

    // Bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            // If current item's ratio is smaller than next, swap
            if (items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    float capacity;

    // Ask user for number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Create array of items
    struct Item itm[n];

    // Input weight and profit of each item
    for (int i = 0; i < n; i++)
    {
        printf("Enter item %d weight and profit: ", i + 1);
        scanf("%d %d", &itm[i].weight, &itm[i].profit);

        // Calculate profit/weight ratio
        itm[i].ratio = (float)itm[i].profit / itm[i].weight;
    }

    // Input knapsack capacity
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items based on ratio (highest first)
    sort(itm, n);

    float totalProfit = 0.0;

    // Apply Fractional Knapsack logic
    for (int i = 0; i < n; i++)
    {
        // If the whole item can be taken
        if (capacity >= itm[i].weight)
        {
            totalProfit += itm[i].profit;
            capacity -= itm[i].weight;
        }
        else
        {
            // Take fractional part of the item
            totalProfit += itm[i].ratio * capacity;
            break;
        }
    }

    // Print maximum profit
    printf("Maximum profit = %.2f\n", totalProfit);

    return 0;
}
