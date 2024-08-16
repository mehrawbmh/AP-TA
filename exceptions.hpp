#ifndef MODELSIM_EXCEPTIONS_HPP
#define MODELSIM_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

class BadInputException : public std::exception {
private:
    std::string message;
public:
    BadInputException(const std::string& msg) : message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

class NotFoundExcpetion: public std::exception {
private:
    std::string message;
public:
    NotFoundExcpetion(const std::string &msg): message(msg) {}
    virtual const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
