#include <iostream>
using namespace std;


void merge(int a[], int l, int m, int r, int n) {
  
  
  int n1 = m - l + 1;
  int n2 = r - m;

  int left[n1], right[n2];

  for (int i = 0; i < n1; i++)
    left[i] = a[l + i];
  for (int i = 0; i < n2; i++)
    right[i] = a[m + 1 + i];

  int i, j, k;
  i = 0;
  j = 0;
  k = l;


  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      a[k] = left[i];
      i++;
    } else {
      a[k] = right[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    a[k] = left[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = right[j];
    j++;
    k++;
  }

  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
}


void mergeSort(int a[], int l, int r, int n) {
  if (l < r) {
    int m = l + (r - l) / 2;

    mergeSort(a, l, m, n);
    mergeSort(a, m + 1, r, n);

    merge(a, l, m, r, n);
  }

}




int main() {
int n;
cout << "Enter the array size:\n";
  cin >> n;
  int a[n];
  cout << "Enter array elements: \n";
  for (int i = 0; i < n; i++)
  {
      cin>> a[i];
  }

   for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  

  mergeSort(a, 0, n - 1,n);

  cout << "Sorted array: \n";
  for (int i = 0; i < n; i++)
    cout << a[i] << " ";
  cout << endl;
  return 0;
}