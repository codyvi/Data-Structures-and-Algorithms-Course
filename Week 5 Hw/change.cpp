#include<iostream> 
#include <limits.h>
#include<algorithm> 

using namespace std;

int get_change(int n) 
{
  //write your code here
	int arr[] = {1,3,4}; //Array of coins that can be used 
	int m = sizeof(arr)/sizeof(arr[0]); //Length of the array 


    int table[n+1]; 

    table[0]=0;
  
    for(int i=1; i<=n; i++) 
    {
        table[i] = INT_MAX;
        //cout << table[i] << endl;
        for(int j=0; j < m; j++) 
        {
            if(i >= arr[j])
            {
                int NumCoins = table[i-arr[j]]+1;
                if(NumCoins < table[i])
                {
                    table[i] = NumCoins;
                }
            }
        }
    }
  
    return table[n]; 
} 


int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
