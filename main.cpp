#include <Windows.h>
#include <WinUser.h>
#include <shellapi.h>

bool getTaskbarAutohideState()
{
    APPBARDATA msgData{};
    msgData.cbSize = sizeof(msgData);
    msgData.hWnd = FindWindow("System_TrayWnd", nullptr);
    LPARAM state = SHAppBarMessage(ABM_GETSTATE, &msgData);
    return state & ABS_AUTOHIDE;
}

void setTaskbarAutohide(bool enabled) 
{
    APPBARDATA msgData{};
    msgData.cbSize = sizeof(msgData);
    msgData.hWnd = FindWindow("System_TrayWnd", nullptr);
    msgData.lParam = enabled ? ABS_AUTOHIDE : ABS_ALWAYSONTOP;
    SHAppBarMessage(ABM_SETSTATE, &msgData);
}

void toggleTaskbarAutohide()
{
    setTaskbarAutohide(!getTaskbarAutohideState());
}

int main(int argc, char const *argv[])
{
    toggleTaskbarAutohide();

    return 0;
}
