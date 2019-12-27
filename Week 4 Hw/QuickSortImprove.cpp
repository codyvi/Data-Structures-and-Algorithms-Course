#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

void partition3(vector<int> &a, int l, int r, int tmp[])
{
    int x = a[l];
    tmp[0] = l;
    tmp[1] = l;

    for(int i = l+1; i <= r; i++)
    {
        if(a[i] < x)
        {
            tmp[0]++;
            tmp[1]++;
            swap(a[tmp[0]], a[tmp[1]]);
            if(tmp[1] != i)
            {
                swap(a[tmp[0]], a[i]);
            }
        }
        else if (a[i] == x)
        { 
            tmp[1]++;
            swap(a[tmp[1]], a[i]);
        }
    }

    swap(a[l], a[tmp[0]]);
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m[2] = { 0 };
  partition3(a,l,r,m);
  randomized_quick_sort(a, l, m[0] - 1);
  randomized_quick_sort(a, m[1] + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
