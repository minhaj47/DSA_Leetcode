class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {

            // sort(nums.begin(), nums.end());

    
            int n = nums.size();


                // selection sort 

            // for(int unsortedFirst = 0; unsortedFirst<n; unsortedFirst++){
            //     int minIndex = unsortedFirst;

            //     for(int i=unsortedFirst+1; i < n; i++){
            //         if(nums[minIndex] > nums[i]){
            //             minIndex = i;
            //         } 
            //     }
            //     swap(nums[unsortedFirst], nums[minIndex]);
            // }

                // bubble sort

            // for(int i=0; i<n; i++ ){
            //     for(int j=0; j<n-i-1; j++){
            //         if(nums[j] > nums[j+1])swap(nums[j], nums[j+1]);
            //     }
            // }

                // insertion sort

            // for(int unsorted=0; unsorted<n; unsorted++){
            //     for(int i=unsorted-1; i>0; i--){
            //         if(nums[i]<nums[i-1])swap(nums[i], nums[i-1]);
            //     }
            // }

                // merge sort
            
            // mergesort(nums, 0, n-1);

                // quick sort
            
            quicksort(nums, 0, n-1);

            return nums;
            
        }

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
            if(low>=high){
                return;
            }
            int pIndex = partition(arr, low, high);

            quicksort(arr, low, pIndex-1);
            quicksort(arr, pIndex+1, high);

        }

        void mergesort(vector<int>&arr, int low, int high){

            if(low>=high) return;
            int mid = (low+high)/2;

            mergesort(arr, low, mid);
            mergesort(arr, mid+1, high);
            merge(arr, low, mid, high);
        }

        void merge(vector<int>&arr, int low, int mid, int high){
            int i = low;
            int j = mid+1;
            vector<int>temp;

            while(i<=mid && j<=high){
                if(arr[i]<=arr[j]){
                    temp.push_back(arr[i]);
                    i++;
                } else {
                    temp.push_back(arr[j]);
                    j++;
                }
            }

            while(i<=mid){
                temp.push_back(arr[i]);
                i++;
            }
            while(j<=high){
                temp.push_back(arr[j]);
                j++;
            }

            for(int k=low; k<=high; k++){
                arr[k] = temp[k-low];
            }

        }


};