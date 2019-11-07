/**
 * Give two binary strings, return their sum(alse a binary string)
 * For example
 * a = "11"
 * b = "1"
 * Return "100".
 **/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string  addBinary(string a, string b) {
        string result;
        const size_t n = a.size() > b.size() ? a.size() : b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        for (size_t i = 0; i < n; i++) {
            const int ai = i < a.size() ? a[i] - '0' : 0;
            const int bi = i < b.size() ? b[i] - '0' : 0;
            const int val = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            result.insert(result.begin(), val + '0');
        }
        if (carry ==1) result.insert(result.begin(), '1');
        return result;
    }
};

int main() {
    string a = "10010";
    string b = "1011";
    Solution s;
    cout << s.addBinary(a, b) << endl;
    return 0;
}