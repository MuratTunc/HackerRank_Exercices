#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* strtoull */
#include <bits/stdc++.h>

using namespace std;
void printVector(vector<string>& vec)
{
    for (string a : vec)
        cout << a << " ";

    cout<<endl;
}
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}



void SwapSTRINGS(string *x,string *y)
{
    string temp=*x;
    *x=*y;
    *y=temp;
}

bool CompareString(string a,string b)
{
    if( a.size()<b.size() )
        return false; // a is greater;

    if( a.size()>b.size() )
        return true; // a is greater;

    if( a.size()==b.size() )
    {
        for(int i = 0; i < a.size(); i++)
        {
            if ((a[i]-'0')  > (b[i]-'0'))
                 return true;
        }
    }
    return false;

}


bool isGreater(const string& s1, const string& s2) {
   if(s1.size() > s2.size())
        return true;
   if(s1.size() < s2.size())
        return false;
    int n=s1.size();

    for(int i=0;i<n;i++)
    {
        if(s1[i] > s2[i])
           return true;
        else if(s1[i] < s2[i])
           return false;
    }

    return false;
}
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(vector<int> &arr, int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];

}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSortString(vector<string> &arr, int n, int exp)
{
    string output[n]; // output array
    int i, 
    vector<string> count(10);
    
    string temp;
    int radix=0;
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
    {
        radix=arr[i].size()-exp;
        if(radix<=0)
            radix=0;

        count[ stoi(arr[i].substr(radix, 1)) ]++;
    }



    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];



    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        radix=arr[i].size()-exp;
        if(radix<=0)
            radix=0;
        output[count[ stoi(arr[i].substr(radix, 1)) ] - 1] = arr[i];
        count[ stoi(arr[i].substr(radix, 1)) ]--;
    }



    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];



}

int main()
{


    //vector<string> unsorted{ "0","100", "123", "90", "13", "253","254","255","256","75", "90", "8", "90", "1"};


    int n = rand() % 200000 + 1;
    vector<string> unsorted(n);
    for( int i = 0; i < n; ++i ) {
        unsorted[i]=to_string( rand() % 99999 + 1 );
    }
    //Find the largest size string in the vector.
    //find max element...
    int mx=0;
    for (int i = 1; i < n; i++)
    {    if (unsorted[i].size() > mx)
            mx = unsorted[i].size();
    }
    cout<<"mx="<<mx<<endl;

    for (int exp = 1; exp <mx; exp++)
        countSortString(unsorted, n, exp);

    for(int i=0;i<n;i++)
        cout<<unsorted[i]<<endl;




    /*
    int n = rand() % 200000 + 1;
    vector<int> unsorted(n);
    for( int i = 0; i < n; ++i ) {
        unsorted[i]=rand() % 99999 + 1;
    }

    //find max element...
    int mx = unsorted[0];
    for (int i = 1; i < n; i++)
    {    if (unsorted[i] > mx)
            mx = unsorted[i];
    }

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; mx/exp > 0; exp *= 10)
        countSort(unsorted, n, exp);



    for(int i=0;i<n;i++)
        cout<<unsorted[i]<<endl;
    */
    /*
    int temp=0;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++){
            if(unsorted[j]>unsorted[j+1])
            {
                temp=unsorted[j];
                unsorted[j]=unsorted[j+1];
                unsorted[j+1]=temp;
            }
        }
    }
    cout<<"vector sorting finished..."<<endl;
        for(int i=0;i<n;i++)
            cout<<unsorted[i]<<endl;



    /*
    vector<string> unsorted(n);
    for( int i = 0; i < n; ++i ) {
        unsorted[i]=std::to_string(rand() % 99999 + 1);
    }


    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n-1;j++){
            if(isGreater(unsorted[j], unsorted[j+1]))
               swap(unsorted[j], unsorted[j+1]);
        }
    }
    */


    cout<<endl;
    return 0;
}

