#include <iostream>
#include <vector>
#include <algorithm>

int largestSumAfterKNegations(std::vector<int>& nums, int k) {
    // Step 1: Sort the array
    std::sort(nums.begin(), nums.end());

    // Step 2: Flip the most negative numbers
    for (int i = 0; i < nums.size() && k > 0; ++i) {
        if (nums[i] < 0) {
            nums[i] = -nums[i];
            --k;
        }
    }

    // Step 3: If k is still positive and odd, flip the smallest absolute number
    if (k % 2 == 1) {
        std::sort(nums.begin(), nums.end());
        nums[0] = -nums[0];
    }

    // Step 4: Return the sum of the modified array
    int sum = 0;
    for (int num : nums) {
        sum += num;
    }
    return sum;
}

int main() {
    std::vector<int> nums = {4, 2, 3};
    int k = 1;
    std::cout << largestSumAfterKNegations(nums, k) << std::endl;  // Output should be 5
    return 0;
}
