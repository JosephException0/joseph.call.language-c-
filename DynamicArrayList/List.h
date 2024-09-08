#ifndef LIST_H
#define LIST_H

class List {
public: 
    virtual void add(int n) = 0;
    virtual int remove(int n) = 0;
    virtual void print() const = 0;  // Changed to const
    virtual ~List() {} // Virtual destructor
};

#endif // LIST_H
