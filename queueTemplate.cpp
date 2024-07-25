#include<iostream>
#include<string>
#include<vector>
using namespace std;

template <class T>
void processQueue(vector<T>& v) {
    int choice;
    do {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                T num;
                cout << "Enter element: ";
                cin >> num;
                v.push_back(num);
                break;
            }
            case 2: {
                if (!v.empty()) {
                    v.erase(v.begin());
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            }
            case 3: {
                if (!v.empty()) {
                    for (int i = 0; i < v.size(); i++) {
                        cout << v[i] << " ";
                    }
                    cout << endl;
                } else {
                    cout << "Queue is empty." << endl;
                }
                break;
            }
            case 0: {
                cout << "Exiting..." << endl;
                break;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
}

int main() {
    vector<int> intQueue;
    processQueue(intQueue);
    return 0;
}
