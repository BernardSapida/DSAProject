#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class ArrayDSA {
    private:
        int *arrNumbers = new int[1];
        int arrLength = 0;

    public:
        void setArrNumbers(int n) {
            int number = 0;
            delete[] arrNumbers;
            arrLength = n;
            arrNumbers = new int[arrLength];

            for (int i = 0; i < n; i++) {
                cout << "Enter a number: ";
                cin >> number;
                arrNumbers[i] = number;
            }
        }
        
        int queryNumbers() {
            int length;
            cout << "How many numbers would you like to enter: ";
            cin >> length;
            return length;
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
                
                setArrNumbers(queryNumbers());

                if(chosenType == 1) displayOddEvenNumbers("odd");
                if(chosenType == 2) displayOddEvenNumbers("even");
            }
            else {
                setArrNumbers(queryNumbers());
                displaySquaredNumbers();
            }
        }

        void displayOddEvenNumbers(string toFind) {
            cout << "\n==================================================\n\n";
            if (toFind == "odd") cout << "Odd Numbers: ";
            if (toFind == "even") cout << "Even Numbers: ";

            for (int i = 0; i < arrLength; i++) {
                if(toFind == "odd" && arrNumbers[i] % 2 != 0) cout << arrNumbers[i] << " ";
                else if (toFind == "even" && arrNumbers[i] % 2 == 0) cout << arrNumbers[i] << " ";
            }
            cout << "\n\n==================================================\n\n";
        }

        void displaySquaredNumbers() {
            cout << "Squared Numbers: ";

            for (int i = 0; i < arrLength; i++) {
                cout << pow(arrNumbers[i], 2) << " ";
            }
            cout << "\n\n==================================================\n\n";
        }
};

class SortingAlgorithmDSA {
    private:
        int* arrNumbers = new int[1];
        int arrLength = 0;

    public:
        void setArrNumbers(int n) {
            int number = 0;
            delete[] arrNumbers;
            arrLength = n;
            arrNumbers = new int[arrLength];

            for (int i = 0; i < n; i++) {
                cout << "Enter a number: ";
                cin >> number;
                arrNumbers[i] = number;
            }
        }

        int queryNumbers() {
            int length;
            cout << "How many numbers would you like to enter: ";
            cin >> length;
            return length;
        }

        void queryProblem() {
            int choice;

            while (true) {
                cout << "Options:" << endl;
                cout << "[1] Sort List of Numbers using Selection" << endl;
                cout << "[2] Sort List of Numbers using Insertion" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) break;
                cout << "Invalid input! Please try again.\n";
                cout << "\n==================================================\n\n";
            }
            cout << "\n==================================================\n\n";

            setArrNumbers(queryNumbers());

