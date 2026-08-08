#ifndef SINGLETON_HPP
#define SINGLETON_HPP


template <typename T>
class Singleton
{
protected:
    Singleton() {}
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    virtual ~Singleton() {}
    static T* GetInstance();
};

template <typename T>
T* Singleton<T>::GetInstance()
{
    static T m_instance;
    return &m_instance;
}

template <typename T>
Singleton<T>::Singleton(const Singleton&)
{
}

template <typename T>
Singleton<T>& Singleton<T>::operator=(const Singleton&)
{
    return *this;
}


#endif
