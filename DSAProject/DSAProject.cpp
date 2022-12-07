#include <iostream>
using namespace std;

class ArrayDSA {
    private:
        int *arrNumbers = new int[1];
        int nthNumbers = 0;

    public:
        void setArrNumbers(int n) {
            int number = 0;
            delete[] arrNumbers;
            nthNumbers = n;
            arrNumbers = new int[nthNumbers];

            for (int i = 0; i < n; i++) {
                cout << "Enter a number: ";
                cin >> number;
                arrNumbers[i] = number;
            }
        }
        
        int queryNumbers() {
            int nth;
            cout << "How many numbers would you like to enter: ";
            cin >> nth;
            return nth;
        }

        void queryProblem() {
            int choice;

            while (true) {
                cout << "Options:" << endl;
                cout << "[1] Display Odd/Even numbers from a set of numbers" << endl;
                cout << "[2] Display squared of individual numbers" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) break;
                cout << "Invalid input! Please try again.\n";
                cout << "\n==================================================\n\n";
            }
            cout << "\n==================================================\n\n";

            if (choice == 1) {
                int chosenType;

                while (true) {
                    cout << "Options:" << endl;
                    cout << "[1] Display Odd numbers from a set of numbers" << endl;
                    cout << "[2] Display Even numbers from a set of numbers" << endl;
                    cout << "Enter your choice: ";
                    cin >> chosenType;

                    if (chosenType == 1 || chosenType == 2) break;
                    cout << "Invalid input! Please try again.\n";
                    cout << "\n==================================================\n\n";
                }
                cout << "\n==================================================\n\n";
                
                int n = queryNumbers();
                setArrNumbers(n);

                if(chosenType == 1) displayOddEvenNumbers("odd");
                if(chosenType == 2) displayOddEvenNumbers("even");
            }
            else {
                displaySquaredNumbers();
            }
        }

        void displayOddEvenNumbers(string toFind) {
            cout << "\n==================================================\n\n";
            if (toFind == "odd") cout << "Odd Numbers: ";
            if (toFind == "even") cout << "Even Numbers: ";

            for (int i = 0; i < nthNumbers; i++) {
                if(toFind == "odd" && arrNumbers[i] % 2 != 0) cout << arrNumbers[i] << " ";
                else if (toFind == "even" && arrNumbers[i] % 2 == 0) cout << arrNumbers[i] << " ";
            }
            cout << "\n\n==================================================\n\n";
        }

        void displaySquaredNumbers() {
            cout << "Squared Numbers: ";

            for (int i = 0; i < nthNumbers; i++) {
                cout << pow(arrNumbers[i], 2) << " ";
            }
            cout << "\n\n==================================================\n\n";
        }
};

void startArray() {
    ArrayDSA arrayDSA;
    arrayDSA.queryProblem();
}

int main() {
    startArray();
    return 0;
}