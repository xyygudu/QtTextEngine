#pragma once

class CharInfo
{
public:
	CharInfo(wchar_t c);
	~CharInfo();
	void setPosX(float posx) { posX_ = posx; }
	void setPosxY(float posy) { posY_ = posy; }
	void setPos(float posx, float posy) { posX_ = posx; posY_ = posy; }
	float getPosX() { return posX_; }
	float getPosY() { return posY_; }
	void setChar(wchar_t c) { char_ = c; }
	wchar_t getChar() { return char_; }

	void draw();

private:
	wchar_t char_;
	float posX_;
	float posY_;

};

