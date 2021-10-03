#include<bits/stdc++.h>

using namespace std;

void selectionSort (vector<int> &arr) {
     int n = arr.size();
     for (int i = 0; i < n-1; i++)
     {
          int min_index = i;
          for (int j = i+1; j < n; j++)
          {
               if(arr[j] < arr[min_index]) min_index = j;
          }
          swap(arr[i], arr[min_index]);
     }

}

void bubbuleSort (vector<int> &arr) {
     int n = arr.size();
     int i = n-1;
     while (i>0){
          for (int j = 1; j <= i; j++){
               if(arr[j] < arr[j-1]){
                    swap(arr[j], arr[j-1]);
               }
          }
          i--;
     }
}

void insertionSort (vector<int> &arr) {
     int n = arr.size();
     for (int i = 1; i < n; i++){
          int current = arr[i];
          int j = i-1;
          while (arr[j] >= current && j>=0)
          {
               arr[j+1] = arr[j];
               j--;
          }
          arr[j+1] = current;
     }
}

void quickSort (vector<int> &arr, int l, int r) {
     if (l>=r) return;

     int i = l + 1, j = r;
     while (i<=j) {
          while (arr[i] <= arr[l])
               i++;
          while (arr[j] > arr[l])
               j--;
          
          if (i<j) swap (arr[i], arr[j]);
     }
     swap(arr[l], arr[j]);
     quickSort (arr, l, j-1);
     quickSort (arr, j+1, r);
}


void mergeArr (vector<int> &arr, int l, int r) {
     vector<int> b (r-l+10);
     int mid = ((l+r)/2)+1;
     int i=l, j=mid, k=l;

     while (i<mid && j<=r) {
          if(arr[i] < arr[j]) {
               b[k] = arr[i];
               i++; k++;
          } else {
               b[k] = arr[j];
               j++; k++;
          }
     }
     while (i<mid) {
          b[k] = arr[i];
          i++; k++;
     }
     while (j<=r) {
          b[k] = arr[j];
          j++; k++;
     }

     for (i=l; i<=r; i++) {
          arr[i] = b[i];
     }
}
void mergeSort (vector<int> &arr, int l, int r) {
     if (l==r) return;
     mergeSort(arr, l, (l+r)/2);
     mergeSort(arr, ((l+r)/2)+1, r);

     //MERGING
     mergeArr(arr, l, r);

     //////  NOT EXACTLY OPTIMISED WAY OF MERGING, BUT WORKS
     // for (int i=((l+r)/2)+1; i<=r; i++) {
     //      for (int j=i-1; j>=l; j--) {
     //           if (arr[j] > arr[j+1]) swap (arr[j], arr[j+1]);
     //           else break;
     //      }
     // }
}


int main(){
     
     int n;
     cin >> n;

     vector<int> arr(n);
     for (int i = 0; i < n; i++)
          cin >> arr[i];

     mergeSort(arr, 0, n-1);

     for (int i = 0; i < n; i++)
          cout << arr[i] << "   ";

return 0;
}