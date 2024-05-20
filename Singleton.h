#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <atomic>
#include <mutex>

class Singleton
{
public:
    static Singleton *getInstance();
    void performTask() const;
    void reset();

    // Удаляем конструктор копирования и оператор присваивания
    Singleton(const Singleton &singleton) = delete;
    Singleton &operator = (const Singleton &singleton) = delete;

private:
    Singleton() {}
    static std::atomic<Singleton *> instance;
    static std::mutex mutex;
};

#endif // SINGLETON_H
