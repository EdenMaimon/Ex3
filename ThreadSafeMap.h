//
// Created by eden on 12/18/18.
//

#ifndef EX3_THREADSAFEMAP_H
#define EX3_THREADSAFEMAP_H
#include <map>
#include <memory>
#include <mutex>
#include <iterator>
using namespace std;

template<typename K, typename V>

/**
 * This class handles a map that can be safely used in multithreading
 * @tparam K the key type of the map
 * @tparam V the value type of the map
 */
class ThreadSafeMap {

private:
    // a shared pointer of the map
    shared_ptr<map<K,V>> m_map;
    //a shared pointer of the mutex
    shared_ptr<mutex> m_mutex;

public:
    /**
     * constructor that initializes the map and mutex
     */
    ThreadSafeMap() {
        this->m_map = std::make_shared<map<K,V>>();
        this->m_mutex = std::make_shared<mutex>();
    }

     void setKeyValue(const K& k, const V& v);
     V getValue(const K& k);
     V findKeyForValue(const K& k);

};

/**
 * Safely sets a value
 * @tparam K the key type
 * @tparam V the value type
 * @param k the key whose value is to be set
 * @param v the new value
 */
template<typename K, typename V>
void ThreadSafeMap<K, V>::setKeyValue(const K& k, const V& v){
    //lock the map to the thread and open it after finish
    lock_guard<mutex> guard(*this->m_mutex);
    (*this->m_map)[k] = v;
}
/**
 * Get a value of the map safely.
 */
template<typename K, typename V>
V ThreadSafeMap<K, V>::getValue(const K& k) {
    lock_guard<mutex> guard(*this->m_mutex);
    return (*this->m_map)[k];
}

/**
 * Rerutns the key that hold the value
 * @tparam K
 * @tparam V
 * @param k
 * @return
 */
template<typename K, typename V>
V ThreadSafeMap<K, V>::findKeyForValue(const K &k) {
    lock_guard<mutex> guard(*this->m_mutex);






}


#endif //EX3_THREADSAFEMAP_H
