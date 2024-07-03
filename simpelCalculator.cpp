#include <iostream>

using namespace std;

void displayMenu() {
    cout << "Simple Calculator!" << endl;
    cout << "Choose an operation (+, -, *, /): ";
}

double getNumber(const string &prompt) {
    double number;
    cout << prompt;
    cin >> number;
    return number;
}

char getOperation() {
    char operation;
    cin >> operation;
    return operation;
}

void performCalculation(double num1, double num2, char operation) {
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << "Result: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please choose a valid operation." << endl;
    }
}

int main() {
    double num1 = getNumber("Enter the First Number: ");
    double num2 = getNumber("Enter the Second Number: ");

    displayMenu();
    char operation = getOperation();

    performCalculation(num1, num2, operation);

    return 0;
}
