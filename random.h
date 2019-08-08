#include <random>
#include <algorithm>
#include <cmath>

#ifndef RANDOM_H
#define RANDOM_H

std::random_device rd;
std::mt19937 gen(rd());

int uniform_rand_int(int from, int to)
{
  std::uniform_int_distribution<int> distr(from, to);
  return distr(gen);
}

std::vector<int> get_shuffled_vector(int n)
{
  std::vector<int> nums = std::vector<int>(n);
  for(int i = 0; i < n; i++)
    nums[i] = i+1;
  std::shuffle(nums.begin(), nums.end(), gen);
  return nums;
}

std::vector<int> get_almost_sorted_vector(int n)
{
  std::vector<int> nums = std::vector<int>(n);
  for(int i = 0; i < n; i++)
    nums[i] = i+1;
  int swaps = 2*(int)log(n);
  while(swaps > 0) {
    std::uniform_int_distribution<int> distr(0, n-1);
    int i = distr(gen);
    int j = distr(gen);
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
    swaps--;
  }
  return nums;
}

void shuffle_vector(std::vector<int>& nums)
{
  std::shuffle(nums.begin(), nums.end(), gen);
}

#endif
