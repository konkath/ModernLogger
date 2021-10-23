#ifndef MICHAULOGGER_LOGGER_H
#define MICHAULOGGER_LOGGER_H

#include <format>
#include <iomanip>
#include <iostream>
#include <ostream>
#include <source_location>

enum Verbosity {
    DEBUG,
    INFO,
    ERROR,
};

class Logger final {
public:
    static Logger ERR(const std::source_location &location = std::source_location::current());

    static Logger NFO(const std::source_location &location = std::source_location::current());

    static Logger DBG(const std::source_location &location = std::source_location::current());

    Logger &operator=(Logger &) = delete;

    Logger(Logger &) = delete;

    Logger(Logger &&) = delete;

    ~Logger();

    template<typename T>
    Logger &operator<<(const T value) {
        if (!isLoggingEnabled()) {
            return *this;
        }

        (*this).stream << value;
        return *this;
    }

    Logger &operator<<(std::ostream &(*os)(std::ostream &));

    static void SetDynamicDebug(bool dynDebug);

private:
    explicit Logger(Verbosity verbosity, const std::source_location &location) noexcept;

    static std::string getShortFileName(const char *fileName);

    [[nodiscard]] bool isLoggingEnabled() const;

    [[nodiscard]] std::ostream &getStreamType() const;

    [[nodiscard]] std::string getStreamName() const;

    bool hasEndl;
    Verbosity verbosity;
    std::ostream &stream;

    static bool dynamic_debug;
};


#endif //MICHAULOGGER_LOGGER_H
