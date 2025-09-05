#include <iostream>
using namespace std;

int LinearSearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[],int size,int element){
    int low,mid,high;

    low = 0;
    high = size - 1;

    while(low<=high){
        mid = (low + high)/2;

        if(arr[mid] == element){
            return mid;
        }
        if(arr[mid] < element){
            low = mid+1;
        } else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){ 

    int arr[] = {3,4,5,6,7,8,9,10,11,24,31};
    int size = sizeof(arr)/sizeof(int);
    int element;

    cout << "Enter the element you want to search for: ";
    cin >> element;
    int index = binarySearch(arr,size,element);

    cout << "The element " << element << " was found at index " << index;

    return 0;

}