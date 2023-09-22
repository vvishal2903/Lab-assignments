#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int arr[]={64,25,12,22,11};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    cout<<"displaying original array:"<<endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout<<arr[i]<<" ";
    }
    //sorting the array using selection sort
    for(int i=0;i<arraySize-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<arraySize;j++)
        {
            if(arr[j]<arr[minIndex])
            minIndex=j;
        }
        swap(arr[minIndex],arr[i]);
    }
    cout<<"\nDisplaying sorted array:"<<endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout<<arr[i]<<" ";
    }
}