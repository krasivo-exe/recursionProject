#include <iostream>
#include "project3.h"
void printVector(std::vector<int> nums)
{
    for(int i = 0;i<nums.size();i++) std::cout<<nums[i]<<std::endl;//I know this function is disgusting but im lazy
}
int main(int argc, char *argv[])
{
    if( argc != 2 )
    {
        std::cout << "usage:" << argv[0] << " nameOfInputFile\n";
        exit(2);
    }
    std::vector<int> nums,res;
    project3::read_numbers(argv[1],nums);
    //for(int i = 0; i<nums.size();i++) std::cout << nums[i] << std::endl;
    std::cout << "Count inversion iterative: " <<project3::count_inversions_iterative(nums)<< std::endl;
    std::cout << "Count inversion recursive: "<<project3::count_inversions_recursive(nums,nums.size())<< std::endl;
    project3::largest_left_iterative(nums,res);
    printVector(res);
    res.clear();
    project3::largest_left_recursive(nums,res,nums.size());
    printVector(res);
    res.clear();
    project3::larger_left_right_iterative(nums,res);
    printVector(res);
    res.clear();
    project3::larger_left_right_recursive(nums,res,nums.size());
    printVector(res);
    res.clear();
    std::cout << "increasing sequences iterative: " << project3::increasing_sequences_iterative(nums)<<std::endl;
    std::cout << "increasing sequences recursive: " << project3::increasing_sequences_recursive(nums,0)<<std::endl;
    return 0;
}