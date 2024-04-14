/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;

long long UCLN(long long a, long long b)
{
    while (b != 0)
    {
        auto temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class fract
{
private:
    long long nominator, denominator;
    long long turg, maurg;

public:
    void input()
    {
        cin >> nominator >> denominator;
        if (denominator == 0)
        {
            throw exception();
        }

        long long gcd = UCLN(nominator, denominator);
        turg = nominator / gcd;
        maurg = denominator / gcd;

        if (turg < 0 && maurg < 0)
        {
            turg = -turg;
            maurg = -maurg;
        }

        else if (maurg < 0)
        {
            maurg = -maurg;
            turg = -turg;
        }
    }
    long long tu_rg()
    {
        return turg;
    }
    long long mau_rg()
    {
        return maurg;
    }
    void output()
    {
        cout << nominator << "/" << denominator;
    }
};

bool smaller_than(fract &a, fract &b)
{
    long long prod1 = a.tu_rg() * b.mau_rg();
    long long prod2 = b.tu_rg() * a.mau_rg();
    return prod1 < prod2;
}

bool equal(fract &a, fract &b)
{
    return (a.tu_rg() == b.tu_rg() && a.mau_rg() == b.mau_rg());
}

int main()
{
    int n;
    cin >> n;
    fract *a = new fract[n];

    int index = 0;
    for (int i = 0; i < n; i++)
    {
        try
        {
            a[index++].input();
        }
        catch (exception e)
        {
            index--;
        }
    }

    n = index;

    auto min = a[0];
    int _count = 1;
    for (int i = 1; i < n; i++)
    {
        if (smaller_than(a[i], min))
        {
            min = a[i];
            _count = 1;
        }
        else if (equal(a[i], min))
        {
            _count++;
        }
    }
    min.output();
    cout << " is the smallest and appears " << _count << " time(s)";
}
