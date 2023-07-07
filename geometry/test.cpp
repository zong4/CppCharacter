#include "Point.h"
#include "Segment.h"

int main()
{
    {
        Item* item1 = new Point();
        Item* item2 = new Segment();

        item1->lookup(*item2);
        item2->lookup(*item1);

        Register::printSet();
    }

    {
        Item* item1 = new Point();
        Item* item2 = new Segment();

        item1->lookup(*item2);
        item2->lookup(*item1);

        Register::printSet();
    }

    return 0;
}