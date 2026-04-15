#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b)
{
    if(get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b))
        return get<0>(a) < get<0>(b);    
    else if(get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b))
        return get<3>(a) > get<3>(b);
    else if(get<1>(a) == get<1>(b))
        return get<2>(a) < get<2>(b);
    else
        return get<1>(a) > get<1>(b);
}

int main()
{
    vector<tuple <string, int, int, int>> v;
    int n, lang, eng, math;
    string name; 
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        cin>>name>>lang>>eng>>math;
        v.emplace_back(name, lang, eng, math);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i=0; i<v.size(); i++)
        cout<<get<0>(v[i])<<"\n";
    
    return 0;
}