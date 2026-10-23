#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int c = 0;

void merge(vector<int>& a, vector<int>& b, vector<int>& res) {
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] < b[j]) {
            res[k++] = a[i++];
        }
        else {
            res[k++] = b[j++];
        }
    }

    if(i == a.size()) {
        while(j < b.size()) {
            res[k++] = b[j++];
        }
    }

    if(j == b.size()) {
        while(i < a.size()) {
            res[k++] = a[i++];
        }
    }
}

int inversion(vector<int>& a, vector<int>& b) {
    int i = 0;
    int j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] > b[j]) {
            c += (a.size() - i);   // corrected
            j++;
        }
        else {
            i++;
        }
    }

    return c;
}

void mergesort(vector<int>& v) {
    int n = v.size();

    if(n <= 1) return;

    int n1 = n / 2;
    int n2 = n - n / 2;

    vector<int> a(n1), b(n2);

    for(int i = 0; i < n1; i++) {
        a[i] = v[i];
    }

    for(int i = 0; i < n2; i++) {
        b[i] = v[i + n1];
    }

    mergesort(a);
    mergesort(b);

    // count inversions
    inversion(a, b);

    merge(a, b, v);
}

int main() {

    int arr[] = {5, 1, 3, 0, 4, 2, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> v(arr, arr + n);

    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << endl;

    mergesort(v);

    cout << "Inversion count = " << c;

    return 0;
}

































// int main() {

//     int arr[] = {5, 1, 3, 0, 4,9, 6};

//     int n = sizeof(arr) / sizeof(arr[0]);

//     vector<int> v(arr, arr + n);
//     for(int i = 0; i < v.size(); i++) {
//         cout << v[i] << " ";
//     }
//     int count=0;
//     cout << endl;
//     for(int i=0;i<n-1;i++){
//         for(int j=i+1;j<n;j++){
//             if(v[i]>v[j]){
//                 count++;
//             }
//         }
//     }
//     cout<<count;
// }