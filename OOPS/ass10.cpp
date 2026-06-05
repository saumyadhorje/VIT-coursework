#include <iostream>
using namespace std;

// Custom exception class
class InvalidInput
{
public:
    void message()
    {
        cout << "Invalid input value" << endl;
    }
};

class LimitExceeded
{
public:
    void message()
    {
        cout << "Operation limit exceeded" << endl;
    }
};

int main()
{
    int num, den;
    int arr[5] = {10, 20, 30, 40, 50};
    int index;

    cout << "Enter numerator: ";
    cin >> num;

    cout << "Enter denominator: ";
    cin >> den;

    cout << "Enter array index: ";
    cin >> index;

    try
    {
        // Division by zero
        if (den == 0)
            throw den;

        // Invalid array index
        if (index < 0 || index >= 5)
            throw index;

        // Custom exception
        if (num < 0)
            throw InvalidInput();

        // Custom exception
        if (num > 100)
            throw LimitExceeded();

        int result = num / den;

        cout << "Result = " << result << endl;

        cout << "Array element = " << arr[index] << endl;
    }

    // Built-in exceptions
    catch (int ex)
    {
        cout << "Runtime Error Occurred" << endl;
    }

    // Custom exception handling
    catch (InvalidInput obj)
    {
        obj.message();
    }

    catch (LimitExceeded obj)
    {
        obj.message();
    }

    return 0;
}