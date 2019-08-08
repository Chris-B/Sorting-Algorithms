#include "project1.h"
#include "random.h"
#include <cstdlib>

bool is_sorted(std::vector<int>& nums, int n) {
  int prev = nums[0];
  for(int i = 1; i < n; i++) {
    int curr = nums[i];
    if (curr < prev)
      return false;
    prev = curr;
  }
  return true;
}

void spin_the_bottle_sort(std::vector<int>& nums)
{
  int n = nums.size();
  while(!is_sorted(nums, n))
  {
    for(int i = 0; i < n; i++)
    {
      int s = uniform_rand_int(0, n-1);//uniform and independent random 0 <= s <= n-1
      if ((i < s && nums[i] > nums[s]) || (i > s && nums[i] < nums[s])) {
        int temp = nums[i];
        nums[i] = nums[s];
        nums[s] = temp;
      }
    }
  }
}
