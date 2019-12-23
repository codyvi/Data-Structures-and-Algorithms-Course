#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int numRefills = 0, currentRefills = 0;
    int lastRefills = 0;
    int n = stops.size();
    if(dist - stops[n-1] > tank)
    {
      n++;
    }
    //cout << n << endl;
    //cout<<"Stops where you need to get refilling:";
    while(currentRefills <= n)
    {
        lastRefills = currentRefills;
        while((currentRefills <= n) && (stops[currentRefills + 1] - stops[lastRefills] <= tank))
        {
          currentRefills++;
        }
        //cout<<a[lastRefills]<<'\n';
        if(currentRefills == lastRefills)
        // This happens when gas station is far away that even full tank of fuel 
        // could not make up
            return -1;
        if(currentRefills <= n)
        {
          //cout << "Entre" << endl;
          numRefills++;
        }

    }
    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
