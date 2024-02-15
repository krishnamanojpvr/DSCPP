#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int capacity;
    vector<int> table;
public:
    HashTable(int size) {
        capacity = size;
        table.resize(capacity, -1); // Initialize all slots as -1 (indicating empty)
    }

    // Hash function
    int hash(int key) {
        return key % capacity;
    }

    // Insert key into the hash table
    void insert(int key) {
        int index = hash(key);

        // Linear probing to find an empty slot
        while (table[index] != -1) {
            index = (index + 1) % capacity;
        }

        // Insert the key into the found empty slot
        table[index] = key;
    }

    // Search for key in the hash table
    bool search(int key) {
        int index = hash(key);

        // Linear probing to find the key
        while (table[index] != key) {
            if (table[index] == -1) // If we encounter an empty slot, the key is not in the table
                return false;
            index = (index + 1) % capacity;
        }

        // If we reach here, we found the key
        return true;
    }

    // Delete key from the hash table
    void remove(int key) {
        int index = hash(key);

        // Linear probing to find the key
        while (table[index] != key) {
            if (table[index] == -1) // If we encounter an empty slot, the key is not in the table
                return;
            index = (index + 1) % capacity;
        }

        // If we reach here, we found the key, so mark the slot as deleted (-2)
        table[index] = -2;
    }
};

int main() {
    HashTable ht(10);
    ht.insert(12);
    ht.insert(25);
    ht.insert(35);
    ht.insert(4);

    cout << "Searching for 12: " << ht.search(12) << endl;
    cout << "Searching for 25: " << ht.search(25) << endl;
    cout << "Searching for 35: " << ht.search(35) << endl;
    cout << "Searching for 4: " << ht.search(4) << endl;
    cout << "Searching for 10: " << ht.search(10) << endl;

    ht.remove(25);
    cout << "Searching for 25 after removal: " << ht.search(25) << endl;

    return 0;
}
