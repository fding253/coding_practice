//
//  BubbleSort.cpp
//  
//
//  Created by Fiona Ding on 3/30/15.
//
//

#include "BubbleSort.h"

int main() {
    
    int array[] = { 5, 3, 4, 1, 2 };
    int size = 5;
    
    std::cout << "Array before sorting:" << std::endl;
    for(int i=0; i<size; i++)
        std::cout << array[i] << ",";
    
    std::cout << std::endl;
    
    BubbleSort(array, size);
    
    std::cout <<" Array after sorting:" << std::endl;
    for(int i=0; i<size; i++)
        std::cout << array[i] << ",";
    std::cout << std::endl;
    
    return 0;
    
}

void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void BubbleSort(int array[], int size) {
    
    for(int highestUnsorted = size - 1; highestUnsorted > 0; highestUnsorted--) {
        for(int highestSoFar = 0; highestSoFar < highestUnsorted; highestSoFar++) {
            if(array[highestSoFar]>array[highestSoFar+1]) {
                swap(array,highestSoFar,highestSoFar+1);
            }
        }
    }

}
