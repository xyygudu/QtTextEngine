#pragma once

class CharInfo {
public:
	CharInfo(char16_t c);
	~CharInfo();
	void setPenX(float penx) { penX_ = penx; }
	void setPosY(float peny) { penY_ = peny; }
	void setPenPos(float posx, float posy) { penX_ = posx; penY_ = posy; }
	float getPenX() { return penX_; }
	float getPenY() { return penY_; }
	void setChar(char16_t c) { originChar_  = paintChar_ = c; }
	//void setOriginChar(char16_t c) { originChar_ = c; }
	void setPaintChar(char16_t c) { paintChar_ = c; }
	void setAddChar(char16_t c) { addChar_ = c; }
	const char16_t getOriginChar() { return originChar_; }
	const char16_t getPaintChar() { return paintChar_; }
	const char16_t getAddChar() { return addChar_; }

	void draw();

private:
	char16_t originChar_;	// 原始字符
	char16_t paintChar_;	// 正在渲染的字符
	char16_t addChar_;		// 部分字符，一个char16表示不全，需要一个补充字符
	float penX_;			// pen表示笔点
	float penY_;

};

