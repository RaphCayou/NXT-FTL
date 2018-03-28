﻿#include "position.h"

position::position(float x, float y, float direction_in_rad) : x(x), y(y), direction_in_rad(direction_in_rad)
{
    
}

bool position::operator==(position other) const
{
    return 
        std::fabs(this->x - other.x) < std::numeric_limits<float>::epsilon() &&
        std::fabs(this->y - other.y) < std::numeric_limits<float>::epsilon() &&
        std::fabs(this->direction_in_rad - other.direction_in_rad) < std::numeric_limits<float>::epsilon();
}
