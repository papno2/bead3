#include "Application.h"

using namespace std;


int main()
{
    Application app(18, 30);
    app.event_loop();

    return 0;
}
