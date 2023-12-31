/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/robotscreen_screen/RobotScreenViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <images/BitmapDatabase.hpp>

RobotScreenViewBase::RobotScreenViewBase() :
    flexButtonCallback(this, &RobotScreenViewBase::flexButtonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    box.setPosition(0, 0, 480, 272);
    box.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(box);

    textArea1.setXY(12, 9);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(90, 189, 77));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RUPU));
    add(textArea1);

    line1.setPosition(0, 29, 480, 50);
    line1Painter.setColor(touchgfx::Color::getColorFromRGB(93, 245, 76));
    line1.setPainter(line1Painter);
    line1.setStart(10, 5);
    line1.setEnd(470, 5);
    line1.setLineWidth(1);
    line1.setLineEndingStyle(touchgfx::Line::ROUND_CAP_ENDING);
    add(line1);

    backButton.setIconBitmaps(Bitmap(BITMAP_BACK_20X20_ID), Bitmap(BITMAP_BACK_20X20_ID));
    backButton.setIconXY(16, 16);
    backButton.setAction(flexButtonCallback);
    backButton.setPosition(430, 222, 50, 50);
    add(backButton);
}

RobotScreenViewBase::~RobotScreenViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void RobotScreenViewBase::setupScreen()
{

}

void RobotScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &backButton)
    {
        //backToMenu
        //When backButton clicked change screen to MenuScreen
        //Go to MenuScreen with screen transition towards East
        application().gotoMenuScreenScreenWipeTransitionEast();
    }
}
