#include<iostream>
#include<list>
#include<utility>
#include<unordered_map>
using namespace std;

// Brute Force Method
// class LRUCache {
// public:
//     vector<pair<int, int>> cache;
//     int n;

//     LRUCache(int capacity) {
//         n = capacity;
//     }

//     int get(int key) {
//         for(int i = 0; i < cache.size(); i++) {
//             if(cache[i].first == key) {
//                 int val = cache[i].second;

//                 pair<int, int> temp = cache[i];
//                 cache.erase(cache.begin() + i);
//                 cache.push_back(temp);

//                 return val;
//             }
//         }

//         return -1;
//     }

//     void put(int key, int val) {
//         for(int i = 0; i < cache.size(); i++) {
//             if(cache[i].first == key) {
//                 cache.erase(cache.begin() + i);
//                 cache.push_back({key, val});
//                 return;
//             }
//         }

//         if(cache.size() == n) {
//             cache.erase(cache.begin());
//             cache.push_back({key, val});
//         } else {
//             cache.push_back({key, val});
//         }
        
//     }
// };

class LRUCache {
public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> mp;
    int cap;

    LRUCache(int capacity) {
        cap = capacity;
    }

    void makeRecentlyUsed(int key) {
        dll.erase(mp[key].first);

        dll.push_front(key);

        mp[key].first = dll.begin();
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }

        makeRecentlyUsed(key);

        return mp[key].second;
    }

    void put(int key, int val) {
        if(mp.find(key) != mp.end()) {

            // present in map
            mp[key].second = val;
            makeRecentlyUsed(key);
        } else {
            
            // not present in map
            dll.push_front(key);
            mp[key] = {dll.begin(), val};
            cap--;
        }

        // overflow condition
        if(cap < 0) {
            int deleteKey = dll.back();
            mp.erase(deleteKey);
            dll.pop_back();

            cap++;
        }
    }
};

int main() {
    return 0;
}