#include <cmath>
#include <cstdio>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   


    string line;
    int number;
    vector<int> numbers;
    int x;
    int a,b;

    getline(cin, line);
    getline(cin, line);
    
    istringstream stream(line);
    while (stream >> number)
        numbers.push_back(number);
    
    cin>>x;
    cin>>a>>b;

    numbers.erase(numbers.begin()+x-1); 
    numbers.erase(numbers.begin()+a-1,numbers.begin()+b-1);
 
    cout<<numbers.size()<<endl;
    for(auto i:numbers)
       cout<<i<<" ";

    return 0;
}
