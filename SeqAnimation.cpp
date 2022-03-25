#include "SeqAnimation.h"
#include "tinyxml.h"
#include <iostream>
#include "../Graphics/TextureManager.h"


SeqAnimation::SeqAnimation(bool repeat): Animation(repeat) {}

void SeqAnimation::DrawFrame(float x, float y, float scale_x, float scale_y, SDL_RendererFlip flip) {
	TextureManager::GetInstance()->Draw(current_sequence_.TextureIDs[current_frame_], x, y, current_sequence_.width, current_sequence_.height,
		scale_x, scale_y, flip);
}

void SeqAnimation::Update(float dt) {
	if (repeat_ || !ended_) {
		ended_ = false;
		current_frame_ = (SDL_GetTicks() / current_sequence_.speed) % current_sequence_.frame_count;
	}

	if (!repeat_ && current_frame_ == (current_sequence_.frame_count - 1)) {
		ended_ = true;
		current_frame_ = (current_sequence_.frame_count - 1);
	}
}

void SeqAnimation::SetCurrentSeq(std::string seqID) {
	if (sequence_map_.count(seqID) > 0) {
		current_sequence_ = sequence_map_[seqID];
	}
	else {
		std::cout << "The given sequence animation is not matching: " << seqID << std::endl;
	}
}

void SeqAnimation::Parse(std::string source) {
	TiXmlDocument xml;
	xml.LoadFile(source);
	if (xml.Error()) {
		std::cout << "Failed to load animationfile: " << source << std::endl;
	}

	TiXmlElement* root = xml.RootElement();
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("sequence")) {
			Sequence seq;
			std::string seqID = e->Attribute("id");
			e->Attribute("speed", &seq.speed);
			e->Attribute("width", &seq.width);
			e->Attribute("height", &seq.height);
			e->Attribute("frameCount", &seq.frame_count);

			for (TiXmlElement* frame = e->FirstChildElement(); frame != nullptr; frame = frame->NextSiblingElement()) {
				seq.TextureIDs.push_back(frame->Attribute("textureID"));
			}

			sequence_map_[seqID] = seq;
		}
	}

}