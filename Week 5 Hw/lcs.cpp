#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b, int t1, int t2) {
  //write your code here
  int DP[t1+1][t2+1]; 

   for (int i=0; i<=t1; i++) 
   { 
     for (int j=0; j<=t2; j++) 
     { 
       if (i == 0 || j == 0) DP[i][j] = 0; 
    
       else if (a[i-1] == b[j-1]) 
       {
         DP[i][j] = DP[i-1][j-1] + 1; 
       }
   
       else
       {
         DP[i][j] = ((DP[i-1][j] > DP[i][j-1]) ? DP[i-1][j] : DP[i][j-1]);
       } 
     } 
   } 
     
   return DP[t1][t2]; 
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b,n,m) << std::endl;
}
