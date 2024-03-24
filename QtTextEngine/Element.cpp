#include "Element.h"

#include <include/core/SkTypeface.h>
#include <include/core/SkFontTypes.h>


//TextElement::TextElement()
//{
//	canvasArea_ = { 400, 300 };
//	bitmap_ = new SkBitmap();
//	bitmap_->allocN32Pixels(canvasArea_.width, canvasArea_.height, false);
//	canvas_ = new SkCanvas(*bitmap_);
//	canvas_->drawColor(SkColorSetARGB(255, 101, 33, 131));
//}
//
//void TextElement::drawFace()
//{
//	
//	SkPaint paint;
//	paint.setARGB(255, 255, 0, 0);
//	paint.setAntiAlias(true);
//
//	for (size_t i = 0; i < charInfos_.size(); ++i)
//	{
//		std::shared_ptr<CharInfo> pChar = charInfos_[i];
//		const wchar_t character = pChar->getChar();
//		if (character == L'\r' || character == L'\n')
//			continue;
//		canvas_->drawSimpleText(&character, sizeof(character), SkTextEncoding::kUTF16,
//			pChar->getPosX(), pChar->getPosY(), font_, paint);
//	}
//	SkRect rect;
//	paint.setStyle(SkPaint::kStroke_Style);  // 设置为边框样式
//	paint.setStrokeWidth(2);  // 设置边框宽度
//	paint.setColor(SK_ColorWHITE);
//	float x = 100, y = 100 - font_.getSpacing();
//	rect.setLTRB(x, y, x + textBoxWidth_, y + textBoxHeight_);
//	canvas_->drawRect(rect, paint);
//}
//
//void TextElement::drawBorder()
//{
//}
