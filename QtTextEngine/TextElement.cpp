#include "TextElement.h"
#include <include/gpu/GrDirectContext.h>
#include <include/gpu/ganesh/gl/GrGLDirectContext.h>
#include <include/gpu/gl/GrGLInterface.h>
#include <include/core/SkSurface.h>
#include <include/core/SkFontMetrics.h>
#include "include/core/SkData.h"
#include "include/core/SkImage.h"

TextElement::TextElement()
    : text_(L"")
    , font_(SkTypeface::MakeFromName("Microsoft Yahei", SkFontStyle::Normal()), 40)
    , alignMode_(AlignMode::LEFT)
    , layout_(Layout::HORIZONTAL)
    , textAreaChangedCallback_(nullptr)
    , isDirty_(false)
    , centerPoint_(GEPointF(300, 240))
{
    SkScalar width = 600;
    SkScalar height = 480;
    canvasArea_.width = width;
    canvasArea_.height = height;
    bitmap_ = SkBitmap();
    bitmap_.allocN32Pixels(width, height, false);
    canvas_ = new SkCanvas(bitmap_);
    canvas_->drawColor(SkColorSetARGB(255, 101, 33, 131));

}

void TextElement::setText(const std::wstring& text)
{
    text_ = text;
    if (!charInfos_.empty())
    {
        charInfos_.clear();
        bitmap_.erase(SkColorSetARGB(255, 101, 33, 131), bitmap_.bounds());
    }
        
    for (size_t i = 0; i < text.size(); ++i)
    {
        std::shared_ptr<CharInfo> pChar(new CharInfo(text[i]));
        charInfos_.push_back(pChar);
    }
    isDirty_ = true;
}

void TextElement::horizontalLayout(float textBoxWidth)
{
    size_t charCount = charInfos_.size();
    size_t index = 0;
    float curPosX = 0, curPosY = 0;
    float textWidth = 0, textHeight = 0;
    int lineCount = 1;
    while (index < charCount)
    {
        std::shared_ptr<CharInfo> pChar = charInfos_[index];
        pChar->setPos(curPosX, curPosY);
        const wchar_t character = pChar->getChar();
        float advance = font_.measureText(&character, sizeof(character), SkTextEncoding::kUTF16);
        curPosX += advance;
        if (curPosX > textWidth)
            textWidth = curPosX;
        
        if (character == L'\r' || character == L'\n')
        {
            lineCount++;
            curPosX = 0;
            curPosY += font_.getSpacing();
        }
        if (curPosX > textBoxWidth)
        {
            lineCount++;
            if (textWidth - advance > textWidth)
                textWidth -= advance;
            index--;
            curPosX = 0;
            curPosY += font_.getSpacing();
        }
        index++;
    }
    textHeight = lineCount * font_.getSpacing();
    textArea_.width = textWidth;
    textArea_.height = textHeight;
    if (textAreaChangedCallback_)
        textAreaChangedCallback_(textWidth, textHeight);
}

void TextElement::drawFace()
{
    SkPaint paint;
    paint.setARGB(255, 255, 0, 0);
    paint.setAntiAlias(true);
    
    float hSpace = centerPoint_.x - (textArea_.width / 2);
    float vSpace = centerPoint_.y - (textArea_.height / 2);
    SkFontMetrics* metrics = new SkFontMetrics();
    float lineHegiht = font_.getMetrics(metrics);
    float ascent = metrics->fAscent;
    for (size_t i = 0; i < charInfos_.size(); ++i)
    {
        std::shared_ptr<CharInfo> pChar = charInfos_[i];
        const wchar_t character = pChar->getChar();
        if (character == L'\r' || character == L'\n')
            continue;
        canvas_->drawSimpleText(&character, sizeof(character), SkTextEncoding::kUTF16,
            pChar->getPosX() + hSpace, pChar->getPosY() + vSpace - metrics->fDescent + font_.getSpacing(), font_, paint);
    }
    SkRect rect;
    paint.setStyle(SkPaint::kStroke_Style);  // 设置为边框样式
    paint.setStrokeWidth(2);  // 设置边框宽度
    paint.setColor(SK_ColorWHITE);
    float x = centerPoint_.x - textArea_.width / 2;
    float y = centerPoint_.y - textArea_.height / 2;
    rect.setLTRB(x, y, x + textArea_.width, y + textArea_.height);
    canvas_->drawRect(rect, paint);
}

void TextElement::drawBorder()
{
}

void TextElement::setCenterPoint(float x, float y)
{
    centerPoint_.x = x;
    centerPoint_.y = y;
}

