#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

struct Test 
{ 
   int diff, x1, x2; 
};

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
    int n=arr.size();
    sort(arr.begin(),arr.end());
    int k=0;
    int d=0;
    vector<int> diffs;
    vector<pair<int,int>> pairs;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i;j<n-1;j++)
        {
            d=abs(arr[i]-arr[j+1]);
            diffs.push_back(d);
            pairs.push_back(make_pair(arr[i],arr[j+1]));
        }
    }

    auto smallest = std::min_element( diffs.begin(), diffs.end() );
    vector <int> min_indexs;
    for(int i=0;i<diffs.size();i++)
        if(diffs[i]==(*smallest))
            min_indexs.push_back(i);

    vector<int> pairs_result;
    int index_temp=0;
    for(int i=0;i<min_indexs.size();i++)
    {
        index_temp=min_indexs[i];
        pairs_result.push_back((pairs[index_temp].first));
        pairs_result.push_back((pairs[index_temp].second));

    }
    return pairs_result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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