            if(choice == 1) selectionSort();
            if(choice == 2) insertionSort();
        }

        void selectionSort() {
            int LOWER_NUMBER_INDEX;
            int temp;

            cout << "\n==================================================\n\n";
            cout << "Selection Sort: " << endl;
            
            for (int n = 0; n < arrLength; n++) {
                cout << arrNumbers[n] << " ";
            }
            cout << "Original" << endl;

            for(int i = 0; i < arrLength; i++) {
                LOWER_NUMBER_INDEX = i;
                
                for (int k = i + 1; k < arrLength; k++) {
                    if(arrNumbers[k] < arrNumbers[LOWER_NUMBER_INDEX]) LOWER_NUMBER_INDEX = k;
                }

                // Swapping Values
                temp = arrNumbers[i];
                arrNumbers[i] = arrNumbers[LOWER_NUMBER_INDEX];
                arrNumbers[LOWER_NUMBER_INDEX] = temp;

                for (int n = 0; n < arrLength; n++) {
                    cout << arrNumbers[n] << " ";
                }

                cout << "Swap #" << i + 1 << endl;
            }

            for (int n = 0; n < arrLength; n++) {
                cout << arrNumbers[n] << " ";
            }
            cout << "Sorted List" << endl;
            cout << "\n\n==================================================\n";
        }

        void insertionSort() {
            int swapNumber = 1;
            int LOWER_NUMBER_INDEX = 0;
            int temp = 0;

            cout << "\n==================================================\n\n";
            cout << "Selection Sort: " << endl;

            for (int n = 0; n < arrLength; n++) {
                cout << arrNumbers[n] << " ";
            }
            cout << "Original" << endl;

            for (int i = 0; i < arrLength; i++) {
                for(int k = i; k < i + 1; k++) {
                    if(arrNumbers[k] < arrNumbers[i]) {
                        // Swap
                        temp = arrNumbers[i];
                        arrNumbers[i] = arrNumbers[k];
                        arrNumbers[k] = temp;
                    }

                    for(int j = k; j > 0; j--) {
                        if(arrNumbers[j] > arrNumbers[j - 1]) break;

                        // Swap
                        temp = arrNumbers[j - 1];
                        arrNumbers[j-1] = arrNumbers[j];
                        arrNumbers[j] = temp;

                        for (int n = 0; n < arrLength; n++) {
                            cout << arrNumbers[n] << " ";
                        }

                        cout << "Swap #" << swapNumber << endl;
                        swapNumber++;
                    }
                }
            }

            for (int n = 0; n < arrLength; n++) {
                cout << arrNumbers[n] << " ";
            }
            cout << "Sorted List" << endl;
            cout << "\n\n==================================================\n";
        }
};

class SearchingAlgorithmDSA {
    private:
        int* arrNumbers = new int[1];
        int arrLength = 0;

    public:
        void setArrNumbers(int n) {
            int number = 0;
            delete[] arrNumbers;
            arrLength = n;
            arrNumbers = new int[arrLength];

            for (int i = 0; i < n; i++) {
                cout << "Enter a number: ";
                cin >> number;
                arrNumbers[i] = number;
            }
        }

        int queryNumbers() {
            int length;
            cout << "How many numbers would you like to enter: ";
            cin >> length;
            return length;
        }

        void queryProblem() {
            int choice;

            while (true) {
                cout << "Options:" << endl;
                cout << "[1] Using Binary Search, find element in a list and display attempts and index" << endl;
                cout << "[2] Using Linear Search, find element in a list and display attempts and index" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) break;
                cout << "Invalid input! Please try again.\n";
                cout << "\n==================================================\n\n";
            }
            cout << "\n==================================================\n\n";

            setArrNumbers(queryNumbers());

            if (choice == 1) binarySearch();
            if (choice == 2) linearSearch();
        }

        void binarySearch() {
            int numberOfAttempts = 0;
            int position = -1;
            int start = 0;
            int mid = floor(arrLength / 2);
            int end = arrLength-1;
            int element;

            cout << "What element you want to find the index: ";
            cin >> element;

            cout << "\n==================================================\n\n";
            cout << "Binary Search: " << endl;

            while (start <= end) {
                numberOfAttempts++;

                if (arrNumbers[mid] == element) {
                    position = mid;
                    break;
                }
                else if (arrNumbers[mid] < element) {
                    start = mid - 1;
                }
                else if (arrNumbers[mid] > element) {
                    end = mid + 1;
                }

                mid = floor((start - end) / 2);
            }

            cout << "Number of attempts: " << numberOfAttempts << endl;
            cout << "Index of " << element << ": " << position << endl;

            cout << "\n==================================================\n\n";
        }

        void linearSearch() {
            int numberOfAttempts = 0;
            int position = -1;
            int element;

            cout << "What element you want to find the index: ";
            cin >> element;

            cout << "\n==================================================\n\n";
            cout << "Linear Search: " << endl;

            for (int i = 0; i < arrLength; i++) {
                numberOfAttempts++;

                if (arrNumbers[i] == element) {
                    position = i;
                    break;
                }
            }

            cout << "Number of attempts: " << numberOfAttempts << endl;
            cout << "Index of " << element << ": " << position << endl;

            cout << "\n==================================================\n\n";
        }
};

class QueueDSA {
    private:
        queue<string> orders_queue;

