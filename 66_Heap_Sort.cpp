#include<iostream>
using namespace std;
void maxHeapify(int arr[],int n, int i){
    int largest = i;
    int leftChild = 2*i + 1;
    int rightChild = 2*i + 2;
    if(leftChild<n && arr[leftChild]>arr[largest]){
        largest = leftChild;
    }
        if(rightChild<n && arr[rightChild]>arr[largest]){
        largest = rightChild;
    }
    if(largest!=i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        maxHeapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--){
        maxHeapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxHeapify(arr,i,0);
    }
}
int main()
{
    int arr[10] = {9,8,7,6,5,4,3,2,1,0};
    heapSort(arr,10);
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}