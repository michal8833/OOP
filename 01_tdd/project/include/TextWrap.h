#pragma once

#include <string>

class TextWrap {
public:

    explicit TextWrap(int columns = 10);

    int getColumns() const;

    std::string wrap(const std::string& string) const;

private:
    int columns;

    static bool containSpace(const std::string& string);
};