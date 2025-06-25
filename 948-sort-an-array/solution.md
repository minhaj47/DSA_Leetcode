# Intuition
The problem requires sorting an array, and multiple sorting algorithms can be applied. Each algorithm has different trade-offs in terms of time complexity, space usage, and performance characteristics. The implementation demonstrates five classic sorting algorithms: Selection Sort, Bubble Sort, Insertion Sort, Merge Sort, and Quick Sort, with Quick Sort being the active choice.

# Approach
The code implements multiple sorting algorithms, each with distinct strategies:

## 1. Selection Sort
- **Strategy**: Find the minimum element in unsorted portion and swap with first unsorted element
- **Process**: For each position, scan remaining array to find minimum
- **Characteristics**: Always makes exactly n-1 swaps, regardless of input

## 2. Bubble Sort  
- **Strategy**: Repeatedly swap adjacent elements if they're in wrong order
- **Process**: Multiple passes through array, "bubbling" largest elements to end
- **Characteristics**: Can terminate early if no swaps occur (optimized version)

## 3. Insertion Sort
- **Strategy**: Build sorted portion one element at a time by inserting each element in correct position
- **Process**: Take each element and shift it left until proper position found
- **Characteristics**: Efficient for small arrays and nearly sorted data

## 4. Merge Sort
- **Strategy**: Divide array into halves, recursively sort, then merge sorted halves
- **Process**: Split until single elements, then combine in sorted order
- **Characteristics**: Stable, consistent performance, requires extra space

## 5. Quick Sort (Active Implementation)
- **Strategy**: Choose pivot, partition array around pivot, recursively sort partitions
- **Process**: Partition using two pointers, place pivot in final position
- **Characteristics**: In-place, cache-friendly, but worst-case can be poor

# Complexity Analysis

## Time Complexity Comparison

| Algorithm | Best Case | Average Case | Worst Case | Notes |
|-----------|-----------|--------------|------------|-------|
| **Selection Sort** | $$O(n^2)$$ | $$O(n^2)$$ | $$O(n^2)$$ | Always quadratic |
| **Bubble Sort** | $$O(n)$$ | $$O(n^2)$$ | $$O(n^2)$$ | Best when already sorted |
| **Insertion Sort** | $$O(n)$$ | $$O(n^2)$$ | $$O(n^2)$$ | Excellent for small/nearly sorted |
| **Merge Sort** | $$O(n \log n)$$ | $$O(n \log n)$$ | $$O(n \log n)$$ | Consistent performance |
| **Quick Sort** | $$O(n \log n)$$ | $$O(n \log n)$$ | $$O(n^2)$$ | Typically fastest in practice |

## Space Complexity Comparison

| Algorithm | Space Complexity | Type | Notes |
|-----------|------------------|------|-------|
| **Selection Sort** | $$O(1)$$ | In-place | Only uses temp variables |
| **Bubble Sort** | $$O(1)$$ | In-place | Only uses temp variables |
| **Insertion Sort** | $$O(1)$$ | In-place | Only uses temp variables |
| **Merge Sort** | $$O(n)$$ | Out-of-place | Requires temporary arrays |
| **Quick Sort** | $$O(\log n)$$ avg, $$O(n)$$ worst | In-place | Recursion stack space |

# Algorithm Characteristics

## Stability
- **Stable**: Merge Sort, Bubble Sort, Insertion Sort
- **Unstable**: Selection Sort, Quick Sort (as implemented)

## Adaptive (performs better on partially sorted data)
- **Adaptive**: Bubble Sort, Insertion Sort
- **Non-adaptive**: Selection Sort, Merge Sort, Quick Sort

## When to Use Each Algorithm

### Selection Sort
- **Use when**: Memory writes are expensive, small datasets
- **Avoid when**: Performance matters, large datasets

### Bubble Sort  
- **Use when**: Educational purposes, detecting if array is sorted
- **Avoid when**: Any production code (generally inefficient)

### Insertion Sort
- **Use when**: Small arrays (≤50 elements), nearly sorted data, as subroutine in hybrid algorithms
- **Avoid when**: Large random datasets

### Merge Sort
- **Use when**: Stability required, predictable performance needed, external sorting
- **Avoid when**: Memory is limited, small datasets

### Quick Sort
- **Use when**: General-purpose sorting, memory is limited, cache performance matters
- **Avoid when**: Stability required, worst-case performance is critical

# Code

```cpp
class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int n = nums.size();

            // SELECTION SORT - O(n²) always
            // Finds minimum in unsorted portion, swaps to front
            /*
            for(int unsortedFirst = 0; unsortedFirst<n; unsortedFirst++){
                int minIndex = unsortedFirst;
                for(int i=unsortedFirst+1; i < n; i++){
                    if(nums[minIndex] > nums[i]){
                        minIndex = i;
                    } 
                }
                swap(nums[unsortedFirst], nums[minIndex]);
            }
            */

            // BUBBLE SORT - O(n²) worst/avg, O(n) best
            // Repeatedly swaps adjacent out-of-order elements
            /*
            for(int i=0; i<n; i++ ){
                for(int j=0; j<n-i-1; j++){
                    if(nums[j] > nums[j+1])swap(nums[j], nums[j+1]);
                }
            }
            */

            // INSERTION SORT - O(n²) worst/avg, O(n) best  
            // Builds sorted array one element at a time
            /*
            for(int unsorted=0; unsorted<n; unsorted++){
                for(int i=unsorted-1; i>0; i--){
                    if(nums[i]<nums[i-1])swap(nums[i], nums[i-1]);
                }
            }
            */

            // MERGE SORT - O(n log n) always, O(n) space
            // Divide and conquer with guaranteed performance
            // mergesort(nums, 0, n-1);

            // QUICK SORT - O(n log n) avg, O(n²) worst, O(log n) space avg
            // In-place partitioning around pivot
            quicksort(nums, 0, n-1);

            return nums;
        }

        // Quick Sort Implementation
        int partition(vector<int>&arr, int low, int high){
            int pivot = arr[low];
            int i = low, j = high;
            
            while(i<j){
                while(arr[i] <= pivot && i<high) i++;
                while(arr[j] > pivot && j>low) j--;
                if(i<j) swap(arr[i], arr[j]);
            }

            swap(arr[j], arr[low]);
            return j;
        }

        void quicksort(vector<int>&arr, int low, int high){
            if(low>=high) return;
            
            int pIndex = partition(arr, low, high);
            quicksort(arr, low, pIndex-1);
            quicksort(arr, pIndex+1, high);
        }

        // Merge Sort Implementation  
        void mergesort(vector<int>&arr, int low, int high){
            if(low>=high) return;
            
            int mid = (low+high)/2;
            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }

        void merge(vector<int>&arr, int low, int mid, int high){
            int i = low, j = mid+1;
            vector<int>temp;

            while(i<=mid && j<=high){
                if(arr[i]<=arr[j]){
                    temp.push_back(arr[i++]);
                } else {
                    temp.push_back(arr[j++]);
                }
            }

            while(i<=mid) temp.push_back(arr[i++]);
            while(j<=high) temp.push_back(arr[j++]);

            for(int k=low; k<=high; k++){
                arr[k] = temp[k-low];
            }
        }
};
```

## Performance Summary
Your implementation showcases the evolution of sorting algorithms from simple O(n²) methods to sophisticated O(n log n) algorithms. Quick Sort is chosen as the active implementation due to its excellent average-case performance and in-place nature, making it ideal for most practical applications despite its O(n²) worst case.
