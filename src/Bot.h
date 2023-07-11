//
// Created by tommy31 on 10.07.23.
//


#ifndef RATHAUS_BOT_H
#define RATHAUS_BOT_H


#pragma once

#include <iostream>
#include <dpp/dpp.h>

class Bot {
private:
    std::string token;
    int shards = 1;
    int interaction_delay = 0;
    void handleSlashCommand();
public:
    explicit Bot(const std::string& token);
    [[maybe_unused]] void setInteractionDelay(int delay);
    [[maybe_unused]] void setShards(int shards);
    void run(int delay);
};


#endif //RATHAUS_BOT_H
