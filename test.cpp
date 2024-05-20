#include <iostream>
#include <sstream>
#include "Singleton.h"

void testInstanceNotNull() {
    Singleton* instance = Singleton::getInstance();
    if (instance != nullptr) {
        std::cout << "testInstanceNotNull passed" << std::endl;
    } else {
        std::cerr << "testInstanceNotNull failed" << std::endl;
    }
}

void testSameInstance() {
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    if (instance1 == instance2) {
        std::cout << "testSameInstance passed" << std::endl;
    } else {
        std::cerr << "testSameInstance failed" << std::endl;
    }
}

void testPerformTask() {
    Singleton* instance = Singleton::getInstance();
    std::streambuf* originalCoutBuffer = std::cout.rdbuf();
    std::ostringstream capturedOutput;
    std::cout.rdbuf(capturedOutput.rdbuf());

    instance->performTask();

    std::cout.rdbuf(originalCoutBuffer);
    if (capturedOutput.str() == "Performing some task\n") {
        std::cout << "testPerformTask passed" << std::endl;
    } else {
        std::cerr << "testPerformTask failed" << std::endl;
    }
}

void testResetInstance() {
    Singleton* instance1 = Singleton::getInstance();
    instance1->reset();
    Singleton* instance2 = Singleton::getInstance();
    if (instance1 != instance2) {
        std::cout << "testResetInstance passed" << std::endl;
    } else {
        std::cerr << "testResetInstance failed" << std::endl;
    }
}

int main() {
    testInstanceNotNull();
    testSameInstance();
    testPerformTask();
    testResetInstance();
    return 0;
}
