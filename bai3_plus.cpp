/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <vector>
using namespace std;

// ###INSERT CODE HERE -
class POINT
{
public:
    int x, y;
    void input()
    {
        cin >> x >> y;
    }

    int distance(POINT z)
    {
        return (x - z.x) * (x - z.x) + (y - z.y) * (y - z.y);
    }

    void output()
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class RECTANGLE
{
public:
    POINT p1, p2;
    RECTANGLE(POINT a, POINT b)
    {
        p1 = a;
        p2 = b;
    }

    bool contain(POINT m)
    {
        int minX = min(p1.x, p2.x);
        int maxX = max(p1.x, p2.x);
        int minY = min(p1.y, p2.y);
        int maxY = max(p1.y, p2.y);
        if (minX < m.x && m.x < maxX )
        {
            if (minY < m.y && m.y < maxY)
            {
                return true;
            }
        }
        return false;
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
    int furthest = 0, furthest_i, furthest_j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].distance(arr[j]) > furthest)
            {
                furthest = arr[i].distance(arr[j]);
                furthest_i = i;
                furthest_j = j;
            }
        }
    }

    RECTANGLE rect(arr[furthest_i], arr[furthest_j]);
    for (int i = 0; i < n; i++)
    {
        if (rect.contain(arr[i]))
        {
            arr[i].output();
            cout << endl;
        }
    }
}
