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
    for(int i=0;i<arraySize;i++)
    {
        int temp=arr[i];
        int j=i-1;
        for(;j>=0;j--)
        {
            if(arr[j]>temp)
            arr[j+1]=arr[j];
            else
            break;
        }
        arr[j+1]=temp;
    }
    cout<<"\nDisplaying sorted array:"<<endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout<<arr[i]<<" ";
    }
}