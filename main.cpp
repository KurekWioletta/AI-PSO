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
    for (int i = 0; i < 2000; i++) 
        swarm.optimize();

    /* output for our example, where dimension of vector equals 2 */
    cout << "f(x,y) = " << swarm.getBestValue() << endl;
    cout << "(x,y) = (" << swarm.getBestPos()[0] << "," << swarm.getBestPos()[1] << ")" << endl; 

    return 0;
}