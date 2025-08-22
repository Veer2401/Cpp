#include <iostream>
using namespace std;

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[],int n){
    cout << "Running Selection sort \n";

    for(int i=0;i<n-1;i++){
        int indexOfMin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[indexOfMin]){
                indexOfMin = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp;
    }
}

int main(){
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: " << endl;
    for(int i=0;i<n;i++){
        cout << i + 1 << ": ";
        cin >> arr[i];
    }

    print(arr,n);
    cout << "\n";

    selectionSort(arr,n);

    cout << "The sorted array is: " << endl;
    print(arr,n);

    return 0;

}