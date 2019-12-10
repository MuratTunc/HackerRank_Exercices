#include <bits/stdc++.h>
#include <string>
using namespace std;

bool Compare_String(const string &a,const string &b)
{
            if(a.length()  == b.length() )
                return a.compare( b )>0;
            else 
               return a.length()  > b.length();

}

// Complete the bigSorting function below.
vector<string> bigSorting(vector<string> unsorted) {

    vector<string>::iterator itx,ity;
    
    for(itx=unsorted.begin(); itx!=unsorted.end(); itx++)
        for(ity=itx+1; ity!=unsorted.end(); ity++) 
            if( Compare_String(*itx,*ity) )
                std::iter_swap(itx,ity);
      

    return unsorted;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> unsorted(n);

    for (int i = 0; i < n; i++) {
        string unsorted_item;
        getline(cin, unsorted_item);

        unsorted[i] = unsorted_item;
    }

    vector<string> result = bigSorting(unsorted);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

