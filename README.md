# recursionProject
a both iterative and recursive solution

This program stipulated 4 problems that I needed to solve:

Count inversions: Count the number of inversion in a vector that contains n elements. Two adjacent elements in a vector are inverted if the first element is larger than the element next to it. 

Largest Left:Given a vector of values each of which is larger than zero, for each value, find the closest element that comes before it and is larger than it.

Larger Left Right: Given a vector of values each of which is larger than zero, for each value, find the larger of two values, one that is larger than it and comes before it, and one that is larger than it and comes after it.  In either case, the indices of the larger values, if they both exist, should be closest to the index of the original value.

Increasing sequences: Find the length of the longest (adjacent) increasing subsequence in a vector with n elements.

Here are the methods I implemented:
int count_inversions_iterative(const std::vector<int> &numbers);

int count_inversions_recursive(const std::vector<int> &numbers, int n);

void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result);

void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);

void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result);

void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);

int increasing_sequences_iterative(std::vector<int> &numbers);

int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx);

void read_numbers(std::string fileName, std::vector<int> &v);
  
  
