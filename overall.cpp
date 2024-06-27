Sorting

    SELECTION SORT--->
    // int a range( i > n ) selection minimum value and relplace it with i index
    // tc -- n2
    // sc -- 1
    for (int i = 0; i < n; i++)
{
    int mini = i;
    for (int j = i; j < n; j++)
    {
        if (arr[j] < arr[mini])
        {
            mini = j;
        }
    }
    swap(arr[i], mini);
}

BUBLE SORT--->
    // move the max element towards right of array by each swapping
    // tc -- n2
    // sc -- 1
    for (int i = n - 2; i >= 0; i--)
{
    for (int j = 0; j <= i; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
    }
}

INSERTION SORT--->
    // take the element and move it towards it corect position
    // tc -- n2
    // sc -- 1

    for (int i = 0; i < n; i++)
{
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        swap(arr[j], arr[j - 1]);
        j--;
    }
}

MERGE SORT--->
// divide and conqueur concept 
//  use recursion 
// tc --> nlogn 
// sc --> n 
void merge(vector<int> &nums, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left]);
            left++;
        }
        else
        {
            temp.push_back(nums[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
}
void mergesort(vector<int> &nums, int low, int high)
{
    if (low >= high)return;
    int mid = (low + high) / 2;
    mergesort(nums, low, mid);
    mergesort(nums, mid + 1, high);
    merge(nums, low, mid, high);
}
vector<int> sortArray(vector<int> &nums)
{
    mergesort(nums, 0, nums.size() - 1);
    return nums;
};


OUICK SORT
// divide and conquer 
// tc --  nlog n  
// sc -- 1 

int partion ( int arr , int low  , int high){

    int pivot  = arr[low];
    int i = low ;
    int j = high;
    while (i<j )
    {
        while( arr[i] <= pivot && i<= high -1){ // imp  <=  and high sa picha 
            i++;
        }
        while( arr[j] > pivot && j >= low +1){  // imp > and low sa aga ;
            j-- ; 
        }
        if( i< j )swap( arr[i] , arr[j ]);
    }
    swap(arr[low] , arr[j]);
    return j ;
    
}

void quick( int arr [ ] , int low , int high){
    if( low >= high)return ;
    int partionIND  = partition ( arr[] , low  , high);
    quick( arr , low  , partionIND - 1);
    quick ( arr , partion+1 , high);
}