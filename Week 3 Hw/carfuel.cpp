#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

int compute_min_refills(int target, int startFuel,vector<int> & stations) 
{
    //Write your code here
    priority_queue<int> pq;
    int ret = 0, stationId = 0, range = startFuel;
    while (range < target) 
    {
        while (stationId < stations.size() && stations[stationId] <= range) 
        {
                pq.push(stations[stationId++]);
            }
            if (pq.empty()) 
                return -1;
            range += pq.top();
            pq.pop();
            ++ret;
        }
        return ret;
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



    cout << compute_min_refills(d, m,stops) << "\n";

    return 0;
}
