#ifndef _SMARTPOINTER_H_
#define _SMARTPOINTER_H_

namespace DTLib
{
template <typename T>
class SmartPointer
{
protected:
    T* m_pointer;

public:
    SmartPointer(T* p = NULL)
    {
        m_pointer = p;
    }

    SmartPointer(const SmartPointer<T>& obj)
    {
        m_pointer = obj.m_pointer;

        obj.m_pointer = NULL;
    }

    T* operator-> ()
    {
        return m_pointer;
    }

    T& operator* ()
    {
        return *m_pointer;
    }

    bool isNull()
    {
        return (m_pointer == NULL);
    }

    T* get()
    {
        return m_pointer;
    }

    ~SmartPointer
    {
        delete m_pointer;
    }
};
}

#endif // _SMARTPOINTER_H_
