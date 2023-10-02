// Z funtion 
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Complexity O(n)
vector<int> z_function(string s){
    int n = (int) s.length(); // n = length of string s
    cout << "n = " << n << endl;
    vector<int> z(n); // z[i] = longest common prefix between s and the suffix of s starting at i
    for (int i = 1, l = 0, r = 0; i < n; i++){
        if (i <= r){
            z[i] = min(r - i + 1, z[i - l]); //backtracking
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}


//Complexity O(n^2)
vector<int> z_function2(string s){
    int n = (int) s.length(); // n = length of string s
    cout << "n = " << n << endl;
    vector<int> z(n); // z[i] = longest common prefix between s and the suffix of s starting at i, z[0] = 0
    for (int i = 1; i < n; i++){
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
    }

    return z;
}

int main (){
    string s = "aaaabaaab";
    vector<int> z = z_function(s);
    for (int i = 0; i < z.size(); i++){
        cout << z[i] << " ";
    }
    cout << endl;
    vector <int> z2 = z_function2(s);
    for (int i = 0; i < z2.size(); i++){
        cout << z2[i] << " ";
    }
    cout << endl;
    return 0;
}