/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <bits/stdc++.h>

using namespace std;

//###INSERT CODE HERE -



int main()
{
	big_integer f1 = 1, f2 = 1;
	int n;
	cin >> n;
	while(n >= 3){
		n--;
		auto temp = f2;
		f2.add(f1);
		f1.assign(temp);
	}
	f2.output();
    return 0;
}
