#include "evenements.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


Evenements::Evenements()
{


}

void Evenements::event()
{

    random = rand()%(3-1) +1;
    if(random ==1)
    {
        bonus = true;
        this->benef += 0.2;
    }
   else
   {
        malus=true;
        this->perte += 0.2;

   }



}