    public:
        void queryProblem() {
            int choice;

            while(true) {
                cout << "Options:" << endl;
                cout << "[1] List of orders (Food)" << endl;
                cout << "[2] Back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) {
                    if (choice == 1) {
                        int option;
                        cout << "\n==================================================\n\n";

                        while (true) {
                            cout << "Options:" << endl;
                            cout << "[1] Insert Food" << endl;
                            cout << "[2] Remove Food" << endl;
                            cout << "[3] Display Queue" << endl;
                            cout << "[4] Cancel" << endl;
                            cout << "Enter your choice: ";
                            cin >> option;
                            cout << "\n==================================================\n\n";

                            if (option == 1 || option == 2 || option == 3 || option == 4) {
                                if (option == 1) addElementInQueue();
                                if (option == 2) removeElementInQueue();
                                if (option == 3) displayQueue();
                                if (option == 4) break;
                            } else {
                                cout << "Invalid input! Please try again.\n";
                                cout << "\n==================================================\n\n";
                            }
                        }
                    }

                    if(choice == 2) break;
                } else {
                    cout << "Invalid input! Please try again.\n";
                    cout << "\n==================================================\n\n";
                }
            }

            cout << "\n\n==================================================\n\n";
        }

        void addElementInQueue() {
            string order;

            cout << "Name of order: ";
            cin >> order;
            orders_queue.push(order);
            cout << "\n==================================================\n\n";
        }

        void removeElementInQueue() {
            if (orders_queue.size() > 0) {
                cout << "Order named " << orders_queue.front() << " was removed!";
                orders_queue.pop();
                cout << "\n\n==================================================\n\n";
            }
            else {
                cout << "Queue is empty!";
                cout << "\n\n==================================================\n\n";
            }
            
        }

        void displayQueue() {
            queue<string> temp_queue = orders_queue;

            cout << "Queue of Orders: ";

            if (orders_queue.size() > 0) {
                while (!orders_queue.empty()) {
                    cout << orders_queue.front() << " ";
                    orders_queue.pop();
                }
                orders_queue = temp_queue;
            }
            else {
                cout << "Empty Queue!";
            }

            cout << "\n\n==================================================\n\n";
        }
};

class StackDSA {
    private:
        stack<string> books_stack;

    public:
        void queryProblem() {
            int choice;

            while(true) {
                cout << "Options:" << endl;
                cout << "[1] Stack of Book" << endl;
                cout << "[2] Back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) {
                    if (choice == 1) {
                        int option;
                        cout << "\n==================================================\n\n";

                        while (true) {
                            cout << "Options:" << endl;
                            cout << "[1] Insert Book" << endl;
                            cout << "[2] Remove Book" << endl;
                            cout << "[3] Display Stack" << endl;
                            cout << "[4] Cancel" << endl;
                            cout << "Enter your choice: ";
                            cin >> option;
                            cout << "\n==================================================\n\n";

                            if (option == 1 || option == 2 || option == 3 || option == 4) {
                                if (option == 1) addElementInQueue();
                                if (option == 2) removeElementInQueue();
                                if (option == 3) displayStack();
                                if (option == 4) break;
                            } else {
                                cout << "Invalid input! Please try again.\n";
                                cout << "\n==================================================\n\n";
                            }
                        }
                    }

                    if(choice == 2) break;
                } else {
                    cout << "Invalid input! Please try again.\n";
                    cout << "\n==================================================\n\n";
                }
            }

            cout << "\n\n==================================================\n\n";
        }

        void addElementInQueue() {
            string order;

            cout << "Name of book: ";
            cin >> order;
            books_stack.push(order);
            cout << "\n==================================================\n\n";
        }

        void removeElementInQueue() {
            if (books_stack.size() > 0) {
                cout << "Book named " << books_stack.top() << " was removed!";
                books_stack.pop();
                cout << "\n\n==================================================\n\n";
            }
            else {
                cout << "Stack is empty!";
                cout << "\n\n==================================================\n\n";
            }
            
        }

        void displayStack() {
            stack<string> temp_stack = books_stack;

            cout << "Stack of book: ";

            if (books_stack.size() > 0) {
                while (!books_stack.empty()) {
                    cout << books_stack.top() << " ";
                    books_stack.pop();
                }
                books_stack = temp_stack;
            }
            else {
                cout << "Empty Stack!";
            }

            cout << "\n\n==================================================\n\n";
        }
};

