/*
You will be given an array of N integers and you have to print the integers in the reverse order.

Input Format

The first line of the input contains N, where N is the number of integers.
The next line contains N space-separated integers.

Constraints

1 <= N <= 1000
1 <= A[i] <= 10000, where A[i] is the i-th integer in the array.

Output Format

Print the N integers of the array in the reverse order, space-separated on a single line.

Sample Input

4
1 4 3 2

Sample Output

2 3 4 1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<string> split(string, string);
vector<int> strToInt(const vector<string> &);
vector<int> reverse(const vector<int> &);
void print(const vector<int> &);

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string s; string data;
    getline(cin, s);
    if (stoi(s) < 1) cerr << "Invalid Input" << endl;
    
    getline(cin, data); // N space-separated integers
    // parse data into tokens; delimit by space
    auto parsed = strToInt(split(data, " "));
    auto reversed = reverse(parsed);
    print(reversed);
     
    return 0;
}

vector<string> split(string ip, string delimiter) {
    vector<string> p;
    int start = 0, end, delimSize = delimiter.size();
    
    for (;;) {
        end = ip.find(delimiter, start);
        string sub = ip.substr(start, end - start);
        if (!sub.empty())
            p.push_back(sub);
        
        if (end == string::npos) {
            break;
        }
        
        start = end + delimSize;
    }
        
    return p;
}

vector<int> strToInt(const vector<string> & s) {
    vector<int> i;
    for (auto e : s) {
        i.push_back(stoi(e));
    }
    
    return i;
}

vector<int> reverse(const vector<int> & input) {
    return vector<int>(input.rbegin(), input.rend());
}

void print(const vector<int> &v) {
    for (auto i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << " ";
    }
}

