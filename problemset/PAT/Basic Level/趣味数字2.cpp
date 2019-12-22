#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
 
int main()
{
    int n;
    while (cin >> n)
    {
        int i, beg, s1 = 0, cha, num;
        map<int, int>vec;
        for (i = 0; i < n; ++i)
        {
            cin >> num;
            vec[num]++;
        }
        map<int, int>::iterator it = vec.begin(), jt = vec.end();
        for (; it != vec.end(); ++it)
        {
            if (it->second > 1)
                s1 = s1 + (it->second - 1) * it->second / 2;
        }
        if (s1 == 0)
        {
            it = vec.begin();
            beg = it->first;
            it++;
            cha = it->first - beg;
            for (; it != vec.end(); ++it)
            {
                if (cha > it->first - beg)
                {
                    cha = it->first - beg;
                    s1 = 1;
                }
                else if (cha == it->first - beg)
                    s1++;
                beg = it->first;
            }
        }
        it = vec.begin();
        jt--;
        if (it->first != jt->first)
            cout << s1 << ' ' << it->second * jt->second << endl;
        else
            cout << it->second - 1 << ' ' << it->second - 1 << endl;
    }
    return 0;
}
