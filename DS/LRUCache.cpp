#include <iostream>
#include <unordered_map>

class LRUCache{

    private:
        struct Node{
            int data;
            int key;
            Node *next;
            Node *prev;

            Node(int k, int val){
                key = k;
                data = val;
                prev = nullptr;
                next = nullptr;
            }
        };

        std::unordered_map<int, Node*> cache;    
        int capacity;
        Node *front;
        Node *rear;

    public:
        LRUCache(int capacity);
        ~LRUCache();
        void put(int key, int value);
        int get(int key);
};

LRUCache::LRUCache(int capacity){
    this->capacity = capacity;
}

LRUCache::~LRUCache(){

}

int LRUCache::get(int keyI){


}

void LRUCache::put(int keyI, int valI){
    if (cache.size() < capacity){

    }
    else {
        Node *lruNode = rear->prev;
        removeLRUNode(prev);
        cache.erase(prev->key)

    }
}
