# Sorting

## Overview
1. Write a small function that verifies that a collection is in sorted order. template<typename Comparable, typename Comparator>, bool VerifyOrder(const vector<Comparable> &input, Comparator less_than).
The above function should return true if and only if the input is in sorted order according to the Comparator.
2. Write two functions, one that generates a random vector, and another that
generates a sorted vector. vector<int> GenerateRandomVector(size_t size_of_vector), vector<int> GenerateSortedVector(size_t size_of_vector, bool
smaller_to_larger). The sorted vector should generate a vector of increasing or
decreasing values based on bool smaller_to_larger

## Thoughts
1. Modify "HeapSort" method, "QuickSort" method, and "MergeSort" method. 
2. Modify "Median of Three" method, "MiddlePivot" method, and "FirstPivot" method. 
3. Modify "VerifyOrder" method, "GenerateRandomVector" method, "GenerateSortedVector" method, 
"ComputeDuration" method, and "sortTestingWrapper" method. 
4. Seperate "HeapSort, MergeSort, QuickSort" and "Median of Three, Middle, First" 
with a line of code said that "Testing Quicksort Pivot Implementations". 
5. Make the driver format correct. 

## Run
- To compile on terminal type:
1. make clean
2. make all

- To delete executables and object file type:
1. make clean

- To run with a given file that is redirected to standard input:
1. ./test_sorting_algorithms random 20000 less
2. ./test_sorting_algorithms sorted 10000 greater
