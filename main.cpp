#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <future>
#include <chrono>
#include "ThreadPool.h"


int main() {
    ThreadPool pool(4);
    std::vector<std::future<int>> futures;
    for (int i = 0; i < 10; ++i) {
        futures.emplace_back(pool.enqueue([i]() {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            return i * i;
        }));
    }
    for (auto& f : futures) {
        std::cout << f.get() << std::endl;
    }
    std::cout << "Done" << std::endl;
    // join all threads in the pool
    // pool.join(); // this is not needed, destructor calls it automatically

    // pool.~ThreadPool(); // destructor is called automatically at the end of main()

    return 0;
}