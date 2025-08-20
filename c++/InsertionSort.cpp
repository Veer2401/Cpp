#include <iostream>
using namespace std;

void insert(int arr[],int n){
    for(int i=1;i<=n-1;i++){
        int k = arr[i];
        int j = i-1;
        
        while(j>=0 && arr[j]>k){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = k;
    }
}

void print(int arr[], int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n;
    
    cout << "Enter the number of elements: " << endl;
    cin >> n;
    
    int arr[n];
    
    cout << "Enter the elements: " << endl;
    for(int i=0;i<n;i++){
        cout << "Element [" << i << "]: ";
        cin >> arr[i];
    }
    
    cout << "Array before sorting:" << endl;
    print(arr,n);
    
    insert(arr,n);
    
    cout << "\n";
    
    
    cout << "Sorted array: " << endl;
    print(arr,n);
    
    return 0;
}