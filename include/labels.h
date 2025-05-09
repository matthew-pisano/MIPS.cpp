//
// Created by matthew on 4/26/25.
//

#ifndef LABELS_H
#define LABELS_H

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "tokenizer.h"

/**
 * Class to manage the mapping of labels to memory locations
 */
class LabelMap {
    /**
     * A map between the names of labels and their associated memory addresses
     */
    std::map<std::string, uint32_t> labelMap;

public:
    /**
     * Modifies instruction arguments to replace label references with labeled memory locations
     * @param instructionArgs The instruction arguments to modify
     * @throw runtime_error When one of the arguments references an unknown label
     */
    void resolveLabels(std::vector<Token>& instructionArgs);

    /**
     * Populates the label map prior to processing using static allocations for the given tokens
     * @param tokens The program tokens
     * @throw runtime_error When a duplicate label definition is detected
     */
    void populateLabelMap(const std::vector<std::vector<Token>>& tokens);
};

#endif // LABELS_H
