#pragma once

namespace nZemax
{
    enum Params {
        windowHeight = 600,
        windowWidth  = 600,
        sphereRadius = 200,
    };

    // hex colors in RGB format.
    // lowest byte is Blue
    enum class Colors: unsigned int {
        royalBlue = 0x4169E1,
        cherry    = 0xD2042D,

        red       = 0xFF0000,
        green     = 0x00FF00,
        blue      = 0x0000FF,

        white     = 0xFFFFFF,
        grey      = 0x808080,
        black     = 0x000000,
   };
};
