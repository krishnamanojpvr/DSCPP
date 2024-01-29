#include<iostream>
using namespace std;
void merge(int arr[], int lb, int mid , int ub){
    int brr[ub+1];
    int i = lb;
    int j = mid+1;
    int k = lb;
    while(i<=mid && j<=ub){
        if(arr[i]<=arr[j]){
            brr[k]=arr[i];
            i++;
            k++;
        }
        else{
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i>mid){
        while(j<=ub){
            brr[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
        while(i<=mid){
        brr[k]=arr[i];
        i++;
        k++;
        }
    }
    for(k=lb;k<=ub;k++){
        arr[k]=brr[k];
    }
}
void mergeSort(int arr[],int lb,int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);
        merge(arr,lb,mid,ub);
    }
}
int main()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
    
}