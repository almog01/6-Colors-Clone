#include "User.h"



User::User(Colorbar & colorbar) : Player(colorbar)
{
}


User & User::instance(Colorbar & colorbar)
{
	static User inst(colorbar);
	return inst;
}

User::~User()
{
}
