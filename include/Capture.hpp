#ifndef CAPTURE_HPP
#define CAPTURE_HPP
#include <string>

class Capture
{
    public:
        Capture(std::string a);
        int getCap();
    private:
        std::string count;
};

#endif
