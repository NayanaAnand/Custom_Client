#ifndef CUSTOM_CLIENT_I_IMPL_H
#define CUSTOM_CLIENT_I_IMPL_H

#include "Custom_Client_base.h"

class Custom_Client_i : public Custom_Client_base
{
    ENABLE_LOGGING
    public:
        Custom_Client_i(const char *uuid, const char *label);
        ~Custom_Client_i();

        void constructor();

        int serviceFunction();

    protected:
};

#endif // CUSTOM_CLIENT_I_IMPL_H
