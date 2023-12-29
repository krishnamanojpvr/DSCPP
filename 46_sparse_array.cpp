#include<iostream>
using namespace std;
int main()
{
    int arr[3][3]={{1,0,0},{2,0,1},{1,0,1}};
    int count=0;
    int k =0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (arr[i][j]!=0)
                count++;
        }
    }
    int arr1[3][count];
    for (int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if (arr[i][j]!=0){
                arr1[0][k]=i;
                arr1[1][k]=j;
                arr1[2][k]=arr[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<3;i++){
        for (int j=0;j<count;j++){
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}