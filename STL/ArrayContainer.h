#ifndef ARRAYCONTAINER_H
#define ARRAYCONTAINER_H

#include <iostream>
#include <stdexcept>
#include "MyIterator.h"

template <typename T, size_t Size>
class ArrayContainer {
public:
    using Iterator = MyIterator<T>;

    ArrayContainer() = default;

    // Construtor com valores iniciais
    ArrayContainer(const T& defaultValue) {
        for (size_t i = 0; i < Size; ++i) {
            m_Data[i] = defaultValue;
        }
    }

    // Função para acessar elementos com verificação de limites
    T& at(size_t index) {
        if (index >= Size) {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[index];
    }

    // Função const para acessar elementos
    const T& at(size_t index) const {
        if (index >= Size) {
            throw std::out_of_range("Index out of range");
        }
        return m_Data[index];
    }

    // Operador [] (sem verificação de limites)
    T& operator[](size_t index) {
        return m_Data[index];
    }

    const T& operator[](size_t index) const {
        return m_Data[index];
    }

    // Função para obter o tamanho do array
    constexpr size_t size() const {
        return Size;
    }

    // Função para preencher o array com um valor
    void fill(const T& value) {
        for (size_t i = 0; i < Size; ++i) {
            m_Data[i] = value;
        }
    }

    Iterator begin(){
        return Iterator(&m_Data[0]);
    }

    Iterator end(){
        return Iterator(&m_Data[Size]);
    }



private:
    T m_Data[Size]; // Array interno
};


#endif