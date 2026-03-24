#ifndef KGG_GAME_NAME_H // header guard
#define KGG_GAME_NAME_H // This works with #ifndef to make sure the header is only processed once.

#include "bn_sprite_ptr.h" //my class stores sprite objects using Butano’s bn::sprite_ptr type, especially for displaying the score.
#include "mj/mj_game.h" // my class inherits from mj::game, so I included this header to inherit the common game interface.
#include "bn_vector.h" // Butano often uses fixed-size containers, which are good for memory control on Game Boy Advance projects.
#include "kgg/kgg_rock.h" // I included my rock class because this game creates and updates multiple falling rocks.
#include "kgg/kgg_player.h" // I included the player class because the game owns a player object that handles the character’s state and behavior
#include "bn_regular_bg_ptr.h" //I included this so I could store and manage the game’s background using Butano’s background pointer type.


namespace kgg { // I placed this class inside a namespace to group related game code together and avoid naming collisions with other parts of the project

class kgg_game_name : public mj::game //This class represents my game, and it inherits from the project’s base game class so it follows the required game interface like play, title, and transition functions
{

public: // functions under public can be accessed from outside the class.

    kgg_game_name(int completed_games, const mj::game_data& data); //A constructor is a special function that runs automatically when the object is created. It receives the number of completed games and a reference to shared game data. I used const and a reference to avoid copying the data and to ensure it is not modified inside the constructor.

    bn::string<16> title() const override; //Declares a function that returns the title of the game. A virtual function is a function defined in a base class that can be redefined in a derived class.

    int total_frames() const override; //This returns the duration of the game in frames, which helps the engine manage timing and round length

    mj::game_result play(const mj::game_data& data) override; //Declares the main game function. play is the core function of the game. It receives the current game data, runs the gameplay logic, and returns the result of the round

    bool victory() const override; //a function that returns whether the player won

    void fade_in(const mj::game_data& data) override; // This function handles the transition when the game starts, so the scene can appear smoothly instead of popping in instantly.

    void fade_out(const mj::game_data& data) override; // This function handles the ending transition when the round is over or the game is switching away

private: //These variables and helper functions should only be used inside the class

    bn::fixed _rock_speed = 3.5; //This stores the rock speed. I used bn::fixed because Butano commonly uses fixed-point number type values for movement, which is suitable for game development on limited hardware
    bn::fixed _speed(mj::difficulty_level difficulty); //a private helper function that returns a speed based on difficulty
    int _spawn_limit = 50; //the number of frames that must pass before a new rock is created
    bool _victory = false; //This boolean tracks whether the player won the round, and it starts as false until the victory condition is met
    player _player; //Creates a player object as a member of the game class
    bool _game_over = false; // helps stop the game once player gets hit
    int _spawn_timer = 0; // This timer increases as the game runs, and when it reaches the spawn limit, a new rock can be created
    bn::vector<rock, 16> _rocks; // I used a fixed-capacity vector to store active rocks. This is useful in Butano because memory is more controlled, and I know this can store up to 16 rocks
    bn::regular_bg_ptr _background; //This stores the game’s background so the class can create and manage the scene visually
    bool _lost = false;      // remembers that player got hit
    int _lose_timer = 0;     // short delay before ending round
    static constexpr int _lose_delay = 60; //about 1 second. static means the variable belongs to the class itself, not to each object. constexpr is a compile-time constant. 
    int _score = 0; // keeps track of survival score
    
    bn::vector<bn::sprite_ptr, 32> _score_sprites; //I used this vector to hold the sprite objects that visually display the score. Since text is often made from sprites in Butano, this lets me manage the score graphics




};

}

#endif //Ends the header guard


// This header defines my main game class. 
// It inherits from the project’s base game interface and declares the functions needed 
// to run the game, such as play, transitions, title, and victory state. 
// It also stores the internal game state like the player, rocks, timers, background, 
// and score.