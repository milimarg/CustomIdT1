/*
** EPITECH PROJECT, 2024
** CustomIdT1
** File description:
** Pair.hpp
*/

#ifndef CUSTOMIDT1_PAIR_HPP
    #define CUSTOMIDT1_PAIR_HPP
    #include <iostream>

namespace std {
    template <>
    struct hash<std::pair<int, int>> {
        size_t operator()(const std::pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
}

#endif //CUSTOMIDT1_PAIR_HPP
