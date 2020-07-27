class Object;
class SmartPointer;
class Counter{
    friend class SmartPointer;
public:
    Counter(){
        ptr = NULL;
        cnt = 0;
    }
    Counter(Object* p){
        ptr = p;
        cnt = 1;
    }
    ~Counter()
    {
        delete ptr;
    }
private:
    Object* ptr;
    int cnt;
}
class SmartPointer
{
public:
    SmartPointer(Object* p){
        ptr_counter = new Counter(p);
    }
    SmartPointer(const SmartPointer &sp){
        ptr_counter = sp.ptr_counter;
        ++ptr_count->cnt;
    }
    SmartPointer& operator=(const SmartPointer &sp){
        ++sp.ptr_counter->cnt;
        --ptr_counter->cnt;
        if(ptr_counter->cnt == 0){
            delete ptr_counter;
        }
        ptr_counter  = sp.ptr_counter;
    }
    ~SmartPointer()
    {
        --ptr_counter->cnt;
        if(ptr_counter->cnt == 0){
            delete ptr_counter;
        }
    }
private: 
    Counter* ptr_counter;
}

///////////////////////////////////////////////////////////////////////////

template<typename SmartPointer,typename Type>
class PtrCount{
    friend SmartPointer;
    PtrCount(Type* _p):p(_p),use(1){};
    ~PtrCount(){delete p;}
    Type *p;
    size_t use;
}
template<typename Type>
class SmartPtr{
public:
    SmartPtr(Type *p):ptrCnt(new PtrCount<SmartPtr,Type>(p)){};
    SmartPtr(const SmartPtr& orig):ptrCnt(orig.ptrCnt){
        ++ptrCnt->use;
    }
    SmartPtr& operator=(const SmartPtr& rhs){
        ++rhs.ptrCnt->use;
        if(--ptrCnt->use == 0)
            delete ptrCnt;
        ptrCnt = rhs.ptrCnt;
        return *this;
    }
    ~SmartPtr(){
        if(--ptrCnt->use == 0)
            delete ptrCnt;
    }
private:
    PtrCount<SmartPtr,Type> *ptrCnt;
}