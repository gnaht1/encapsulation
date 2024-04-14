/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
if
switch
###End banned keyword*/
#include <iostream>
#include <vector>
using namespace std;
class vector_2d{
private:
    long x, y;
public:
    void output(){
        cout << "(" << x << ", "  << y<< ")";
    }
//###INSERT CODE HERE -
    void input() {
        cin >> x >> y;
    }

    long long length() {
        return x*x + y*y;
    }
};

int main () {
    int n;
    cin >> n;
    vector<vector_2d> Array(n);
    for(int i = 0; i < n; i++){
        Array[i].input();
    }

    vector_2d longest = Array[0];

    for(int i = 1; i < n; i++){
        if (longest.length() < Array[i].length()) longest = Array[i];
    }

    longest.output();
}
