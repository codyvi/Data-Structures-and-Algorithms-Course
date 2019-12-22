#include<iostream>
#include<vector>
#include<cmath>

using namespace std;


int get_digits(int n)
{
    int count = 0;
    while(n / 10 != 0)
    {
        count++;
        n = n / 10;
    }   
    return count;
}


int get_max(int a, int b)
{
    int count_a = get_digits(a);
    int count_b = get_digits(b);

    int temp_a = (a * (int)pow(10, count_b + 1)) + b;
    int temp_b = (b * (int)pow(10, count_a + 1)) + a;

    if(temp_a >= temp_b)
        return a;
    else
        return b;
}


void get_max_salary(int n, vector<int> numbers)
{
    int temp_n = n;
    int max_digit = -1;
    int temp_index = 0;
    while(temp_n != 0)
    {
        max_digit = numbers[0];
        temp_index = 0;
        for(int i = 1; i < n; i++)
        {
            max_digit = get_max(max_digit, numbers[i]);
            if(max_digit == numbers[i])
            {
                temp_index = i;
            }
        }
        numbers[temp_index] = 0;
        cout<<max_digit;
        temp_n--;
    }
}

int main()
{
    int n = 0;

    cin>>n;
    vector<int> numbers(n);
    for(int i = 0; i < n; i++)
        cin>>numbers[i];
    
    get_max_salary(n, numbers);
    //cout<<'\n';
    return 0;
}