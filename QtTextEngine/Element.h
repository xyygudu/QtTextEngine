#pragma once
#include "Define.h"

#include <include/core/SkFont.h>
#include <include/core/SkCanvas.h>
#include <include/core/SkBitmap.h>

class Element
{
public:
	Element() = default;
	virtual void drawFace() = 0;
	virtual void drawBorder() = 0;
	virtual void setCenterPoint(float x, float y) = 0;

};

//class TextElement : public Element
//{
//public:
//	TextElement();
//	virtual void drawFace();
//	virtual void drawBorder();
//
//private:
//	GESize canvasArea_;
//	SkFont font_;
//	SkCanvas* canvas_;
//	SkBitmap* bitmap_;
//	
//};