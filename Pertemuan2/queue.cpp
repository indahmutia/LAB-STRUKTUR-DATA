#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int input;

    while (cin >> input) {
        q.push(input);
    }
    do {
        cout << q.front() << " ";
        q.pop();
    } while (q.size() != 0);

   cout << endl;
   return 0;
}