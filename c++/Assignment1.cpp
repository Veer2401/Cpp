#include <iostream>
using namespace std;

void bubbleSort(int arr[],int n){

    cout << "Running Bubble sort " << endl;

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


void insertionSort(int arr[],int n){

    cout << "Running Insertion sort " << endl;

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

void selectionSort(int arr[],int n){
    cout << "Running Selection sort " << endl;

    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int partition(int arr[],int low,int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do{
        while(i <= high && arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while(i < j);

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[],int low,int high){
    int partitionIndex;

    if(low < high){
        partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex - 1);
        quickSort(arr,partitionIndex+1,high);
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    int n,choice;

    cout << "-------------AVAILABLE SORTING ALGORITHMS--------------- " << endl;
    cout << " 1. Bubble Sort " << endl;
    cout << " 2. Insertion Sort " << endl;
    cout << " 3. Selection Sort " << endl;
    cout << " 4. Quick Sort " << endl;

    cout << "Enter your choice (1-4) ";
    cin >> choice;

    cout << "Enter number of terms: ";
    cin >> n;

    if(n<=0){
        cout << "Invalid input!";
        return 0;
    }

    int arr[n];

    cout << "Enter elements: " << endl;
    for(int i=0;i<n;i++){
        cout << i + 1 << ": ";
        cin >> arr[i];
    }

    switch(choice){
        case 1:
            bubbleSort(arr,n);
            cout << "Sorted Array: ";
            print(arr,n);
            break;

        case 2:
            insertionSort(arr,n);
            cout << "Sorted Array: ";
            print(arr,n);
            break;

        case 3:
            selectionSort(arr,n);
            cout << "Sorted Array: ";
            print(arr,n);
            break;

        case 4:
            cout << "Running Quick sort " << endl;
            quickSort(arr,0,n-1);
            cout << "Sorted Array: ";
            print(arr,n);
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;

}
