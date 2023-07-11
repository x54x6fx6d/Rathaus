//
// Created by tommy31 on 10.07.23.
//


#include "Bot.h"

// Files
#include "util.h"

// Libs
#include <chrono>
#include <thread>
#include <dpp/dpp.h>

Bot::Bot(const std::string& token) {
    this->token = token;
}

[[maybe_unused]] void Bot::setInteractionDelay(int delay) {
    this->interaction_delay = delay;
}


void Bot::run([[maybe_unused]]int delay) {
    if (delay != 0){
        std::this_thread::sleep_for(std::chrono::seconds(delay));
    }
    dpp::cluster client(this->token, dpp::intents::i_all_intents, this->shards);
    client.on_ready([&] (const dpp::ready_t& event) {
        client.set_presence(dpp::presence(dpp::ps_idle, dpp::at_listening, "euren Commands zu."));
        log_start(this->shards);
    });
    client.start(dpp::st_wait);
}

void Bot::setShards(int shards) {
    this->shards = shards;
}

