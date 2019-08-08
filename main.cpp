#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <cmath>
#include "random.h"
#include "bubble_sort.cpp"
#include "insertion_sort.cpp"
#include "spin_the_bottle_sort.cpp"
#include "shell_sort.cpp"
#include "annealing_sort.cpp"

struct timing
{
  int n;
  double seconds;
};

timing bubble_sort_uniform(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_shuffled_vector(n);
    std::clock_t start = clock();
    bubble_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing bubble_sort_almost(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_almost_sorted_vector(n);
    std::clock_t start = clock();
    bubble_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing insertion_sort_uniform(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_shuffled_vector(n);
    std::clock_t start = clock();
    insertion_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing insertion_sort_almost(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_almost_sorted_vector(n);
    std::clock_t start = clock();
    insertion_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing spin_the_bottle_sort_uniform(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_shuffled_vector(n);
    std::clock_t start = clock();
    spin_the_bottle_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing spin_the_bottle_sort_almost(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_almost_sorted_vector(n);
    std::clock_t start = clock();
    spin_the_bottle_sort(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

std::vector<int> get_gaps(int n)
{
  int size;
  switch(n) {
    case 10:
      size = 3;
      break;
    case 100:
      size = 5;
      break;
    case 1000:
      size = 8;
      break;
    case 10000:
      size = 10;
      break;
  }
  std::vector<int> gaps = std::vector<int>(size);
  for(int k = 0; k < size; k++)
  {
    //Sedgewick 1986
    if(k % 2 == 0) {
      gaps[k] = (9*(pow(2,k)-pow(2,k/2))) + 1;
    } else {
      int left = 8*pow(2,k);
      int right = (6*pow(2,(k+1)/2))+1;
      gaps[k] = left-right;
    }
  }
  return gaps;
}

timing shell_sort_uniform(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  std::vector<int> gaps = get_gaps(n);
  for(int i = 0; i < reps; i++)
  {
    nums = get_shuffled_vector(n);
    std::clock_t start = clock();
    shell_sort(nums, gaps);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing shell_sort_almost(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  std::vector<int> gaps = get_gaps(n);
  for(int i = 0; i < reps; i++)
  {
    nums = get_almost_sorted_vector(n);
    std::clock_t start = clock();
    shell_sort(nums, gaps);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

void annealing_schedule(std::vector<int>& nums)
{
  int n = nums.size();
  std::vector<int> T1 = std::vector<int>(n * 2);
  int t = (2*n)-1;
  while(t > 0) {
    T1.push_back(t);
    t--;
  }
  T1.push_back(0);
  std::vector<int> R1 = std::vector<int>(T1.size());
  for(int i = 0; i < T1.size(); i++)
    R1.push_back(n / 5);
  annealing_sort(nums, T1, R1);
}

timing annealing_sort_uniform(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_shuffled_vector(n);
    std::clock_t start = clock();
    annealing_schedule(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

timing annealing_sort_almost(int n, int reps)
{
  double total_time = 0.0;
  std::vector<int> nums;
  for(int i = 0; i < reps; i++)
  {
    nums = get_almost_sorted_vector(n);
    std::clock_t start = clock();
    annealing_schedule(nums);
    std::clock_t end = clock();
    total_time += (float)(end - start) / CLOCKS_PER_SEC;
  }
  timing t{n, (float)total_time/reps};
  return t;
}

void create_timing_file(std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::trunc);
  f << "funcname,n,seconds\n";
  f.close();
}

void add_timing_to_file(std::string func, timing t, std::string filename)
{
  std::ofstream f;
  f.open(filename, std::ios::app);
  f << func << "," << t.n << "," << t.seconds << "\n";
  f.close();
} 

int main()
{
  create_timing_file("timings.csv");
  std::vector<int> sizes{10, 100, 1000, 10000};
  int reps = 2;
  for(int i = 0; i < sizes.size(); i++) {
    int n = sizes[i];

    timing bubble_uniform = bubble_sort_uniform(n, reps);
    std::cout << "Bubble Uniform (" << n << "): " << bubble_uniform.seconds << std::endl;
    add_timing_to_file("bubble-uniform", bubble_uniform, "timings.csv"); 

    timing bubble_almost = bubble_sort_almost(n, reps);
    std::cout << "Bubble Almost (" << n << "): " << bubble_almost.seconds << std::endl << std::endl;
    add_timing_to_file("bubble-almost", bubble_almost, "timings.csv");


    timing insertion_uniform = insertion_sort_uniform(n, reps);
    std::cout << "Insertion Uniform (" << n << "): " << insertion_uniform.seconds << std::endl;
    add_timing_to_file("insertion-uniform", insertion_uniform, "timings.csv");

    timing insertion_almost = insertion_sort_almost(n, reps);
    std::cout << "Insertion Almost (" << n << "): " << insertion_almost.seconds << std::endl << std::endl;
    add_timing_to_file("insertion-almost", insertion_almost, "timings.csv");


    timing spin_uniform = spin_the_bottle_sort_almost(n, reps);
    std::cout << "Spin Uniform (" << n << "): " << spin_uniform.seconds << std::endl;
    add_timing_to_file("spin-uniform", spin_uniform, "timings.csv");

    timing spin_almost = spin_the_bottle_sort_almost(n, reps);
    std::cout << "Spin Almost (" << n << "): " << spin_almost.seconds << std::endl << std::endl;
    add_timing_to_file("spin-almost", spin_almost, "timings.csv");


    timing shell_uniform = shell_sort_uniform(n, reps);
    std::cout << "Shell Uniform (" << n << "): " << shell_uniform.seconds << std::endl;
    add_timing_to_file("shell-uniform", shell_uniform, "timings.csv");

    timing shell_almost = shell_sort_almost(n, reps);
    std::cout << "Shell Almost (" << n << "): " << shell_almost.seconds << std::endl << std::endl;
    add_timing_to_file("shell-almost", shell_almost, "timings.csv");

    timing annealing_uniform = annealing_sort_uniform(n, reps);
    std::cout << "Annealing Uniform (" << n << "): " << annealing_uniform.seconds << std::endl;
    add_timing_to_file("annealing-uniform", annealing_uniform, "timings.csv");

    timing annealing_almost = annealing_sort_almost(n, reps);
    std::cout << "Annealing Almost (" << n << "): " << annealing_almost.seconds << std::endl << std::endl;
    add_timing_to_file("annealing-almost", annealing_almost, "timings.csv");
    
  }
}
