#pragma once
#include "State.h"

class NoneState : public State
{
public:

	NoneState();
	~NoneState();

private:


	// Inherited via State
	void load() override;

	void init() override;

	void update() override;

	void draw() override;

	void dispose() override;

};