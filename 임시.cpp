#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    vector<string> completion;
    completion = {"mislav", "stanko", "mislav", "ana"};

    unordered_map<string, int> strMap;
    
    for(auto elem : completion)
    {
        if(strMap.end() == strMap.find(elem)){
            strMap.insert(make_pair(elem, 1));
            cout << "if " << strMap[elem] << endl;
            cout << elem << endl;
        }
        else{
            strMap[elem]++;
            cout << "else " << strMap[elem] << endl;
        }
    }
}