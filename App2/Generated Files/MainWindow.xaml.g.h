﻿
//------------------------------------------------------------------------------
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//------------------------------------------------------------------------------
#pragma once

#include <unknwn.h>

// Undefine GetCurrentTime macro to prevent
// conflict with Storyboard::GetCurrentTime
#undef GetCurrentTime

#if __has_include(<winrt/Microsoft.UI.Xaml.Controls.h>)
#include <winrt/Microsoft.UI.Xaml.Controls.h>
#endif
#if __has_include(<winrt/Microsoft.UI.Xaml.Markup.h>)
#include <winrt/Microsoft.UI.Xaml.Markup.h>
#endif
#if __has_include(<winrt/Windows.Foundation.h>)
#include <winrt/Windows.Foundation.h>
#endif


namespace winrt::App2::implementation
{
    using IInspectable = ::winrt::Windows::Foundation::IInspectable;

    template <typename D, typename ... I>
    struct MainWindowT : public ::winrt::App2::implementation::MainWindow_base<D,
        ::winrt::Microsoft::UI::Xaml::Markup::IComponentConnector,
        I...>
    {
        using base_type = typename MainWindowT::base_type;
        using base_type::base_type;
        using class_type = typename MainWindowT::class_type;

        void InitializeComponent();
        virtual void Connect(int32_t connectionId, IInspectable const& target);
        virtual ::winrt::Microsoft::UI::Xaml::Markup::IComponentConnector GetBindingConnector(int32_t connectionId, IInspectable const& target);
        void UnloadObject(::winrt::Microsoft::UI::Xaml::DependencyObject const& dependencyObject);
        void DisconnectUnloadedObject(int32_t connectionId);

        ::winrt::Microsoft::UI::Xaml::Controls::NavigationView NavigationMain()
        {
            return _NavigationMain;
        }
        void NavigationMain(::winrt::Microsoft::UI::Xaml::Controls::NavigationView value)
        {
            _NavigationMain = value;
        }

        ::winrt::Microsoft::UI::Xaml::Controls::Frame Content()
        {
            return _Content;
        }
        void Content(::winrt::Microsoft::UI::Xaml::Controls::Frame value)
        {
            _Content = value;
        }
        
    protected:
        bool _contentLoaded{false};

    private:
        struct MainWindow_obj1_Bindings;

        ::winrt::Microsoft::UI::Xaml::Controls::NavigationView _NavigationMain{nullptr};
        ::winrt::Microsoft::UI::Xaml::Controls::Frame _Content{nullptr};
    };
}

