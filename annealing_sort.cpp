#include "project1.h"
#include <algorithm>

void annealing_sort(std::vector<int>& nums, const std::vector<int>& temps, const std::vector<int>& reps)
{
  int n = nums.size();
  for(int j = 0; j < temps.size(); j++)
  {
    for(int i = 0; i < (n-1); i++)
    {
      for(int k = 0; k < reps[j]; k++)
      {
        int s = uniform_rand_int(i+1, std::min(n-1, i + temps[j]));
        if (nums[i] > nums[s]) {
          int temp = nums[i];
          nums[i] = nums[s];
          nums[s] = temp;
        }
      }
    }
    for(int i = n-1; i > 0; i--)
    {
      for(int k = 0; k < reps[j]; k++)
      {
        int s = uniform_rand_int(std::max(0, i - temps[j]), i - 1);
        if (nums[s] > nums[i]) {
          int temp = nums[s];
          nums[s] = nums[i];
          nums[i] = temp;
        }
      }
    }
  }
}
