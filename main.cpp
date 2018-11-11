#include "swarm.hpp"
#include <iostream>

using namespace std;

int main(){
    vector<vector<int>> bounds = {{-10, 10}, {-10, 10}}; /* bounds: Xi c [a, b] */

    double c1, c2; /* acceleration factors */
    cout << "c1 factor (double): ";
    cin >> c1;
    cout << "c2 factor (double): ";
    cin >> c2;
    
    Swarm swarm = Swarm(30, c1, c2, 0.1, bounds);
    for (int i = 0; i < 2000; i++) {
        swarm.optimize();
    }
    cout << swarm.getBestValue();

    return 0;
}