#include "SpriteAnimation.h"
#include "Animation.h"
#include "../Graphics/TextureManager.h"
#include <iostream>

void SpriteAnimation::Update(float dt) {
	
	if (reset_frame_) {
		time_=SDL_GetTicks() - reset_amount_;
		std::cout << reset_amount_ << std::endl;
	}
	current_frame_ = ((SDL_GetTicks() - time_) / animation_speed_) % frame_count_;
	reset_frame_ = false;
	
}

void SpriteAnimation::ResetFrame(int i) {
	reset_frame_ = true;
	reset_amount_ = i;
}



void SpriteAnimation::Draw(float x, float y, int sprite_width, int sprite_height, float scale_x, float scale_y, SDL_RendererFlip flip) {
	TextureManager::GetInstance()->DrawFrame(texture_id_, x, y, sprite_width, sprite_height, sprite_row_, current_frame_, scale_x, scale_y, flip);
}

void SpriteAnimation::AbsoluteDraw(float x, float y, int sprite_width, int sprite_height, float scale_x, float scale_y, SDL_RendererFlip flip) {
	TextureManager::GetInstance()->AbsoluteDrawFrame(texture_id_, x, y, sprite_width, sprite_height, sprite_row_, current_frame_, scale_x, scale_y, flip);
}

void SpriteAnimation::SetProps(std::string texture_id, int sprite_row, int frame_count, int animation_speed)
{
	texture_id_ = texture_id;
	sprite_row_ = sprite_row;
	frame_count_ = frame_count;
	animation_speed_ = animation_speed;
	

}