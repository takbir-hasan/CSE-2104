#include<bits/stdc++.h>
using namespace std;

pair<int,int> MinMax(int a[], int l,int r){

            if( l==r)  return {a[l],a[r]};
            int m= (l+r)>>1;
           pair<int,int> x=  MinMax(a,l,m);
           pair<int,int> y= MinMax(a,m+1,r);
          
            return {min(x.first,y.first), max(x.second,y.second)};
}

int main(){
  int n;
 cout << "Enter the array size:\n";
  cin >> n;
  int a[n];
  cout << "Enter array elements: \n";
  for (int i = 0; i < n; i++)
  {
      cin>> a[i];
  }

if(n==1){
 cout << "Minimum: " << a[0] << endl;
 cout << "Maximum: " << a[0] << endl;
 return 0;
}
cout << "Minimum: " << MinMax(a,0,n-1).first << endl;
cout << "Maximum: " << MinMax(a,0,n-1).second << endl;

  return 0;
}