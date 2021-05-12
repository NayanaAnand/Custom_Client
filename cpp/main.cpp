#include <iostream>
#include "ossie/ossieSupport.h"

#include "Custom_Client.h"
int main(int argc, char* argv[])
{
    Custom_Client_i* Custom_Client_servant;
    Component::start_component(Custom_Client_servant, argc, argv);
    return 0;
}

