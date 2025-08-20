#include <iostream>
using namespace std;

void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[],int n){
    cout << "\nThe sorted array is: ";
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
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

    BubbleSort(arr,n);
    print(arr,n);

    return 0;

}