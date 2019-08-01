#include "gtci.h"
#include <chrono>
#include <random>

std::string tab(gtci::interface& io, const std::string& current)
{
    io.printLn("Tab was pressed at: \"" + current + "\".");
    return current + current;
}

uint32_t mtrand(uint32_t lo, uint32_t hi)
{
    static std::mt19937 mt;
    static bool seeded = false;
    if (!seeded)
    {
        std::random_device rd;
        std::vector<uint32_t> seed;
        for (int i = 64;i;--i)
            seed.push_back(rd());
        std::seed_seq seeq (seed.begin(),seed.end());
        mt.seed(seeq);
        seeded = true;
    }
    uint32_t r;
    if (lo >= hi)
        r = lo;
    else
        r = (std::uniform_int_distribution<uint32_t>(lo,hi))(mt);
    return r;
}

std::string randString()
{
    std::string out;
    for (size_t length = mtrand(15,200), i = 0;i < length;++i)
        out.append(1,(char)mtrand(33,126));
    return out;
}

int main()
{
    gtci::interface io(&tab);
    std::thread outThread ([&io]
    {
        while (true)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(mtrand(0,10000)));
            io.printLn("[OUT]: " + randString());
        }
    });
    std::string input;
    while (io.getline(input))
        io.printLn("Input: " + input);
    outThread.join();
    return 0;
}

