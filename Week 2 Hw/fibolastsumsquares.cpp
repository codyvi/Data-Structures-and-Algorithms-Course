#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

long long getFibonacciLastDigit(long long n)
{
    if (n <= 1)
    {
        return n;
    }

    int prev = 0;
    int curr = 1;
    for(long long i = 2; i <= n; i++)
    {
        int next = (prev+curr) %10;
        prev = curr;
        curr = next;
    }
    return curr % 10;
}

long long getFibonacciSquareSum(long long n)
{
    int verticalSide = getFibonacciLastDigit( n % 60);
    int horizontalSide = getFibonacciLastDigit((n + 1) % 60);
    int sumSquares = verticalSide * horizontalSide;
    return sumSquares % 10;
}


int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << getFibonacciSquareSum(n);
}
