// For OSX
// gcc mouse_test.c -framework ApplicationServices

#include <ApplicationServices/ApplicationServices.h>
#include <stdio.h>

void die(const char *s)
{
    perror(s);
    exit(1);
}

void fancyPrintLocation(CGPoint location)
{
    printf(
        "(%d, %d)\n",
        (int)location.x,
        (int)location.y);
}

CGEventRef CGEventCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon)
{
    if (type == kCGEventMouseMoved)
    {
        CGPoint location = CGEventGetLocation(event);
        fancyPrintLocation(location);
    }
    return event;
}

int main(void)
{
    CGRect screenBounds = CGDisplayBounds(CGMainDisplayID());
    printf(
        "Main screen is %dx%d\n",
        (int)screenBounds.size.width,
        (int)screenBounds.size.height);

    CFMachPortRef eventTap = CGEventTapCreate(
        kCGSessionEventTap,
        kCGHeadInsertEventTap,
        kCGEventTapOptionDefault,
        (1 << kCGEventMouseMoved),
        CGEventCallback,
        NULL);

    if (!eventTap)
    {
        die("eventTap");
    }

    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(
        kCFAllocatorDefault,
        eventTap,
        0);

    CFRunLoopAddSource(
        CFRunLoopGetCurrent(),
        runLoopSource,
        kCFRunLoopCommonModes);

    CGEventTapEnable(eventTap, true);
    CFRunLoopRun();

    return 0;
}