#include<iostream>
using namespace std;
void selection(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minidx=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[minidx]>arr[j])
            {
                minidx=j;
            }
        }
        swap(arr[i],arr[minidx]);
    }

}
int main()
{
    int n;
    cout<<"\nenter no of elements:";
    cin>>n;
    int arr[n];
    cout<<"\nenter array elements:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    selection(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}


