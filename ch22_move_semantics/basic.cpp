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
    btecSmartPointer(const btecSmartPointer& other) = delete;             // delete copy constructor
    btecSmartPointer& operator=(const btecSmartPointer& other) = delete;  // delete copy assignment
    btecSmartPointer(btecSmartPointer&& other) noexcept : m_ptr(other.m_ptr) {  // move  constructor
        other.m_ptr = nullptr;
    }
    btecSmartPointer& operator=(btecSmartPointer&& other) noexcept {  // move assignment
        if (this == &other) {
            return *this;
        }
        delete m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() { return m_ptr == nullptr; }
};

class Resource {
   public:
    Resource() { std::cout << "Acquired\n"; }
    ~Resource() { std::cout << "Destroyed\n"; }
};

int main() {
    btecSmartPointer<Resource> res1 = new Resource();
    btecSmartPointer<Resource> res2;

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");

    res2 = std::move(res1);

    std::cout << "res1 is " << (res1.isNull() ? "null\n" : "not null\n");
    std::cout << "res2 is " << (res2.isNull() ? "null\n" : "not null\n");
    return 0;
}