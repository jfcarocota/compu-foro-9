class Quicksort
{
private:
    const static void Partition(int[], int, int, int&, int&); 
public:
    const static void Sorting(int[], int, int);
    Quicksort(/* args */);
    ~Quicksort();
};

Quicksort::Quicksort()
{
}

Quicksort::~Quicksort()
{
}


//Dutch National Flag Algorithm 
const void Quicksort::Partition(int a[], int low, int high, int &i, int &j) 
{ 
    if (high - low <= 1) 
    { 
        if (a[high] < a[low]) 
            std::swap(a[high], a[low]); 
        i = low; 
        j = high; 
        return; 
    } 
  
    int mid = low; 
    int pivot = a[high]; 
    while (mid <= high) 
    { 
        if (a[mid]<pivot) 
            std::swap(a[low++], a[mid++]); 
        else if (a[mid]==pivot) 
            mid++; 
        else if (a[mid]>pivot) 
            std::swap(a[mid], a[high--]); 
    } 
  
    //update i and j 
    i = low-1; 
    j = mid; //or high-1 
} 
  
const void Quicksort::Sorting(int a[], int low, int high) 
{ 
    if (low>=high) 
        return; 
  
    int i, j; 
  
    Quicksort::Partition(a, low, high, i, j); 
  
    Quicksort::Sorting(a, low, i); 
    Quicksort::Sorting(a, j, high); 
} 