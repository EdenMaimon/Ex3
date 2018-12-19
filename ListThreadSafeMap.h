//
// Created by eden on 12/18/18.
//

#ifndef EX3_LISTTHREADSAFEMAP_H
#define EX3_LISTTHREADSAFEMAP_H

#include <bits/allocator.h>
#include <map>
#include <memory>
#include <mutex>
#include <list>

template<typename K, typename Container,typename V>
class ListThreadSafeMap {

private:
    // a shared pointer of the map
    std::shared_ptr<std::map<K, Container>> m_map;
    //a shared pointer of the mutex
    std::shared_ptr<std::mutex> m_mutex;

public:
    /**
     * constructor that initializes the map and mutex
     */
    ListThreadSafeMap() {
        this->m_map = std::make_shared<std::map<K, Container>>();
        this->m_mutex = std::make_shared<std::mutex>();
    }

    void setKeyValue(const K &k, const V& v);


    Container getValue(const K &k);


};
1
template<typename K, typename Container,typename V>
void ListThreadSafeMap<K, Container, V>::setKeyValue(const K &k, const V &v) {

    std::lock_guard<std::mutex> guard(*this->m_mutex);
    (*this->m_map)[k].push_back(v);
}

template<typename K, typename Container, typename V>
Container ListThreadSafeMap<K, Container, V>::getValue(const K &k) {
    std::lock_guard<std::mutex> guard(*this->m_mutex);

    return (*this->m_map)[k];
}


#endif //EX3_LISTTHREADSAFEMAP_H
