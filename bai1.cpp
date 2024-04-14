/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <vector>
using namespace std;
class POINT
{
public:
    int x, y;
    void input()
    {
        cin >> x >> y;
    }
    int square_distance(const POINT &other) const
    {
        int dx = x - other.x;
        int dy = y - other.y;
        return dx * dx + dy * dy; 
    }
};

class CIRCLE
{
private:
    POINT center;
    int radius;

public:
    bool contain(POINT temp)
    {
        return center.square_distance(temp) < radius * radius;
    }
    void input()
    {
        center.input();
        cin >> radius;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<POINT> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].input();
    }
    CIRCLE C;
    C.input();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (C.contain(arr[i]))
        {
            count += 1;
        }
    }
    cout << count;
}
