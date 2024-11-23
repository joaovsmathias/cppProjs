#include <iostream>
#include <string>

using namespace std;
/* 
class String
{
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }
    
    ~String()
    {
        printf("Destroyed!\n");
        delete[] m_Data;
    }
    void Print()
    {
        for(uint32_t i = 0; i < m_Size; i++){
            printf("%c", m_Data[i]);
        }
        printf("\n");
    }

private:
    char* m_Data;
    uint32_t m_Size;

};


class Entity
{
public:
    Entity(const String& name)
        :m_name(name)
    {}

    Entity(String&& name)
        :m_name(move(name))
    {}

    void printName()
    {
        m_name.Print();
    }

private:
    String m_name;

};

testes->>
    Entity entity("John");
    entity.printName();
testes->>
 
namespace MyNamespace {
    class MyClass {
    public:
        int value;
    };

    std::ostream& operator<<(std::ostream& os, const MyClass& obj) {
        os << "MyClass: " << obj.value;
        return os;
    }
}


*/


#ifdef DEBUG_MODE
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x);
#endif

int main() 
{
    LOG("OLa mundo!");

    std::cin.get();


}
