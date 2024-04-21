#pragma once
#include <string>
#include <vector>
#include <memory>
#include <functional>



#include "Element.h"
#include "CharInfo.h"
#include "Define.h"



class TextElement : public Element
{
public:
	TextElement();
	void setText(const std::u16string& text);
	void horizontalLayout(float textBoxWidth);
	virtual void drawFace() override;
	virtual void drawBorder() override;
	virtual void setCenterPoint(float x, float y);
	SkBitmap getBitmap() { return bitmap_; }

	
private:
	bool isAddChar(const char16_t & utf16Char);
private:
	using TextAreaChangedCallback = std::function<void(float, float)>;

	GESize canvasArea_;
	GESize textArea_;
	int insertIndex_;
	GEPointF centerPoint_;
	std::vector<std::shared_ptr<CharInfo>> charInfos_;

	SkFont font_;

	SkCanvas* canvas_;
	SkBitmap bitmap_;

	AlignMode alignMode_;
	Layout layout_;
	TextAreaChangedCallback textAreaChangedCallback_;

	bool isDirty_;
};

