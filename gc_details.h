// This class defines an element that is stored
// in the garbage collection information list.
template <class T>
class PtrDetails
{
  public:
    unsigned refcount;
    T *memPtr;
    bool isArray; 
    unsigned arraySize;

    PtrDetails(void) {
        this->memPtr = nullptr;
        this->isArray = false;
        this->arraySize = 0;
        this->refcount = 0;
    }

    PtrDetails(T* ptr, int arraySize = 0) {
        this->memPtr = ptr;
        this->isArray = arraySize > 0;
        this->arraySize = arraySize;
        this->refcount = 1;
    }

    void addReference();
    void reduceReference();
};

// Overloading operator== allows two class objects to be compared.
// This is needed by the STL list class.
template <class T>
bool operator==(const PtrDetails<T> &ob1,
                const PtrDetails<T> &ob2)
{
    return ((ob1.memPtr == ob2.memPtr) & (ob1.isArray == ob2.isArray));
}

template <class T>
void PtrDetails<T>::addReference() {
    this->refcount += 1;
}

template <class T>
void PtrDetails<T>::reduceReference() {
    this->refcount -= 1;
}