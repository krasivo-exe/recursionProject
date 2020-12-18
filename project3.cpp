//
// Created by nicho on 9/15/2020.
//

#include "project3.h"
#include <fstream>
#include <iostream>
void project3::read_numbers(std::string fileName, std::vector<int> &nums)
{
    std::ifstream heavensDoor;
    heavensDoor.open(fileName.c_str(),std::ios_base::in);
    int num = -1;
    while(heavensDoor >> num) nums.push_back(num);
}
int project3::count_inversions_iterative(const std::vector<int> &numbers)
{
    int inversionCount = 0;
    for(int i = 0;i<numbers.size()-1;i++)
        if(numbers[i] > numbers[i+1]) inversionCount++;
    return inversionCount;//cycle through the whole thing once to get it to work
}
int project3::count_inversions_recursive(const std::vector<int> &numbers, int n)
{
    if(n<=1) return 0; //base case
    if (numbers[n-1] > numbers[n-2]) return (count_inversions_recursive(numbers, n - 1));//if not an inversion
    return (1 + count_inversions_recursive(numbers, n - 1));//if an inversion
}
void project3::largest_left_iterative(const std::vector<int> &numbers, std::vector<int> &result)
{
    for(int i = 0; i<numbers.size();i++)
        result.push_back(nearestLeft(numbers,i));
}
int project3::nearestLeft(const std::vector<int> &numbers, int index)
{
    int thiccBoi = 0;
    for(int i = 0; i<index;i++)
       if(numbers[i] > numbers[index] ) thiccBoi = numbers[i];

    return thiccBoi;
}
void project3::largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n)
{
    if(n==0) return;
    result.push_back(nearestFren(numbers, numbers.size()-n,0));
    //std::cout << numbers[numbers.size()-n] << std::endl;
    largest_left_recursive(numbers,result,n-1);
}
int project3::nearestFren(const std::vector<int> &numbers, int index, int steps)
{
    //find nearest left large item
  //  std::cout << numbers[index] << " " << numbers[index-steps]<< std::endl;
  if((index-steps)<0) return 0;
  if(numbers[index] >= numbers[index-steps]) return nearestFren(numbers,index,steps+1);
  if(numbers[index] < numbers[index-steps]) return numbers[index-steps];


}
void project3::larger_left_right_iterative(const std::vector<int> &numbers, std::vector<int> &result)
{
    int left,right = 0;//okay so the idea is to pull both the left and the right and take the bigger one
    for(int i = 0;i<numbers.size();i++)
    {
        left = idxleft(numbers,i);
        right = idxright(numbers,i);
        //std::cout << i<< " "<<left << " " << right << " " << numbers[left] << " " << numbers[right]<<std::endl;
        if(numbers[left] > numbers[right]) result.push_back(numbers[left]);
        if(numbers[left] < numbers[right]) result.push_back(numbers[right]);
        if(numbers[left] ==  numbers[right]) result.push_back(0);//I figured the only time this case activates is when we need a 0
    }
}
int project3::idxleft(const std::vector<int> &numbers, int index)
{
    if(index == 0) return 0;
    //std::cout << "index: " << index << std::endl;
    int thiccBoi = 0;
    for(int i = 0; i<index;i++)
        if(numbers[i] > numbers[index] ) thiccBoi = i;
    return thiccBoi;
}
int project3::idxright(const std::vector<int> &numbers, int index)
{
    //honestly I feel horrible about how this method turned out, I mean sure it works but still the break seems like
    //a total stop gap.
    int thiccBoi = 0;
    for(int i = index; i<numbers.size();i++)
        if(numbers[i] > numbers[index] ) {
            thiccBoi = i;
            break;
        }
        return thiccBoi;
}
void project3::larger_left_right_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n)
{
    if(n==0) return;
    result.push_back(numFinder(numbers,numbers.size()-n));
    larger_left_right_recursive(numbers,result,n-1);
}
int project3::numFinder(const std::vector<int> &numbers, int index)
{//find the correct indexes on each side, evaluate, and return
    int left,right = 0;
    left = idxRleft(numbers,index,0);
    right = idxRright(numbers,index,0);
  // std::cout << index << " " << left << " " << right <<std::endl;
    if(left == 0 && right == numbers.size()) return 0;
    else if(right == numbers.size()) return numbers[left];
    if(numbers[left] > numbers[right]) return(numbers[left]);
    if(numbers[left] < numbers[right]) return(numbers[right]);

}
int project3::idxRleft(const std::vector<int> &numbers, int index, int steps)
{
    //find nearest left large item
  //    std::cout << index<<" (left) "<< numbers[index] << " " << numbers[index-steps]<< std::endl;
    if((index-steps)<=0) return 0;
    if(numbers[index] >= numbers[index-steps]) return idxRleft(numbers,index,steps+1);
    if(numbers[index] < numbers[index-steps]) return (index-steps);

}
int project3::idxRright(const std::vector<int> &numbers, int index, int steps)
{
    //find nearest right large item
  // std::cout << index<<" (right)"<< numbers[index] << " "<< steps<< std::endl;
    if((index+steps)>=numbers.size()-1) return numbers.size();
    if(numbers[index] >= numbers[index+steps]) return idxRright(numbers,index,steps+1);
    if(numbers[index] < numbers[index+steps]) return (index+steps);
}
int project3::increasing_sequences_iterative(std::vector<int> &numbers)
{
    //count the streak
    int streak = 1,counter=0;
    for(int i = 0;i<numbers.size()-1;i++)
    {
        if(numbers[i]<=numbers[i+1]) streak++;
        else
        {
            if(streak > counter) counter = streak;
            streak = 1;
        }

    }
    return counter;
}
int project3::increasing_sequences_recursive(std::vector<int> &numbers, int startIdx)
{

    if(startIdx == numbers.size()-1) return 0;
    if(startIdx == 0) return 1+increasing_sequences_recursive(numbers,startIdx+1);
    int nums = (finder(numbers,startIdx)-startIdx);
    if( nums > increasing_sequences_recursive(numbers,startIdx+1))return nums;
    return (increasing_sequences_recursive(numbers,startIdx+1));

}
int project3::finder(std::vector<int> &numbers, int idx) {
    if(idx == numbers.size()-1)return 0;
    if(numbers[idx] >= numbers[idx-1]) return (finder(numbers,idx+1));
    if(numbers[idx]< numbers[idx-1]) return idx;
}

