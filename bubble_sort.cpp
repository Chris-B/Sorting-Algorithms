#include "project1.h"

void bubble_sort(std::vector<int>& nums) {
  int n = nums.size();
  int swapped = 1;
  while (swapped) {
    swapped = 0;
    for (int i = 1; i < n; i++) {
      if (nums.at(i) < nums.at(i-1)) {
        int temp = nums[i-1];
        nums[i-1] = nums[i];
        nums[i] = temp;
        swapped = 1;
      }
    }
  }
}
