#pragma once

#include "Setting.g.h"
namespace winrt::App2::implementation
{
    struct Setting : SettingT<Setting>
    {
        Setting()
        {
            
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        //void IsShowWelcome_Toggled(IInspectable const&, RoutedEventArgs const&);

        void IsShowWelcome_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);

        void Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::App2::factory_implementation
{
    struct Setting : SettingT<Setting, implementation::Setting>
    {
        
    };
}
