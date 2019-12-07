#include <iostream>
#include <string>
using namespace std;

int factorial(int n) {
  int result = 1;
  for (int i = 1; i <= n; i++) {
    result *= i;
  }
  return result;
}

// put the element at index (offset by i) element at i
// and shift the rest on the right of i
void shift (string &s, int i, int index) {
  int temp = (s[i+index] - '0');
  for (int j = i + index; j > i; j --) {
    s[j] = s[j-1];
  }
  s[i] = '0'+temp;
}

string kth_permutation(string &s, int k) {
  int n = s.size();
  for (int i = 0; i < n - 1; i++) {
    int fact = factorial(n-i-1);
    int index = (k/fact);
    shift(s, i, index);
    k = k - fact*index;
  }
  return s;
}
/* Lexicographic order permutation */
string getPermutation(int n, int k) {
  string s(n, '0');
  string result;
  for (int i = 0; i < n; i++)
  {
    s[i] += i + 1;
  }

  return kth_permutation(s, k);
}

int main() {
  string s = getPermutation(4, 5);
  
  cout << s << endl;
  return 0;
}

