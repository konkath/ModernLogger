#include "Logger.h"

bool Logger::dynamic_debug = false;

Logger Logger::ERR(const std::source_location &location) {
    return Logger(ERROR, location);
}

Logger Logger::NFO(const std::source_location &location) {
    return Logger(INFO, location);
}

Logger Logger::DBG(const std::source_location &location) {
    return Logger(DEBUG, location);
}

Logger::~Logger() {
    if (isLoggingEnabled() && !hasEndl) {
        stream << std::endl;
    }
}

Logger &Logger::operator<<(std::ostream &(*os)(std::ostream &)) {
    if (!isLoggingEnabled()) {
        return *this;
    }

    if (os == (std::basic_ostream<char> &(*)(std::basic_ostream<char> &)) &std::endl) {
        hasEndl = true;
    }
    (*this).stream << os;
    return *this;
}

void Logger::SetDynamicDebug(bool dynDebug) {
    dynamic_debug = dynDebug;
}

Logger::Logger(Verbosity verbosity, const std::source_location &location) noexcept:
        verbosity(verbosity), stream(getStreamType()), hasEndl(false) {
    if (!isLoggingEnabled()) {
        return;
    }

    stream << std::format("{:10.10} - {:10.10}: {:5d} [{:3.3}] | ",
                          getShortFileName(location.file_name()),
                          location.function_name(),
                          location.line(),
                          getStreamName());
}

std::string Logger::getShortFileName(const char *fileName) {
    std::string str(fileName);
    std::size_t iter = str.find_last_of("/\\");
    return str.substr(iter + 1);
}

bool Logger::isLoggingEnabled() const {
    return verbosity != DEBUG || dynamic_debug;
}

std::ostream &Logger::getStreamType() const {
    switch (verbosity) {
        case ERROR:
            return std::cerr;
        case INFO:
        case DEBUG:
            return std::cout;
    }
    return std::cout;
}

std::string Logger::getStreamName() const {
    switch (verbosity) {
        case DEBUG :
            return "DBG";
        case INFO:
            return "NFO";
        case ERROR:
            return "ERR";
    }
    return "NAN";
}
