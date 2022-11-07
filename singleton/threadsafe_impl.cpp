#include <iostream>
#include <mutex>
#include <future>

using namespace std;
std::mutex m;

class S{
public:
    static S& getInstance() {
        std::lock_guard<std::mutex> mylock(m);
        if (s == nullptr)
            s = new S();
        return *s;
    }
private:
    S() = default;
    ~S() = default;
    S(const S&) = delete;
    S& operator=(const S&) = delete;
    static S *s;
};

S* S::s = nullptr;

void Instance() {
    S::getInstance();
}

int main()
{
    auto f1 = std::async(std::launch::async, Instance);
    auto f2 = std::async(std::launch::async, Instance);
    auto f3 = std::async(std::launch::async, Instance);
    
    f1.get();
    f2.get();
    f3.get();

    return 0;
}
