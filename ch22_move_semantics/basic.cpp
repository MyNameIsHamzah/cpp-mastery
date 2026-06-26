#include <iostream>

void func() {
    int* ptr = new int{5};
    if (*ptr == 0)
        return;  // int 5 will be stranded in heap if this hits. how can we delete this if this
                 // condition hits? smart pointers.
    delete ptr;
}

template <typename T>
class btecSmartPointer {
   private:
    T* m_ptr{};

   public:
    btecSmartPointer(T* ptr = nullptr) : m_ptr(ptr) {};
    ~btecSmartPointer() { delete m_ptr; }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};

class Resource {
   public:
    Resource() { std::cout << "Acquired\n"; }
    ~Resource() { std::cout << "Destroyed\n"; }
};

int main() {
    btecSmartPointer<Resource> res = new Resource();
    return 0;
}