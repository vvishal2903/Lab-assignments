/* how far an element is from its sorted version
    
*/
#include<iostream>
using namespace std;

int main(){
    int inv=0;
    int arr[]={3,2,4,1,5};
    int size=sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; i++)
    {
        for (int j=i+1; j < size; j++)
        {
            if(arr[i]>arr[j])
            {
                inv++;
            }
        }
    }
    cout<<"Number of inversions="<<inv<<endl;
    return 0;
}