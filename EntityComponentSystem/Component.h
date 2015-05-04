#pragma once

class Component
{
	
public:

	enum compType{
		RENDER,
		TRANSFORM
	};

	Component(){};
	virtual ~Component(){};

	compType GetType(){ return type; }


	compType type;
};

