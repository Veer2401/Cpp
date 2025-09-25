#include <iostream>
using namespace std;

int linearSearch(int arr[],int size,int element){
    for(int i=0;i<size;i++){
        if(arr[i] == element){
            cout << "Linear Search: The element " << element << " was found out at index " << i << endl;
            return i;
        }
    }
    cout << "The element was not found in the array!" << endl;
    return -1;
}

void bubbleSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

int binarySearch(int arr[],int size,int element){
    int low=0,mid,high=size-1;

    while(low<=high){
        mid = (low+high)/2;
        if(arr[mid] == element ){
            return mid;
        }
        else if(arr[mid] < element){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    int size,element;

    cout << "Enter the size of Array: ";
    cin >> size;

    int arr[size];

    cout << "Enter elements: " << endl;
    for(int i=0;i<size;i++){
        cout << i+1 << ": ";
        cin >> arr[i];
    }

    cout << "Enter the element you want to search for: ";
    cin >> element;

    linearSearch(arr,size,element);

    bubbleSort(arr,size);

    cout << "Sorted array: " << endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int index = binarySearch(arr,size,element);

    if(index != -1){
        cout << "Binary Search: The element " << element << " was found out at index " << index << endl;

    }
    else{
        cout << "The element was not found!" << endl;
    }

    return 0;
}

