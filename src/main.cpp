#include <iostream>

// Files
#include "util.h"
#include "Bot.h"

int main() {
    int shards = 10;
    Bot bot;
    bot.run();
    log_start(shards);
    return 0;
}
