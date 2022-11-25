#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
private:
    string *ps;
    int i;
public:
    HasPtr(const string &s = string()) :
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr &p) : 
        ps(new string(*p.ps)), i(p.i) { }
    HasPtr& operator= (const HasPtr&);
    HasPtr& operator= (const string&);
    string& operator*();
    bool operator< (const HasPtr&) const;
    ~HasPtr();
};

HasPtr::~HasPtr()
{
    delete ps;
}

inline 
HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newps = new string(*rhs.ps);
    delete ps;
    ps = newps;
    i = rhs.i;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs)
{
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*()
{
    return *ps;
}
inline 
void swap(HasPtr &lhs, HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

int main(int argc, char **argv)
{
    vector<HasPtr> vh;
    int n = atoi(argv[1]);
    for(int i = 0; i < n; i++)
        vh.push_back(to_string(n - i));
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    sort(vh.begin(), vh.end());
    for(auto p : vh)
        cout << *p << " ";
    cout << endl;
    return 0;
}

