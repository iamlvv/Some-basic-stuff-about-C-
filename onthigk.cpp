#include <iostream> 
#include <string>
using namespace std;

int check(int n) {
    static int count = 0;
    if (n > 0) {
        count++;
        n = n / 2;
    }
    cout << count << endl;
    return n;
}
// Driver code
int main()
{
    cout << check(2) << endl;
    cout << check(4) << endl;
    string s = "foo(number2,1)";
    string p = "a";
    if (s.find(p) > 10000) cout << "false";
    int pos = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            pos = i;
            break;
        }
    }
    string result = s.substr(1, pos - 1);
    cout << result << endl;
    return 0;
}