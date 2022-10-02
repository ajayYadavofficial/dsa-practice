class HashMapNode {
public:
    int key;
    int value;
    HashMapNode* next;
    
    HashMapNode(int k, int v, HashMapNode* n = NULL) {
        key = k;
        value = v;
        next = n;
    }
};

class MyHashMap {
public:
    const int BUCK_SIZE = 1000;
    HashMapNode* bucks[1000] = {NULL};
    
    
    MyHashMap() {
        // Leave emtpy
    }
    
    void put(int key, int value) {
        int index = hash(key);
        HashMapNode* buck = bucks[index];
        
        if (buck == NULL) {
            bucks[index] = new HashMapNode(key, value);
            return;
        }
        
        HashMapNode* prev = new HashMapNode(0, 0);
        prev->next = buck;
        
        while (buck != NULL) {
            if (buck->key == key) {
                buck->value = value;
                return;
            }
            prev = buck;
            buck = buck->next;
        }
        
        prev->next = new HashMapNode(key, value);
    }
    
    int get(int key) {
        int index = hash(key);
        HashMapNode* buck = bucks[index];
        
        while (buck != NULL) {
            if (buck->key == key) {
                return buck->value;
            }
            buck = buck->next;
        }
        
        return -1;
    }
    
    void remove(int key) {
        int index = hash(key);
        HashMapNode* buck = bucks[index];
        
        if (buck == NULL) return;
        
        if (buck->key == key) {
            bucks[index] = buck->next;
            return;
        }
        
        HashMapNode* prev = new HashMapNode(0, 0);
        prev->next = buck;
        
        while (buck != NULL) {
            if (buck->key == key) {
                prev->next = buck->next;
            }
            prev = buck;
            buck = buck->next;
        }
    }
    
    int hash(int key) {
        return key % BUCK_SIZE;
    }
};