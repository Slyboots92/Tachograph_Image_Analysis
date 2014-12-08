#include "polarbasictachoactivityfactory.h"

PolarBasicTachoActivityFactory::PolarBasicTachoActivityFactory()
{
}


TachoActivitiy* PolarBasicTachoActivityFactory::produceTachoActivtiy(int choose)
{

    switch( choose )
    {
    case 0:
        return  new TachoRestActivity();
        break;

    case 1:
        return new TachoStandbyActivity();
        break;

    case 2:
        return new TachoWorkingActivity();
        break;

    case 3:
        return new TachoDrivingActivity();
        break;

    default:
        throw new std::invalid_argument("choose wrong arg");
        break;
    }

}
