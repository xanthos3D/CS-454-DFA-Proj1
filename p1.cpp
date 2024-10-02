#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// Function to encode a string into an integer using base 4 (1-4)
int encodeToState(const string& s) {
    int encoded = 0;
    int base = 4;
    int len = s.length();
    
    for (int i = 0; i < len; ++i) {
        int value;
        switch (s[i]) {
            case 'a': value = 1; break;
            case 'b': value = 2; break;
            case 'c': value = 3; break;
            case 'd': value = 4; break;
            default: value = -1; 
        }
        //essentially doing 4^len * letter
        encoded += value * pow(base, len - i - 1);
    }
    return encoded;
}

// Function to decode an integer into a string using base 4 (1-4)
string decodeToString(int encoded, int length) {
    string decoded = "";
    int base = 4;

    while (length > 0) {
        //sibtract by 1 because we are using 1 based instead of 0
        int value = (encoded - 1) % base;
        encoded = (encoded - 1) / base;
        
        switch (value) {
            case 0: decoded = 'a' + decoded; break;
            case 1: decoded = 'b' + decoded; break;
            case 2: decoded = 'c' + decoded; break;
            case 3: decoded = 'd' + decoded; break;
            case -1: decoded += "error";
        }
        length--;
    }
    
    return decoded;
}

int main() {
    // Array of test cases
    vector<string> testCases = {
        "a", "b", "c", "d",
        "aa", "ab", "ba", "bb", "cd",
        "abc", "cba", "aad", "ddd",
        "aaaa", "abcd", "dddd",
        "babca", "ddddd",
        ""
    };

    // Loop through test cases
    for (const string& s : testCases) {
        int state = encodeToState(s);
        string decodedString = decodeToString(state, s.length());

        cout << "Test case: '" << s << "'" << endl;
        cout << "State: " << state << ", Decoded: '" << decodedString << "'" << endl << endl;
    }

    return 0;
}