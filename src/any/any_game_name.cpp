#include "any_game_name.h"

namespace any {
    any_game_name::any_game_name([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
        mj::game("any"),
        


    bn::string<16> any_game_name::title() const {
        return "testing skeleton";
    }

    int any_game_name::total_frames() const {
        return 300;
    }

    mj::game_result any_game_name::play([[maybe_unused]] const mj::game_data& data){
        _player.update();
        mj::game_result result(victory(), false);
        return result;
    }

    bool any_game_name::victory() const {
    return false;
}

void any_game_name::fade_in([[maybe_unused]]const mj::game_data& data){

}

void any_game_name::fade_out([[maybe_unused]] const mj::game_data& data){
    
}

}