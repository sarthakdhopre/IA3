
#include <iostream>
#include <vector>
using namespace std;

const int TABLE_SIZE = 37;
const int DATA_SIZE = 20;

class HashTable {
private:
    vector<int> table[TABLE_SIZE];

public:

    // Mid-Square Hash Function
    int hashFunction(int key) {
        int square = key * key;

        // Extract middle two digits
        // Equivalent to padding the square to 4 digits
        int middleDigits = (square / 10) % 100;

        return middleDigits % TABLE_SIZE;
    }

    // Insert using Separate Chaining
    void insert(int key) {
        int index = hashFunction(key);

        cout << "Inserting " << key
             << " at index " << index;

        if (!table[index].empty()) {
            cout << " -> Collision occurred";
        }

        table[index].push_back(key);
        cout << endl;
    }
 // Search an element
    void search(int key) {
        int index = hashFunction(key);

        for (int i = 0; i < table[index].size(); i++) {
            if (table[index][i] == key) {
                cout << key << " found at index "
                     << index << endl;
                return;
            }
        }

        cout << key << " not found in hash table."
             << endl;
    }
 // Display complete hash table
    void display() {
        cout << "\n========== HASH TABLE ==========\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << " : ";

            if (table[i].empty()) {
                cout << "EMPTY";
            } else {
                for (int j = 0; j < table[i].size(); j++) {
                    cout << table[i][j] << " -> ";
                }
                cout << "NULL";
            }
  cout << "NULL";
            }

            cout << endl;
        }
    }
};

int main() {

    cout << "====================================\n";
    cout << "       MANGO VARIETIES HASHING\n";
    cout << "====================================\n";

    cout << "Name : Sarthak Anil Dhopre\n";
    cout << "PRN  : 202501100021\n";

    // Dataset generated using:
    // v[i] = (21 + 13 * i) % 100

    int mangoes[DATA_SIZE] = {
        21, 34, 47, 60, 73,
        86, 99, 12, 25, 38,
        51, 64, 77, 90, 3,
        16, 29, 42, 55, 68
    };

    HashTable ht;

    cout << "\nOriginal Mango Dataset:\n";

    for (int i = 0; i < DATA_SIZE; i++) {
        cout << mangoes[i] << " ";
    }
 // Display final hash table
    ht.display();

    // Search operation
    int key;

    cout << "\nEnter mango value to search: ";
    cin >> key;

    ht.search(key);

    cout << "\nProgram Executed Successfully.\n";

    return 0;
}

    cout << "\n\nInserting Elements:\n";

    for (int i = 0; i < DATA_SIZE; i++) {
        ht.insert(mangoes[i]);
    }
