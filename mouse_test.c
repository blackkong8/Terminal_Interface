//gcc mouse_test.c -framework ApplicationServices

#include <ApplicationServices/ApplicationServices.h>

int main(void){
    CGRect screenBounds = CGDisplayBounds(CGMainDisplayID());
    printf(
        "Main screen is %dx%d\n",
        (int)screenBounds.size.width,
        (int)screenBounds.size.height
    );
    return 0;
}