#include "../include/TextWrap.h"

TextWrap::TextWrap(int columns) : columns(columns) {}

int TextWrap::getColumns() const {
    return columns;
}

bool TextWrap::containSpace(const std::string& string) {
    for(char c : string) {
        if(c == ' ') return true;
    }

    return false;
}

std::string TextWrap::wrap(const std::string& line) const {

    std::string res;

    unsigned int i = 0;

    if(line.size() == 1) return line;

    while(i < line.size()) {
        if(i!=0)
            res += "\n";
        if(i+columns >= line.size()) {
            if(line[i] == ' ')
                res += line.substr(i+1);
            else
                res += line.substr(i);
            i=line.size();
        }
        else {
            unsigned c;
            std::string sub = line.substr(i, columns);

            if(sub == " " || sub[0] == ' ') {
                i++;
                sub = line.substr(i, columns);
            }

            if((containSpace(sub) && sub[sub.size()-1] != ' ' && line[i + sub.size()] != ' ') || (containSpace(sub) && sub[sub.size()-1] == ' ')) {
                for(c=sub.size()-1;c>0;c--) {
                    if(sub[c] == ' ') {
                        if(sub[0] == ' ' && sub[sub.size()-1] == ' ')
                            res += line.substr(i+1, c-1);
                        else if(sub[0] == ' ')
                            res += line.substr(i+1, c);
                        else
                            res += line.substr(i, c);
                        i += c+1;
                        break;
                    }
                }
            }
            else {
                res += sub;
                i += columns;
            }
        }
    }


    return res;
}
