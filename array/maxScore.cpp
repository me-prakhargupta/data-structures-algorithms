#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();

    // Step 1: Take first k elements from the left
    int leftSum = 0;
    for(int i = 0; i < k; i++) {
        leftSum += cardPoints[i];
    }

    // Initialize maxSum with the case where all k cards are taken from left
    int maxSum = leftSum;

    int rightSum = 0;
    int right = n - 1;

    // Step 2: Gradually shift selection from left to right
    // Remove one card from left and add one from right
    for(int left = k - 1; left >= 0; left--) {
        leftSum -= cardPoints[left];      // remove from left
        rightSum += cardPoints[right];    // add from right
        right--;

        // Update maximum score
        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main() {
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;

    cout << maxScore(cardPoints, k);
    return 0;
}