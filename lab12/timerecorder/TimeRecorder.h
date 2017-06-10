//
// Created by mateusz on 4.06.17.
//

#ifndef JIMP_EXERCISES_TIMERECORDER_H
#define JIMP_EXERCISES_TIMERECORDER_H
#include <map>
#include <chrono>

namespace profiling {
    template<typename T>
    auto TimeRecorder(T t) {
        typedef std::chrono::high_resolution_clock clock;
        typedef std::chrono::duration<double, std::milli> duration;
        static clock::time_point begin = clock::now();
        auto result = (t)();
        duration elapsed = clock::now() - begin;
        return std::pair<decltype(result), double>(result, elapsed.count());
    };
}


#endif //JIMP_EXERCISES_TIMERECORDER_H
