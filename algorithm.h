////////////////////////////////////////////////////////////////////////////////
/// @brief Algorithms, e.g., sorting
/// @ingroup MySTL
/// @todo Implement swap
/// @todo Implement bubble sort
/// @todo Implement one of:
///       - Insertion Sort (in place)
///       - Selection Sort (in place)
/// @todo Implement one of:
///       - Heap Sort (in place)
///       - Merge Sort
///       - Quick Sort (in place)
/// @bonus Each extra sort you implement will be worth bonus points
////////////////////////////////////////////////////////////////////////////////

// Implemented by: David Earl and Gerald Hu

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <limits>
#include <vector>
#include <ctime>
#include <typeinfo>

namespace mystl {

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Swap values of two elements
    /// @tparam T Value type
    /// @param a First value
    /// @param b Second value
    template<typename T>
        void swap(T& a, T& b) {
            T temp = a;
            a = b;
            b = temp;
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Bubble Sort
    template<class RandomAccessIterator, class Compare>
        void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            bool isSorted = false;
            while (!isSorted) {
                RandomAccessIterator i = first;
                isSorted = true;
                while (i != last-1) {
                    RandomAccessIterator j = i + 1;
                    if (!comp(*i, *j)) {
                        swap(*i, *j);
                        isSorted = false;
                    }
                    ++i;
                }
                --last;
            }
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Selection Sort.
    template<class RandomAccessIterator, class Compare>
        void selection_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            while (first != last) {
                RandomAccessIterator i = first;
                RandomAccessIterator smallest = i;
                while (i != last) {
                    if (comp(*i, *smallest)) smallest = i;
                    ++i;
                }
                swap(*first, *smallest);
                ++first;
            }
        }

    ////////////////////////////////////////////////////////////////////////////////
    //p
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Insertion Sort
    template<class RandomAccessIterator, class Compare>
        void insertion_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            RandomAccessIterator start = first;
            while (start != last-1) {
                RandomAccessIterator i = start + 1;
                while (i > first && comp(*i, *(i-1))) {
                    swap(*i, *(i-1));
                    --i;
                }
                ++start;
            }
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Slow sort sorts in a non-optimal fashion. Select and implement one of:
    ///   -(a) insertion sort
    ///   -(b) selection sort
    /// Your sort should be inplace (uses no extra memory).
    template<class RandomAccessIterator, class Compare>
        void slow_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            //selection_sort(first, last, comp);
            insertion_sort(first, last, comp);
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Heap Sort.
    template<class RandomAccessIterator, class Compare>
        void heap_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Merge Sort.

    template<class RandomAccessIterator, class Compare>
        void merge(RandomAccessIterator first, RandomAccessIterator split, RandomAccessIterator last, Compare comp) {
            typedef typename RandomAccessIterator::value_type T;
            std::vector<T> merged(last - first);
            int index = 0;
            RandomAccessIterator left_smallest = first;
            RandomAccessIterator right_smallest = split;
            while (index < last - first) {
                if (right_smallest == last || (left_smallest < split && comp(*left_smallest, *right_smallest))) {
                    merged[index] = *left_smallest;
                    ++left_smallest;
                }
                else if (right_smallest < last) {
                    merged[index] = *right_smallest;
                    ++right_smallest;
                }
                ++index;
            }

            RandomAccessIterator place = first;
            for (auto i : merged) {
                *place = i;
                ++place;
            }
        }

    template<class RandomAccessIterator, class Compare>
        void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            if (last - first < 2) return;
            
            RandomAccessIterator split = first + (last - first) / 2;
            merge_sort(first, split, comp);
            merge_sort(split, last, comp);
            merge(first, split, last, comp);
        }


    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Quick Sort.
    template<class RandomAccessIterator, class Compare>
        void quick_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            auto pivot = first[std::rand() % (last - first)];
            RandomAccessIterator h1 = first;
            RandomAccessIterator h2 = last-1;

            while (h1 <= h2) {
                while (comp(*h1, pivot)) ++h1;
                while (comp(pivot, *h2)) --h2;
                if (h1 <= h2) {
                    swap(*h1, *h2);
                    ++h1;
                    --h2;
                }
            }
            if (first < h2) quick_sort(first, h2+1, comp);
            if (h1 < last) quick_sort(h1, last, comp);
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) into nondecreasing order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @tparam Compare Comparator function
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    /// @param comp Binary function that accepts two elements in the range as
    ///             arguments and returns a value convertable to bool. The value
    ///             returned indicates whether the element passed as first argument
    ///             is considered to go before the second in the ordering it
    ///             defines.
    ///
    /// Sort sorts in an optimal fashion. Select and implement one of:
    ///   -(a) heap sort  (in place)
    ///   -(b) merge sort
    ///   -(c) quick sort (in place)
    template<class RandomAccessIterator, class Compare>
        void sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
            quick_sort(first, last, comp);
            //merge_sort(first, last, comp);
        }

    ////////////////////////////////////////////////////////////////////////////////
    /// @brief Sort the range [first, last) of integral types into nondecreading
    ///        order
    /// @tparam RandomAccessIterator Random Access Iterator
    /// @param first Initial position of sequence to be sorted
    /// @param last Final position of sequence to be sorted
    ///
    /// Sorts with Radix sort. Should do radix on decimal representation of integer
    /// type, i.e., number of buckets is always 10.
    /// typename RandomAccessIterator::value_type is required to be some integral
    /// type, i.e., char, short, int, long, etc.
    template<class RandomAccessIterator>
        void radix_sort(RandomAccessIterator first, RandomAccessIterator last) {
            /// @bonus Implement radix_sort
        }

}

#endif
