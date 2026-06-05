#include <iostream>
#include <vector>
using namespace std;

// Function to check prime number
bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Function to check palindrome
bool isPalindrome(int n) {
    int original = n;
    int reverse = 0;

    while (n > 0) {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n = n / 10;
    }

    return original == reverse;
}

int main() {

    vector<int> v;
    int n, num, choice;
    int count = 0;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    cout << "\nChoose property to count:\n";
    cout << "1. Even numbers\n";
    cout << "2. Odd numbers\n";
    cout << "3. Prime numbers\n";
    cout << "4. Palindrome numbers\n";

    cin >> choice;

    for (int i = 0; i < v.size(); i++) {

        if (choice == 1 && v[i] % 2 == 0)
            count++;

        else if (choice == 2 && v[i] % 2 != 0)
            count++;

        else if (choice == 3 && isPrime(v[i]))
            count++;

        else if (choice == 4 && isPalindrome(v[i]))
            count++;
    }

    cout << "\nTotal count = " << count << endl;

    return 0;
}