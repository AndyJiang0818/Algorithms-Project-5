// Xihao Jiang
// CSCI 335
// Homework 5
// 4/25/21
// Testing Sorting Algorithms

#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

// Test function that shows how you can time a piece of code.
// Just times a simple loop.

void TestingTiming()
{
  cout << "Testing Timing" << endl;
  const auto begin = chrono::high_resolution_clock::now();
  // Time this piece of code.
  int sum = 0;
  for (int i = 1; i < 10000; ++i)
    sum++;
  // End of piece of code to time.
  const auto end = chrono::high_resolution_clock::now();
  cout << chrono::duration_cast<chrono::nanoseconds>(end - begin).count() << "ns" << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << "ms" << endl;
}

// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector)
{
  // Use rand() to generate random integer
  // Add code
  vector<int> input_vector;
  for (size_t i = 0; i < size_of_vector; i++)
  {
    input_vector.push_back(rand());
  }
  return input_vector;
}

// Generate and returns sorted vector of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger)
{
  // Add code
  vector<int> input_vector;
  for (size_t i = 0; i < size_of_vector; i++)
  {
    if (smaller_to_larger)
    {
      input_vector.push_back(i + 1);
    }
    else
    {
      input_vector.push_back(size_of_vector - i);
    }
  }
  return input_vector;
}

// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than)
{
  // Add code
  vector<Comparable> comp = vector<Comparable>(input);
  sort(comp.begin(), comp.end(), less_than);
  return comp == input;
}

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time)
{
  // Add code
  return chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
}

// Wrapper function to test the different sorting algorithms
int testSortingWrapper(int argc, char **argv)
{
  const string input_type = string(argv[1]);
  const int input_size = stoi(string(argv[2]));
  const string comparison_type = string(argv[3]);
  if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small")
  {
    cout << "Invalid input type" << endl;
    return 0;
  }
  if (input_size <= 0)
  {
    cout << "Invalid size" << endl;
    return 0;
  }
  if (comparison_type != "less" && comparison_type != "greater")
  {
    cout << "Invalid comparison type" << endl;
    return 0;
  }

  // This block of code to be removed for your final submission.
  //TestingTiming();

  cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
  vector<int> input_vector, copy_vector;
  if (input_type == "random")
  {
    // Generate random vector
    srand(time(NULL));
    input_vector = GenerateRandomVector(input_size);
  }
  else
  {
    // Generate sorted vector.
    if (comparison_type == "less")
    {
      input_vector = GenerateSortedVector(input_size, true);
    }
    else
    {
      input_vector = GenerateSortedVector(input_size, false);
    }
  }

  // Call quicksort / heapsort / mergesort using appropriate input.
  // HeapSort
  cout << endl
       << "HeapSort" << endl;
  copy_vector = vector<int>(input_vector);
  auto startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    heapsort(copy_vector, less<int>{});
  }
  else
  {
    heapsort(copy_vector, greater<int>{});
  }
  auto endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(copy_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(copy_vector, greater<int>{}) << endl;
  }

  // MergeSort
  cout << endl
       << "MergeSort" << endl;
  copy_vector = vector<int>(input_vector);
  startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    mergeSort(copy_vector, less<int>{});
  }
  else
  {
    mergeSort(copy_vector, greater<int>{});
  }
  endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(copy_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(copy_vector, greater<int>{}) << endl;
  }

  // QuickSort
  cout << endl
       << "QuickSort" << endl;
  copy_vector = vector<int>(input_vector);
  startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    quicksort(copy_vector, less<int>{});
  }
  else
  {
    quicksort(copy_vector, greater<int>{});
  }
  endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(copy_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(copy_vector, greater<int>{}) << endl;
  }

  cout << endl
       << "Testing Quicksort Pivot Implementations" << endl;

  // Median of Three
  cout << endl
       << "Median of Three" << endl;
  copy_vector = vector<int>(input_vector);
  startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    quicksort(input_vector, less<int>{});
  }
  else
  {
    quicksort(input_vector, greater<int>{});
  }
  endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl;
  }

  // Middle
  cout << endl
       << "Middle" << endl;
  copy_vector = vector<int>(input_vector);
  startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    QuickSort2(copy_vector, less<int>{});
  }
  else
  {
    QuickSort2(copy_vector, greater<int>{});
  }
  endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl;
  }

  // First
  cout << endl
       << "First" << endl;
  copy_vector = vector<int>(input_vector);
  startSort = chrono::high_resolution_clock::now();
  if (comparison_type == "less")
  {
    QuickSort3(copy_vector, less<int>{});
  }
  else
  {
    QuickSort3(copy_vector, greater<int>{});
  }
  endSort = chrono::high_resolution_clock::now();
  cout << "Runtime: " << ComputeDuration(startSort, endSort) << " ns" << endl;
  if (comparison_type == "less")
  {
    cout << "Verified: " << VerifyOrder(input_vector, less<int>{}) << endl;
  }
  else
  {
    cout << "Verified: " << VerifyOrder(input_vector, greater<int>{}) << endl;
  }
}

// Do not change anything below

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
    return 0;
  }

  testSortingWrapper(argc, argv);

  return 0;
}
