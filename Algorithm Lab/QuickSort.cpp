#include <bits/stdc++.h>
using namespace std;


int partition(int a[],int l, int h)
{

      int i = l - 1;
      int pivot = a[h];

      for (int j = l; j < h; j++)
      {

            if (a[j] <= pivot)
            {
                  i++;
                  swap(a[i], a[j]);
            }
      }

      i++;
      swap(a[i], a[h]);
      
      return i;
}

void quickSort(int a[],int l, int h, int n)
{

      if (h <= l)
            return;

      int p = partition(a,l, h);

      quickSort(a,l, p - 1,n);

      quickSort(a,p + 1, h,n);

      for (int i = 0; i < n; i++)
       cout << a[i] << " ";
      cout << endl;

}

int main()
{
      
int n;
      cout << "Enter the array size:\n";
  cin >> n;
  int a[n];
  cout << "Enter array elements: \n";

      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
      }

      for (int i = 0; i < n; i++)
            cout << a[i] << " ";
      cout << endl;

      quickSort(a,0, n - 1, n);

      cout << "Sorted array\n";

      for (int i = 0; i < n; i++)
            cout << a[i] << " ";
      cout << endl;
}