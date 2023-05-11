#pragma once

#include <libtorrent/random.hpp>

#include <vector>
#include <iostream>

class LibtorrentNodeRandom
{
private:
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

    void printVec(std::vector<int> &vec);

public:
    void shuffle();
};