struct Node {
    int data;
    Node* link;
};

class LinkedListDSA {
    private:
        Node* head = new Node();

    public:
        void insertNodeAtHead(Node* node) {
            if (head->data == 0) head = node;
            else {
                Node* temp = head;
                head = node;
                head->link = temp;
            }
        }

        void queryProblem() {
            int choice;

            while (true) {
                cout << "Options:" << endl;
                cout << "[1] Linked List" << endl;
                cout << "[2] Back" << endl;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 1 || choice == 2) {
                    if (choice == 1) {
                        int option;
                        cout << "\n==================================================\n\n";

                        while (true) {
                            cout << "Options:" << endl;
                            cout << "[1] Insert Node at Head" << endl;
                            cout << "[2] Insert Node at Tail" << endl;
                            cout << "[3] Display Nodes" << endl;
                            cout << "[4] Cancel" << endl;
                            cout << "Enter your choice: ";
                            cin >> option;
                            cout << "\n==================================================\n\n";

                            if (option == 1 || option == 2 || option == 3 || option == 4) {
                                if (option == 1) insertNodeAtHead(getNewNode(20));
                                /*if (option == 2) insertNodeAtTail();*/
                                if (option == 3) displayNodes();
                                if (option == 4) break;
                            }
                            else {
                                cout << "Invalid input! Please try again.\n";
                                cout << "\n==================================================\n\n";
                            }
                        }
                    }

                    if (choice == 4) break;
                }
                else {
                    cout << "Invalid input! Please try again.\n";
                    cout << "\n==================================================\n\n";
                }
            }

            cout << "\n\n==================================================\n\n";
        }

        void displayNodes() {
            Node* temp = head;

            while (temp != NULL) {
                cout << temp->data << " ";
                temp = temp->link;
            };

            cout << endl;
        }

        Node* getNewNode(int data) {
            Node* node = new Node();
            node->data = data;
            node->link = NULL;

            return node;
        }
};

void startLinkedList() {
    LinkedListDSA linkedListDSA;
    linkedListDSA.queryProblem();
}

void startArray() {
    ArrayDSA arrayDSA;
    arrayDSA.queryProblem();
}

void startSortingAlgorithm() {
    SortingAlgorithmDSA sortingAlgorithmDSA;
    sortingAlgorithmDSA.queryProblem();
}

void startSearchingAlgorithm() {
    SearchingAlgorithmDSA searchingAlgorithmDSA;
    searchingAlgorithmDSA.queryProblem();
}

void startStacks() {
    StackDSA stackDSA;
    stackDSA.queryProblem();
}

void startQueue() {
    QueueDSA queueDSA;
    queueDSA.queryProblem();
}

void displayTerminal() {
    int choice;

    while (true) {
        cout << "Data Structure and Algorithm:" << endl;
        cout << "[1] Array" << endl;
        cout << "[2] Linked List" << endl;
        cout << "[3] Stacks" << endl;
        cout << "[4] Queue" << endl;
        cout << "[5] Searching Algorithm" << endl;
        cout << "[6] Sorting Algorithm" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5 || choice == 6) break;
        cout << "Invalid input! Please try again.\n";
        cout << "\n==================================================\n\n";
    }
    cout << "\n==================================================\n\n";
    
    if(choice == 1) startArray();
    if(choice == 2) startLinkedList();
    if(choice == 3) startStacks();
    if(choice == 4) startQueue();
    if(choice == 5) startSearchingAlgorithm();
    if(choice == 6) startSortingAlgorithm();
}

int main() {
    while(true) displayTerminal();
    return 0;
}