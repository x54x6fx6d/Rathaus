//
// Created by tommy31 on 10.07.23.
//

#ifndef RATHAUS_UTIL_H
#define RATHAUS_UTIL_H

#include <iostream>
#include <dpp/dpp.h>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/mysql/mysql.h>


static void log_end(){
    dpp::cluster bot("");
    dpp::webhook wh("https://discord.com/api/webhooks/1015300515128680498/-kmaSCcjFbRp9N3TxtrxX5olaxDxSanmXuwKut7aejhnpcPKwq0kPcS5V8AazkR9x4G6");
    dpp::embed emb = dpp::embed()
            .set_title("Bot Status")
            .add_field("Status", "Offline")
            .set_thumbnail("https://cdn.discordapp.com/icons/1088186959777759333/48cffba9fca17d4b8440c10176fdbfc5.webp?size=240")
            .set_color(dpp::colours::green);
    bot.execute_webhook(wh, dpp::message("").add_embed(emb));
}

static void log_start([[maybe_unused]] int shards = 1) {
    dpp::cluster bot("");
    std::string desc = "Running on " + std::to_string(shards) + " Shards";

    dpp::webhook wh("https://discord.com/api/webhooks/1015300515128680498/-kmaSCcjFbRp9N3TxtrxX5olaxDxSanmXuwKut7aejhnpcPKwq0kPcS5V8AazkR9x4G6");
    dpp::embed emb = dpp::embed()
            .set_title("Bot Status")
            .set_description(desc)
            .add_field("Status", "Online")
            .set_thumbnail("https://cdn.discordapp.com/icons/1088186959777759333/48cffba9fca17d4b8440c10176fdbfc5.webp?size=240")
            .set_color(dpp::colours::green);
    bot.execute_webhook(wh, dpp::message("").add_embed(emb));
}

#endif //RATHAUS_UTIL_H
