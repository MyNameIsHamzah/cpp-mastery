#pragma once
#include <chrono>

class Timer {
   private:
    using Clock = std::chrono::steady_clock;
    using Microsecond = std::chrono::nanoseconds;

    std::chrono::steady_clock::time_point m_start;

   public:
    Timer() : m_start(std::chrono::steady_clock::now()) {}

    void reset() { m_start = std::chrono::steady_clock::now(); }

    long long nanoseconds() const {
        auto end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - m_start).count();
    };
};