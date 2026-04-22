#include <stdio.h>
struct Item {
    int value;
    int weight;
};
void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}
void sortByRatio(struct Item arr[], int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            float r1 = (float)arr[i].value / arr[i].weight;
            float r2 = (float)arr[j].value / arr[j].weight;

            if(r1 < r2) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}
float fractionalKnapsack(struct Item arr[], int n, int capacity) {
    sortByRatio(arr, n);
    float totalValue = 0.0;
    int i;

    for(i = 0; i < n; i++) {
        if(arr[i].weight <= capacity) {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        } else {
            totalValue += arr[i].value * ((float)capacity / arr[i].weight);
            break;
        }
    }

    return totalValue;
}
int main() {
    int n, capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item arr[n];
    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].value, &arr[i].weight);
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    float maxValue = fractionalKnapsack(arr, n, capacity);
    printf("Maximum value in knapsack = %.2f\n", maxValue);
    return 0;
}
