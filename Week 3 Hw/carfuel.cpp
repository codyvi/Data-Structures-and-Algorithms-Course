#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

int compute_min_refills(int dist, int tank, int n,vector<int> & stops) 
{
    // write your code here
    int numRefills = 0; 
    int currentRefill = 0;
    int lastRefill = 0;
    while(currentRefill <= n-1)
    {
        lastRefill = currentRefill;
        while((currentRefill <= n) && (stops[currentRefill + 1] - stops[lastRefill] <= tank))
        {
            currentRefill++;

        }

        if(currentRefill == lastRefill)
        {
            return -1;
        }

        if(currentRefill <= n )
        {
            //cout << "Entre" << endl;
            numRefills++;
        }
    }

    return numRefills;
}


int main() 
{
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    stops.push_back(d);



    cout << compute_min_refills(d, m, n,stops) << "\n";

    return 0;
}
