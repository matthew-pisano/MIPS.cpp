//
// Created by matthew on 4/15/25.
//

#include "register.h"

#include <stdexcept>


int RegisterFile::indexFromName(const std::string& name) {
    if (!nameToIndex.contains(name))
        throw std::runtime_error("Unknown register " + name);

    return static_cast<int>(nameToIndex[name]);
}


int32_t RegisterFile::operator[](const uint32_t index) const { return registers[index]; }
int32_t& RegisterFile::operator[](const uint32_t index) {
    if (index >= 32)
        throw std::runtime_error("Register index out of bounds: " + std::to_string(index));
    return registers[index];
}

int32_t RegisterFile::operator[](const Register index) const {
    return registers[static_cast<int>(index)];
}
int32_t& RegisterFile::operator[](const Register index) {
    return registers[static_cast<int>(index)];
}
