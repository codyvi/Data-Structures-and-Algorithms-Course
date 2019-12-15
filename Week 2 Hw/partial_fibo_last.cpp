#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}


long long sum_fib(long long from, long long to)
{
    
    long long f[60] = {0}; 
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i < 60; i++) 
        f[i] = (f[i - 1] + f[i - 2]); 
    
    from %= 60;
    to %= 60;

    if(to < from)
    {
        to +=60;
    }

    long long su = 0;
    for (long long j = from; j < to + 1; j++)
    {
        su += f[j%60];
    }

    return su % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << sum_fib(from, to) << '\n';
}
