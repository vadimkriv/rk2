#include<atomic>
#include <mutex>
#include <iostream>
class Singleton
{
public:
    static Singleton *getInstance();
    void performTask() const;
    void reset();

    // Delete the copy constructor and assingment operator
    Singleton(const Singleton &singleton) = delete;
    Singleton &operator = (const Singleton &singleton) = delete;

private:
    Singleton(){}
    static std::atomic<Singleton *>instance;
    static std::mutex mutex;
};




std::atomic<Singleton *>Singleton::instance {nullptr};
std::mutex Singleton::mutex;

Singleton *Singleton::getInstance()
{
    if(!instance)
    {
        std::lock_guard<std::mutex> lock(mutex);
        if (!instance)
        {
            instance = new Singleton();
        }
    }
    return instance;
}

void Singleton::performTask() const
{
    std::cout << "Performing some task" << std::endl;
}

void Singleton::reset()
{
    Singleton *value = instance.load();
    delete value;
    instance = nullptr;
}


int main()
{
    Singleton* singleton = Singleton::getInstance();
    singleton->performTask();
    singleton->reset();
    singleton = Singleton::getInstance();
    singleton->performTask();

    return 0;
}
