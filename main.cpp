#include "graphics.hpp"
#include "widgets.hpp"
#include "OXbox.h"
#include "examplecheckbox.hpp"
#include "Application.h"
#include "GameMaster.h"
#include <vector>
using namespace std;
using namespace genv;


int main()
{
    Application app(10, 30);
    app.event_loop();

    return 0;
}
