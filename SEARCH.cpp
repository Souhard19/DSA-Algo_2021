#include<bits/stdc++.h>

using namespace std;

int binarySearch (vector<int> &arr, int num, int l, int r) {
     int temp = arr[(l+r)/2];
     if (l>=r) {
          if (num != temp)
               return -1;
     }
     if (num == temp) {
          return (l+r)/2;
     } else if (num > temp) {
          return binarySearch(arr, num, ((l+r)/2)+1, r);
     } else {
          return binarySearch(arr, num, l, ((l+r)/2)-1);
     }
}

int main(){
     vector<int> arr = {12, 34, 56, 78, 124, 345, 657, 999};
     // for (int i=0; i<1000; i++) {
     //      arr.push_back(100+i*23);
     // }
     int i;
     cin >> i;
     cout << binarySearch(arr, i, 0, arr.size()-1);
}