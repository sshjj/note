#include <iostream>
#include <cmath>

using namespace std;


bool is_prime(int n) {
    if (n < 2) {
        return false;
    }
    int r = sqrt(n);
    for (int i = 2; i <= r; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int reverse(int n) {
    int ans = 0;
    while (n > 0) {
        ans = 10 * ans + n % 10;
        n /= 10;
    }
    return ans;
}


bool is_palindrome(int n) {
    return n == reverse(n);
}

bool check_number(int n) {
    int mask = 10;
    while (true) {
        int left = n / mask;
        int right = n % (mask / 10);
        int num = left * (mask / 10) + right;
        if (is_palindrome(num) && is_prime(num)) {
            return true;
        }
        if (mask > n) {
            break;
        }
        mask *= 10;
    }
    
    return false;
}

int main(int argc, char *argv[]) {
    
    int N, M;
    cin >> N >> M;
    int total = 0;
    for (int i = N; i <= M; ++i) {
        if (check_number(i)) {
            ++total;
        }
    }
    cout << total << endl;
    system("pause");
    return 0;
}