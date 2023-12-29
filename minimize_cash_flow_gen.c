#include <stdio.h>

int minOf2(int x, int y) {
    return (x < y) ? x : y;
}

int getMin(int arr[], int person) {
    int minInd = 0;
    for (int i = 1; i < person; i++)
        if (arr[i] < arr[minInd])
            minInd = i;
    return minInd;
}

int getMax(int arr[], int person) {
    int maxInd = 0;
    for (int i = 1; i < person; i++)
        if (arr[i] > arr[maxInd])
            maxInd = i;
    return maxInd;
}

void minCashFlowRec(int amount[], int person) {
    int mxCredit = getMax(amount, person), mxDebit = getMin(amount, person);

    if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
        return;

    int min = minOf2(-amount[mxDebit], amount[mxCredit]);
    amount[mxCredit] -= min;
    amount[mxDebit] += min;

    printf("Person %d pays %d to Person %d\n", mxDebit, min, mxCredit);

    minCashFlowRec(amount, person);
}

void minCashFlow(int graph[][100], int person) {
    int amount[person];

    for (int p = 0; p < person; p++)
        amount[p] = 0;

    for (int p = 0; p < person; p++)
        for (int i = 0; i < person; i++)
            amount[p] += (graph[i][p] - graph[p][i]);

    minCashFlowRec(amount, person);
}

int main() {
    int person;
    printf("Enter the number of persons: ");
    scanf("%d", &person);

    int graph[100][100];  // Assuming a maximum of 100 persons
    for (int i = 0; i < person; i++)
        for (int j = 0; j < person; j++) {
            if (i == j) {
                graph[i][j] = 0;
                continue;
            }
            printf("Enter the amount person %d needs to pay person %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }

    minCashFlow(graph, person);
    return 0;
}
