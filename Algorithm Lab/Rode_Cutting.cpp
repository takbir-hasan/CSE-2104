#include <bits/stdc++.h>
using namespace std;



int cutRod(int price[], int index, int n, vector<vector<int> >& dp)
{
	if (index == 0) {
		return n * price[0];
	}

	if (dp[index][n] != -1)
		return dp[index][n];

      int rod_length = index + 1;

	if (rod_length > n)
	{
            dp[index][n] = cutRod(price, index - 1, n,dp);
            return dp[index][n];
      }

	else{
		dp[index][n]= max(cutRod(price, index - 1, n,dp), price[index]+ cutRod(price, index, n - rod_length,dp));
	      return dp[index][n];
       }

        
	
}

int main()
{
	int arr[] = { 2,3,4,7,6};
      int size= sizeof(arr)/sizeof(arr[0]);
      
	vector<vector<int> > dp(size,vector<int>(size + 1, -1));

	cout << "Maximum profit is: "<< cutRod(arr, size - 1, size, dp);

	return 0;
}
