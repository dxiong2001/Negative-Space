#ifndef ANIMATION_H
#define ANIMATION_H
#include "SDL.h"
#include <string>


class Animation
{
public:
	Animation(bool repeat = true) : repeat_(repeat) { ended_ = false; }
	
	virtual void Update(float dt) = 0;
	inline bool Ended() { return ended_; }

protected:

	bool repeat_;
	bool ended_;
	int current_frame_;


};



#endif