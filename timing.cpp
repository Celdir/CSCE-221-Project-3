////////////////////////////////////////////////////////////////////////////////
/// @brief Example timing file. Add to this file the functions you want to time
////////////////////////////////////////////////////////////////////////////////

#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "algorithm.h"

using namespace std;
using namespace chrono;

/// @todo Modify timing.cpp to evaluate the various sorting algorithms on the
///       following input types:
///       - Random sequence
///       - Sorted sequence
///       - Reverse sorted sequence
///       - A few unique elements sequence

/// @brief Generate random sequence and bubble_sort
/// @param k Vector size
void bubble_sort_random_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(rand());

  mystl::bubble_sort(v.begin(), v.end(), less<int>());
}

void bubble_sort_already_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(i);

  mystl::bubble_sort(v.begin(), v.end(), less<int>());
}

void bubble_sort_reverse_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(k-1-i);

  mystl::bubble_sort(v.begin(), v.end(), less<int>());
}

void bubble_sort_few_unique_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(1);
  for (size_t i = 0; i < k; i += std::log2(k))
    v[i] = 2;

  mystl::bubble_sort(v.begin(), v.end(), less<int>());
}

/// @brief Generate random sequence and selection_sort
/// @param k Vector size
void selection_sort_random_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(rand());

  mystl::selection_sort(v.begin(), v.end(), less<int>());
}

void selection_sort_already_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(i);

  mystl::selection_sort(v.begin(), v.end(), less<int>());
}

void selection_sort_reverse_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(k-1-i);

  mystl::selection_sort(v.begin(), v.end(), less<int>());
}

void selection_sort_few_unique_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(1);
  for (size_t i = 0; i < k; i += std::log2(k))
    v[i] = 2;

  mystl::selection_sort(v.begin(), v.end(), less<int>());
}

/// @brief Generate random sequence and insertion_sort
/// @param k Vector size
void insertion_sort_random_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(rand());

  mystl::insertion_sort(v.begin(), v.end(), less<int>());
}

void insertion_sort_already_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(i);

  mystl::insertion_sort(v.begin(), v.end(), less<int>());
}

void insertion_sort_reverse_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(k-1-i);

  mystl::insertion_sort(v.begin(), v.end(), less<int>());
}

void insertion_sort_few_unique_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(1);
  for (size_t i = 0; i < k; i += std::log2(k))
    v[i] = 2;

  mystl::insertion_sort(v.begin(), v.end(), less<int>());
}

/// @brief Generate random sequence and quick_sort
/// @param k Vector size
void quick_sort_random_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(rand());

  mystl::quick_sort(v.begin(), v.end(), less<int>());
}

void quick_sort_already_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(i);

  mystl::quick_sort(v.begin(), v.end(), less<int>());
}

void quick_sort_reverse_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(k-1-i);

  mystl::quick_sort(v.begin(), v.end(), less<int>());
}

void quick_sort_few_unique_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(1);
  for (size_t i = 0; i < k; i += std::log2(k))
    v[i] = 2;

  mystl::quick_sort(v.begin(), v.end(), less<int>());
}

/// @brief Generate random sequence and merge_sort
/// @param k Vector size
void merge_sort_random_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(rand());

  mystl::merge_sort(v.begin(), v.end(), less<int>());
}

void merge_sort_already_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(i);

  mystl::merge_sort(v.begin(), v.end(), less<int>());
}

void merge_sort_reverse_sorted_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(k-1-i);

  mystl::merge_sort(v.begin(), v.end(), less<int>());
}

void merge_sort_few_unique_sequence_k(size_t k) {
  vector<int> v;
  for(size_t i = 0; i < k; ++i)
    v.push_back(1);
  for (size_t i = 0; i < k; i += std::log2(k))
    v[i] = 2;

  mystl::merge_sort(v.begin(), v.end(), less<int>());
}

/// @brief Control timing of a single function
/// @tparam Func Function type
/// @param f Function taking a single size_t parameter
/// @param max_size Maximum size of test. For linear - 2^23 is good, for
///                 quadrati - 2^18 is probably good enough, but its up to you.
/// @param name Name of function for nice output
///
/// Essentially this function outputs timings for powers of 2 from 2 to
/// max_size. For each timing it repeats the test at least 10 times to ensure
/// a good average time.
template<typename Func>
void time_function(Func f, size_t max_size, string name) {
  cout << "Function: " << name << endl;
  cout << setw(15) << "Size" << setw(15) << "Time(sec)" << endl;

  // Loop to control input size
  for(size_t i = 2; i < max_size; i*=2) {
    cout << setw(15) << i;

    // create a clock
    high_resolution_clock::time_point start = high_resolution_clock::now();

    // loop a specific number of times to make the clock tick
    size_t num_itr = max(size_t(10), max_size / i);
    for(size_t j = 0; j < num_itr; ++j)
      f(i);

    // calculate time
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    duration<double> diff = duration_cast<duration<double>>(stop - start);

    cout << setw(15) << diff.count() / num_itr << endl;
  }
}

/// @brief Main function to time all your functions
int main() {
  time_function(bubble_sort_random_sequence_k, pow(2, 15), "Bubble Sort Random Sequence");
  time_function(bubble_sort_already_sorted_sequence_k, pow(2, 15), "Bubble Sort Pre-sorted Sequence");
  time_function(bubble_sort_reverse_sorted_sequence_k, pow(2, 15), "Bubble Sort Reverse Sorted Sequence");
  time_function(bubble_sort_few_unique_sequence_k, pow(2, 15), "Bubble Sort Sequence with Few Unique Elements");
  time_function(selection_sort_random_sequence_k, pow(2, 17), "Selection Sort Random Sequence");
  time_function(selection_sort_already_sorted_sequence_k, pow(2, 17), "Selection Sort Pre-sorted Sequence");
  time_function(selection_sort_reverse_sorted_sequence_k, pow(2, 17), "Selection Sort Reverse Sorted Sequence");
  time_function(selection_sort_few_unique_sequence_k, pow(2, 17), "Selection Sort Sequence with Few Unique Elements");
  time_function(insertion_sort_random_sequence_k, pow(2, 17), "Insertion Sort Random Sequence");
  time_function(insertion_sort_already_sorted_sequence_k, pow(2, 17), "Insertion Sort Pre-sorted Sequence");
  time_function(insertion_sort_reverse_sorted_sequence_k, pow(2, 17), "Insertion Sort Reverse Sorted Sequence");
  time_function(insertion_sort_few_unique_sequence_k, pow(2, 17), "Insertion Sort Sequence with Few Unique Elements");
  time_function(merge_sort_random_sequence_k, pow(2, 23), "MergeSort Random Sequence");
  time_function(merge_sort_already_sorted_sequence_k, pow(2, 23), "MergeSort Pre-sorted Sequence");
  time_function(merge_sort_reverse_sorted_sequence_k, pow(2, 23), "MergeSort Reverse Sorted Sequence");
  time_function(merge_sort_few_unique_sequence_k, pow(2, 23), "MergeSort Sequence with Few Unique Elements");
  time_function(quick_sort_random_sequence_k, pow(2, 23), "QuickSort Random Sequence");
  time_function(quick_sort_already_sorted_sequence_k, pow(2, 23), "QuickSort Pre-sorted Sequence");
  time_function(quick_sort_reverse_sorted_sequence_k, pow(2, 23), "QuickSort Reverse Sorted Sequence");
  time_function(quick_sort_few_unique_sequence_k, pow(2, 23), "QuickSort Sequence with Few Unique Elements");
}
