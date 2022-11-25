#include <iostream>
using namespace std;
#include "my_StrBlob.h"

int main(int argc, char **argv)
{
    StrBlob b1;
    {
        StrBlob b2 = {"a", "an", "the"};
        b1 = b2;
        b2.push_back("about");
        cout << "b2 size():" << b2.size() << endl;
        cout << "b2 front():" << b2.front() << " " << "b2 back():" << b2.back() << endl;
    }

    cout << "b1 size():" << b1.size() << endl;
    cout << "b1 front():" << b1.front() << " " << "b1 back():" << b1.back() << endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    cout << "b3 size():" << b3.size() << endl;
    cout << "b3 front():" << b3.front() << " " << "b3 back():" << b3.back() << endl;

    cout << "b1 all elements" << endl;
    for(auto it = b1.begin(); neq(it, b1.end()); it.incr())
        cout << it.deref() << endl;
    return 0;
}