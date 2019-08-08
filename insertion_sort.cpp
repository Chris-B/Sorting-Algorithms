#include "project1.h"
#include <iostream>

void insertion_sort(std::vector<int>& nums) {
  int n = nums.size();
  int key, j;
  for (int i = 1; i < n; i++) {
    key = nums[i];
    for (j = i - 1; j >= 0 && key < nums[j]; j--)
      nums[j + 1] = nums[j];
    nums[j + 1] = key;
  }
}
