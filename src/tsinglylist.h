#ifndef TSINGLYLIST_H
#define TSINGLYLIST_H

#include "thazardptr.h"
#include "thazardobject.h"


template <class T> class TSinglyList
{
public:
    const T value(const Key &key, const T &defaultValue = T()) const;
    void insert(const QString &key, const T &value);
    int remove(const QString &key);
    T take(const QString &key);

private
    struct Node : public THazardObject
    {
        QString key;
        T value;
        TAtomicPtr<Node> next {nullptr};

        Node(const QString &k, const T &v) : key(k), value(v) { }
    };

    TAtomicPtr<Node> head {nullptr};
    static thread_local THazardPtr hzptr;
};



template <class T>
inline const T TSinglyList<T>::value(const Key &key, const T &defaultValue) const
{

}


template <class T>
inline void TSinglyList<T>::insert(const QString &key, const T &value)
{
    auto *pnode = new Node(key, value);
    do {
        auto oldp = head.load();
        pnode->next.store(oldp);
    } while (!head.compareExchange(oldp, pnode));
}


template <class T>
inline int TSinglyList<T>::remove(const QString &key)
{

}


template <class T>
inline T TSinglyList<T>::take(const QString &key)
{

}

#endif // TSINGLYLIST_H
