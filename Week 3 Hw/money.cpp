#include <iostream>

using namespace std;

int get_change(int m) {
  //write your code here
  int n = 0;
  int tmp = m;

  while(tmp != 0)
  {
      if(tmp >= 10)
      {
          tmp -= 10;
          n++;
      }

      else if(tmp >= 5)
      {
          tmp -= 5;
          n++;
      }

      else
      {
          tmp--;
          n++;
      }
  }

  return n;
}

int main() {
  int m;
  cout << "Give me the n: ";
  cin >> m;
  cout << get_change(m) << '\n';
}
