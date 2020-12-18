//
// Created by nicho on 9/15/2020.
//
#include <vector>
#include <string>

#ifndef PROJECT3_PROJECT3_H
#define PROJECT3_PROJECT3_H


class project3
{
public:
    static void read_numbers(std::string fileName, std::vector<int> &nums);
    static int count_inversions_iterative(const std::vector<int> &numbers);
    static int count_inversions_recursive(const std::vector<int> &numbers, int n);
    static void largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result);
    static void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
    static void larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result);
    static void larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
    static int increasing_sequences_iterative(std::vector<int> &numbers);
    static int increasing_sequences_recursive(std::vector<int> &numbers, int startIdx);
private:
    static int nearestLeft(const std::vector<int> &numbers, int index);//for l iterative
    static int nearestFren(const std::vector<int> &numbers, int index, int steps);//for l recursive
    static int idxleft(const std::vector<int> &numbers, int index);//for l/r iterative
    static int idxright(const std::vector<int> &numbers, int index);//for l/r iterative
    static int numFinder(const std::vector<int> &numbers,int index);//for l/r recursive
    static int idxRleft(const std::vector<int>&numbers, int index,int steps);//lr recursive
    static int idxRright(const std::vector<int>&numbers, int index,int steps);//lr recursive
    static int finder(std::vector<int> &vector, int idx);
};


#endif //PROJECT3_PROJECT3_H
