#include <iostream>
using namespace std;

void InsertionSort(int arr[],int n){
    for(int i=0;i<=n-1;i++){
        int k = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j]>k){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = k;
    }
}