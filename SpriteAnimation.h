#ifndef SPRITE_ANIMATION
#define SPRITE_ANIMATION

#include <string>
#include "SDL.h"
#include "Animation.h"
#include "../Timer/Timer.h"


class SpriteAnimation : public Animation
{
public:
	SpriteAnimation(bool repeat = true) {
		time_ = 0;
		reset_frame_ = false;
	}

	virtual void Update(float dt);
	void Draw(float x, float y, int sprite_width, int sprite_height, float scale_x = 1, float scale_y = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void AbsoluteDraw(float x, float y, int sprite_width, int sprite_height, float scale_x = 1, float scale_y = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void SetProps(std::string texture_id, int sprite_row, int frame_count, int animation_speed);

	void ResetFrame(int i);
	int GetFrame() {
		return current_frame_;
	}

private:
	int sprite_row_;
	int animation_speed_, frame_count_;
	std::string texture_id_;
	
	Uint32 time_;
	int reset_amount_;
	bool reset_frame_;
};

#endif // !SPRITE_ANIMATION

