#include<iostream>
#include "Quicksort.hh"

  
int main() 
{ 
    int a[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4}; 

    int size = sizeof(a) / sizeof(int); 
  
    Quicksort::Sorting(a, 0, size - 1); 

    for (int i = 0; i < size; ++i) 
    {
        std::cout << a[i] << " ";
    }

    std::getchar();
    return 0; 
} 