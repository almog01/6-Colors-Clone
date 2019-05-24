#pragma once
#include "Player.h"

class User : public Player
{
public:
	// Instance function to make the user as singleton
	static User& instance(Colorbar & colorbar);
	~User();
	User(const User&) = delete;
	User& operator=(const User&) = delete;

private:
	User(Colorbar & colorbar);
};

