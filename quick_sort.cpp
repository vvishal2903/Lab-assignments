#include<iostream>
using namespace std;

void displayArray(int arr[],int arraySize)
{
    for(int i=0;i<arraySize;i++)
    cout<<arr[i]<<" ";
};

int partition(int arr[],int s,int e)
{
    int pivot=arr[s];
    int cnt=0;
    for(int i=s+1;i<=e;i++)
    {
        if(arr[i]<=pivot)
        cnt++;
    }
    int pivotIndex=s+cnt;
    swap(arr[pivotIndex],arr[s]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<pivot)
        i++;
        while (arr[j]>pivot)
        j--;
        if (i<pivotIndex && j>pivotIndex)
        {
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
};

void quickSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);
};

int main(){
    int arr[]={64,25,12,22,11};
    int arraySize = sizeof(arr) / sizeof(arr[0]);
    cout<<"printing original unsorted array: "<<endl;
    displayArray(arr,arraySize);
    quickSort(arr,0,arraySize-1);
    cout<<"\nDisplaying sorted array: "<<endl;
    displayArray(arr,arraySize);
}
