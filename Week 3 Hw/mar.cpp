#include <algorithm>
#include <iostream>
#include <vector>
#include <complex>

using std::vector;

bool compare(int a, int b)
{
    return a > b;
}

long long max_dot_product(vector<int> a, vector<int> b, size_t n) {
  // write your code here
  long long result = 0;
  size_t x, y, i = 0, min, max;
  while(a[i] > 0 && b[i] > 0)
  {
      result = result + ((long long)a[i]) * b[i];
      i++;
  }
  x = i;
  
  i = n - 1;
  
  while(a[i] < 0 && b[i] < 0)
  {
      result = result + ((long long)a[i]) * b[i];
      i--;
  }
  y = i;
  
  if(x != (y+1))
  {
      if(x > y)
      {
        min  = y;
        max = x;
      }
      else
      {
        min  = x;
        max = y;
      }
  
      for(i = min; i <=  max; i++)
      {
        result = result + ((long long)a[i]) * b[i];
      }
  }
  
  
  return result;
}

int main() {
  size_t n;
  int input;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  std::sort(a.begin(),a.end(),compare);
  std::sort(b.begin(),b.end(),compare);
  
  
  std::cout << max_dot_product(a, b, n) << std::endl;
}