#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

vector<string> split_string(string);


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<string> splits;
    
    string n_q;
    getline(cin, n_q);
  
    vector<string> vect_n_q = split_string(n_q);
    int row=stoi(vect_n_q[0]);
    string new_input_line;
    vector<string> vect_temp;
    vector<vector<string>> vect_2D(row); // array sequences
    for(int i=0;i<row;i++){
        getline(cin,new_input_line);
        vect_2D[i]=split_string(new_input_line);
    } 

    vector<vector<string>> vect_Index_2D(row); // array sequences
    for(int i=0;i<row;i++){
        getline(cin,new_input_line);
        vect_Index_2D[i]=split_string(new_input_line);
    }
    
    int row_index;
    int clon_index;

    for(int i=0;i<row;i++){
        row_index=stoi(vect_Index_2D[i][0]);
        clon_index=stoi(vect_Index_2D[i][1])+1;
        cout<< vect_2D[row_index][clon_index]<<endl;

    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}



