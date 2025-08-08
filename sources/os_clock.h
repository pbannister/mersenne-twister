#pragma once
#include <time.h>
#include <stdint.h>

//
//  Base time uses nanosecond resolution on REALTIME clock.
//

namespace os_clock {

typedef uint64_t timed_ns_t;
typedef uint64_t timed_us_t;
typedef uint64_t timed_ms_t;

enum CONSTANTS {
    NS_PER_SECOND = 1000000000
};

inline timed_ns_t time_get() {
    struct timespec ts;
    ::clock_gettime(CLOCK_REALTIME, &ts);
    timed_ns_t t = ts.tv_sec;
    return (NS_PER_SECOND * t) + ts.tv_nsec;
}

inline timed_ns_t ns_from_us(timed_us_t v) {
    return 1000 * v;
}
inline timed_ns_t ns_from_ms(timed_ms_t v) {
    return ns_from_us(1000 * v);
}
inline timed_us_t us_from_ns(timed_ns_t v) {
    return v / 1000;
}
inline timed_ms_t ms_from_ns(timed_ns_t v) {
    return us_from_ns(v) / 1000;
}

inline bool sleep_ns(timed_ns_t ns) {
    timespec ts;
    ts.tv_nsec = ns % NS_PER_SECOND;
    ts.tv_sec = ns / NS_PER_SECOND;
    return 0 == ::clock_nanosleep(CLOCK_REALTIME, 0, &ts, 0);
}
inline bool sleep_us(timed_us_t us) {
    return sleep_ns(us * 1000);
}
inline bool sleep_ms(timed_ms_t ms) {
    return sleep_us(ms * 1000);
}

}  // namespace os_clock
