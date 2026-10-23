#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int partitions(int arr[], int si, int ei) {

    int pivotIndex = (si + ei) / 2;
    int pe = arr[pivotIndex];

    int count = 0;
    for (int i = si; i <= ei; i++) {
        if (i == pivotIndex)
            continue;

        if (arr[i] <= pe)
            count++;
    }
    int pi = si + count;
    swap(arr[pivotIndex], arr[pi]);

    int i = si;
    int j = ei;
    while (i < pi && j > pi) {

        if (arr[i] <= pe) {
            i++;
        }
        else if (arr[j] > pe) {
            j--;
        }
        else {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pi;
}

void quicksort(int arr[], int si, int ei) {
    if (si >= ei)
        return;
    int pi = partitions(arr, si, ei);
    quicksort(arr, si, pi - 1);
    quicksort(arr, pi + 1, ei);
}
int kthsmallest(int arr[],int si,int ei,int k){
    int pi = partitions(arr,si,ei);
    if(pi+1==k) return arr[pi];
    else if(pi+1<k) return kthsmallest(arr,pi+1,ei,k);
    else return kthsmallest(arr,si,pi-1,k);
}
int main() {

    int arr[] = {5, 9, 11, 89, 7, 6, 3, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    // quicksort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int k=4;
    cout<<kthsmallest(arr,0,n-1,k);
}