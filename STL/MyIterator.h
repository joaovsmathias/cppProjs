#ifndef MYITERATOR_H
#define MYITERATOR_H


template <typename T>
class MyIterator{
public:
    MyIterator()=default;
    MyIterator(T* ptr) : m_Ptr(ptr) {}
    //operadores agora
    //*
    T operator*(){
        return *m_Ptr;
    }
    
    //!=
    bool operator!=(const MyIterator<T>& it) {
        if(it.m_Ptr != m_Ptr)return true;
        else return false;
    }

    //++
    void operator++() {
        m_Ptr++;
    }

    //<<
    friend std::ostream& operator<<(std::ostream& os, const MyIterator<T>& it) {
        
        os << it.m_Ptr ;

        return os;
    }
    friend std::ostream& operator<<(std::ostream& os, const T it) {
        
        os << it ;

        return os;
    }
    
    

private:
    T* m_Ptr;

};

#endif