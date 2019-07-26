#include "pch.h"
#include "Windows.h"
#include "WindowControl.h"
class WindowControl
{
public:
	virtual void draw() = 0;
	virtual ~WindowControl();
};

WindowControl::WindowControl()
{
}


WindowControl::~WindowControl()
{
}
