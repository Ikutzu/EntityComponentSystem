#include "Transform.h"


Transform::Transform() : position(0.0f, 0.0f), scale(1.0f, 1.0f), rotation(0)
{
	type = TRANSFORM;
}

Transform::~Transform()
{
}