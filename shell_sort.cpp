#include "project1.h"

void shell_sort(std::vector<int>& nums, const std::vector<int>& gaps)
{
  int n = nums.size();
  for (int m = 0; m < gaps.size(); m++)
  {
    int gap = gaps[m];
    for (int i = gap; i < n; i++)
    {
      int temp = nums[i];
      int j;
      for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
      {
        nums[j] = nums[j - gap];
      }
      nums[j] = temp;
    }
  }
}
