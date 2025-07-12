#pragma once

#include "Home.g.h"

namespace winrt::App2::implementation
{
    struct Home : HomeT<Home>
    {
        Home()
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
    struct Home : HomeT<Home, implementation::Home>
    {
    };
}
