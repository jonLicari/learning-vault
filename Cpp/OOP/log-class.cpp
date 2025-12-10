#include <iostream>
#include <string>

enum LogLevel {
    DEBUG = 0,
    WARN = 1,
    ERROR = 2
};

class Log {
    int logLevel_ = DEBUG;

public:    
    void setLevel(LogLevel level) {
        logLevel_ = level;
    }

    void debug(std::string m) const {
        if (logLevel_ <= DEBUG) log("DEBUG: ", m);
    }
    void warn(std::string m) const {
        if (logLevel_ <= WARN) log("WARN: ", m);
    }
    void error(std::string m) const {
        if (logLevel_ <= ERROR) log("ERROR: ", m);
    }

private:
    void log(std::string prefix, std::string message) const {
        std::cout << prefix << message << std::endl;
    }
};

int main() {    
    Log log;

    log.debug("DA BUG!"); // should print 
    
    log.setLevel(WARN);
    log.debug("DA BUG AGAIN!"); // should NOT print
    log.warn("THICC WARNING INCOMING"); // should print
    
    log.setLevel(ERROR);
    log.warn("THICCER WARNING INCOMING"); // should NOT print
    log.error("THICC ERROR INCOMING"); // should print

    return 0;
}