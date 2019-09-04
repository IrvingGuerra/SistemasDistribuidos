#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <mutex>
#include <condition_variable>

class Semaforo
{
private:
    std::mutex mutex_;
    std::condition_variable condition_;
    unsigned long count_;

public:
    Semaforo(unsigned long = 0);
    void post();
    void wait();
    void init(unsigned long);
};

#endif