#include<iostream>
#include<deque>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int constrainedSum(vector<int>& nums, int k) {
    int sum = 0;
    deque<int> dq;

    pair<int, int> p;
    

    for(int i = 0; i < nums.size(); i++) {
        if(!dq.empty() && dq.front() <= i - k) {
            sum += nums[dq.front()];
            dq.pop_front();
        }

        dq.push_back(i);
    }

    return sum;
}

int main() {
    vector<int> nums = {10,2,-10,5,20};
    int k = 2;
    return 0;
}