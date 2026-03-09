
#include "kgg/kgg_game_name.h"
#include "mj/mj_game_list.h"


namespace {
constexpr bn::string_view code_credits[] = { "Gurpinder Gill" };
constexpr bn::string_view graphics_credits[] = { "" };
constexpr bn::string_view music_credits[] = { "" };
constexpr bn::string_view sfx_credits[] = { "" };
}  

namespace kgg {

kgg_game_name::kgg_game_name(int completed_games, const mj::game_data& data)
: mj::game("kgg")
{
    (void)completed_games;
    (void)data;
}

bn::string<16> kgg_game_name::title() const
{
    return "KGG Game";
}

int kgg_game_name::total_frames() const
{
    return 180;
}

mj::game_result kgg_game_name::play(const mj::game_data& data)
{
    (void)data;
    _victory = true;
    return mj::game_result();
}

bool kgg_game_name::victory() const
{
    //return false;
    return _victory;
}

void kgg_game_name::fade_in(const mj::game_data& data)
{
    (void)data;
}

void kgg_game_name::fade_out(const mj::game_data& data)
{
    (void)data;
}

}
MJ_GAME_LIST_ADD(kgg::kgg_game_name);

MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits);
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits);
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits);
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits); 

