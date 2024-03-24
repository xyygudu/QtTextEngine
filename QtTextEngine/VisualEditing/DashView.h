#pragma once
#include <vector>
#include <Element.h>

#include "Define.h"

enum Modifier
{
    NoModifier = 0x00000000,
    ShiftModifier = 0x02000000,
    ControlModifier = 0x04000000,
    AltModifier = 0x08000000,
};


enum MouseButton
{
    NoButton = 0x00000000,
    LeftButton = 0x00000001,
    RightButton = 0x00000002,
};

struct Event
{
    Modifier modifier = Modifier::NoModifier;
    MouseButton mouseButton = MouseButton::NoButton;
    GEPoint positon = { -1, -1 };
};

class DashView
{
public:
    DashView();
    void executeEvent(const Event& event);

private:
    bool enterEditMode_;            // 是否进入可视化编辑模式
    bool enableHover_;              // 是否启用鼠标hover
    std::vector<Element*> elementList_;
};