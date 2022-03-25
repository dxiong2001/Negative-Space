#ifndef SEQ_ANIMATION_H
#define SEQ_ANIMATION_H

#include <map>
#include <string>
#include <vector>
#include "SDL.h"
#include "Animation.h"


struct Sequence {
	int speed;
	int frame_count;
	int width, height;
	std::vector<std::string> TextureIDs;
};


class SeqAnimation : public Animation
{

public:
	SeqAnimation(bool repeat = true);

	virtual void Update(float dt);
	void Parse(std::string source);
	void SetCurrentSeq(std::string seqID);
	void SetRepeate(bool repeat) { repeat_ = repeat; }
	void DrawFrame(float x, float y, float scale_x = 1, float scale_y = 1, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	Sequence current_sequence_;
	std::map<std::string, Sequence> sequence_map_;
};



#endif