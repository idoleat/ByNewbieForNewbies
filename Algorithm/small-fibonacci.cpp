#include <iostream>
#include <vector>

using namespace std;

int fibo(vector<int> &fi, int n) {
    if (n <= (int)fi.size())
        return fi[n - 1];
    else {
        fi.push_back(fibo(fi, n - 1) + fibo(fi, n - 2));
        return fi.back();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = -1;

    vector<int> fibo_num;
    fibo_num.push_back(1);
    fibo_num.push_back(1);
    while (cin >> n) {
        cout << fibo(fibo_num, n + 1) << "\n";
    }

    return 0;
}
