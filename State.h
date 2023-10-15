#pragma once

class State
{
public:

	State();
	~State();

	virtual void load() = 0;
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void dispose() = 0;

};