//
//  Merge Sorted Array: LeetCode #88
//
//  4/12/15
//  ** Finished 4/15/2015. 

#include <stdio.h>
#include <iostream>
#include <string>

class MergeSortedArrays {
    public:
        void merge(int A[], int m, int B[], int n) {
            int AIndex = m-1;
            int BIndex = n-1;
            int mergedIndex = m+n-1;
            
            if (n==0) {
                return; //B is empty, A already "merged"
            }
            if (m==0) { //A is empty, copy B into A
                for (int i=0; i<n; i++) {
                    A[i] = B[i]; //
                }
                return;
            }

            // Start from last ( (m+n)th element ) and merge until first
            while (AIndex>=0 && BIndex>=0) {
                if (A[AIndex] >= B[BIndex]) {
                    A[mergedIndex] = A[AIndex];
                    mergedIndex--;
                    AIndex--;
                } else if (A[AIndex] < B[BIndex]) {
                    A[mergedIndex] = B[BIndex];
                    mergedIndex--;
                    BIndex--;
                } /*else if (A[AIndex] == B[BIndex]) {
                    A[mergedIndex] = A[AIndex];
                    A[mergedIndex-1] = A[AIndex];
                    mergedIndex=mergedIndex-2;
                    AIndex--;
                    BIndex--;
                } */
            }

            // If at beginning of B, done. If at beginning of A, copy over rest of B. 
            if (AIndex < 0) {
                while (mergedIndex>=0) {
                    A[mergedIndex] = B[BIndex];
                    mergedIndex--;
                    BIndex--;
                }
            }

            return;
        }

};

int main() {
    int m,n;

    m=5;
    n=6;
    
    int A[11] = {1,3,5,7,9};
    int B[6] = {2,4,6,8,10,12};

    MergeSortedArrays msa;

    // Print out original arrays
    std::cout << "A[]: " ;
    for (int a=0; a<m; a++) {
        std::cout << A[a] << " ";
    }
    std::cout << std::endl;

    std::cout << "B[]: " ;
    for (int b=0; b<n; b++) {
        std::cout << B[b] << " ";
    }
    std::cout << std::endl;

    msa.merge(A,m,B,n);
    
    // Print out merged array
    std::cout << "Merged array: " << std::endl;
    for (int i=0; i<m+n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

}
