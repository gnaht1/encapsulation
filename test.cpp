#include <iostream>
using namespace std;

class Fraction
{
private:
    int nominator, denominator;

public:
    double to_double()
    {
        return (double)nominator / denominator;
    }
};
int main()
{
    Fraction a;
    cout << a.to_double();
}