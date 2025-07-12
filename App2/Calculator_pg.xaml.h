#pragma once

#include "Calculator_pg.g.h"

namespace winrt::App2::implementation
{
    struct Calculator_pg : Calculator_pgT<Calculator_pg>
    {
        Calculator_pg()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::App2::factory_implementation
{
    struct Calculator_pg : Calculator_pgT<Calculator_pg, implementation::Calculator_pg>
    {
    };
}
