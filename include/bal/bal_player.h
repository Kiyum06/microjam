#ifndef BAL_PLAYER_H
#define BAL_PLAYER_H

#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>
#include <bn_size.h>

namespace bal
{
class player{
        //GBA screen size
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = - bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = - bn::display::height() / 2;

    public:
        player(bn::fixed_point starting_position, bn::fixed speed);
        void update();

        // bn::sprite_ptr _sprite;
        bn::rect bounding_box;

    private:
        // The sprite to display the player
        bn::sprite_ptr _sprite;
        // The pixels/frame the player moves in each dimension
        bn::fixed _speed;
};

}

#endif