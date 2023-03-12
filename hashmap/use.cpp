#include <iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map <string,int> m;

    pair <string,int> a("hello",1);
    m.insert(a);
    cout << m.at("hello") << endl;
    return 0;
}