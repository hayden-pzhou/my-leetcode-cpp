#ifndef __UTILS_MY_CLOCK__
#define __UTILS_MY_CLOCK__

#include <chrono>
#include <ratio>
#include <cstdio>
#include <string>
#include <iomanip>
#include <string>

#define DEBUG

using std::string;

using MY_NS = std::nano;
using MY_US = std::micro;
using MY_MS = std::milli;
using MY_SEC = std::ratio<1, 1>;
using MY_TP = std::chrono::system_clock::time_point;

inline MY_TP MyGetTimestampNow() {
    return std::chrono::system_clock::now();
}

/**
 * @brief To calculate function executation time
 *
 * put `MyClock<DESIRED_UNIT> myClock;` at a function begining, executation time
 * will be printed in DESIRED_UNIT after function executated.
 * MY_NS means in nanosecond
 * MY_US means in microsecond
 * MY_MS means in millisecond
 * MY_SEC means in second
 */

template<typename T>
class MyClock {
public:
    explicit MyClock(string name = "none") {
        mName =  name;
        printf("Entering function (%s)...\n", mName.c_str());
        mStartPoint = MyGetTimestampNow();
    }

    ~MyClock() {
        mEndPoint = MyGetTimestampNow();
        //auto mDuration = std::chrono::duration_cast<T>(mEndPoint - mStartPoint);
        std::chrono::duration<double, T> duration = mEndPoint - mStartPoint;
        printf("Exiting function (%s)... %f %s elapsed\n", mName.c_str(), duration.count(), getUnitStr());
    }

private:
    const char* getUnitStr() const {
        if (std::is_same<T, MY_NS>::value) return "ns";
        else if (std::is_same<T, MY_US>::value) return "us";
        else if (std::is_same<T, MY_MS>::value) return "ms";
        else if (std::is_same<T, MY_SEC>::value) return "s";
        else return "?";
    }

    MY_TP mStartPoint;
    MY_TP mEndPoint;

    string mName;
};

#endif // __UTILS_MY_CLOCK__
