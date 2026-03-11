#ifndef SDG_INPUT_H
#define SDG_INPUT_H

#include <bn_array.h>

namespace sdg {

    class input {
        public:
            // Input constructor
            input(int difficulty);
            /**
            * Reads the direction input value every frame.
            */
            void update();

            /**
            * Returns whether the code has been correctly inputted.
            *
            * @return true if the code is correct, false if the code as not
            * been inputted correctly yet.
            */
            bool code_is_correct() const;
        private:
            // Default value for when no input is detected.
            int _input = -1;
            // Current index of code.
            int progress;
            // Correct code of fixed values. (max 9 inputs)
            bn::array<int, 10> challenge;
            // Game difficult, scales from 5 to 7 to 10, referring to amount of inputs required
            // to win.
            int diff;

    };
}

#endif