// Vinayak Mani,Roll no -202132
// program to simulate the various searching and sorting
// algorithms and compare their timings of a list of 1000
// elements

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
void Linear_search(int Arr[],int n,int x){
    clock_t start = clock();
    int flag = 1;
    for(int i=0;i<n;i++){
        if(Arr[i]==x){
            cout<<"Element is found at :  "<<i;
            cout<<endl;
            flag=0;
            break;
        }
    }
    if(flag == 1){
        cout<<"Element is not found";
    }
    cout<<fixed<<"\nExecution time of linear search: "<<float(clock()-start)/CLOCKS_PER_SEC<<endl;
}
void Binary_search(int Arr[],int left,int right,int x){
    clock_t start = clock();
    int  flag = 1;
    while(left<=right){
        int mid = left+((right-left)/2);
        if(Arr[mid]==x){
            cout<<"Element is found at: "<<mid;
            flag=0;
            break;
        }
        if(Arr[mid]<x)
            left=mid+1;
        else
            right=mid-1;
    }
    if(flag==1)
        cout<<"Element not present";
    cout<<fixed<<"\nExecution time of Binary Search: "<<float(clock()-start)/CLOCKS_PER_SEC<<endl;
}
void Swap(int &x,int &y){
    int temp=x;
    x  =  y;
    y=temp;
}
void Bubble_sort(int Arr[],int n){
    clock_t start=clock();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<(n-i-1);j++){
            if(Arr[j]>Arr[j+1]){
                swap(Arr[j],Arr[j+1]);
            }
        }
    }
    cout<<fixed<<"\nExcution time of Bubble Sort: "<<float(clock()-start)/CLOCKS_PER_SEC<<endl;
}
int partition(int Arr[],int low,int high){
    int pivot=Arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(Arr[j]<pivot){
            i++;
            swap(Arr[i],Arr[j]);
        }
    }
    swap(Arr[i+1],Arr[high]);
    return i+1;
}
void Quick_Sort(int Arr[],int low,int high){
    if(low<high){
        int pi=partition(Arr,low,high);
        Quick_Sort(Arr,low,pi-1);
        Quick_Sort(Arr,pi+1,high);
    }
}
void Print_Ar(int Arr[],int size){
    for(int i=0;i<size;i++)
        cout<<Arr[i]<<" ";
    cout<<endl;
}
int main(){
    int Ar[1000],new_Ar[1000],element;
    for(int i=0;i<1000;i++){
        Ar[i]=rand()%1000;
    }
    for(int i=0;i<1000;i++){
        new_Ar[i]=Ar[i];
    }
    cout<<"The Array is : "<<endl;
    Print_Ar(Ar,1000);
    cout<<"Enter a Element to search: ";
    cin>>element;
    Linear_search(Ar,1000,element);
    Bubble_sort(Ar,1000);
    Print_Ar(Ar,1000);
    Binary_search(Ar,0,999,element);

    clock_t start=clock();
    Quick_Sort(new_Ar,0,999);
    cout<<fixed<<"\nExecution Time of Quick Sort: "<<float(clock()-start)/CLOCKS_PER_SEC<<endl;
    Print_Ar(new_Ar,1000);
return 0;
}