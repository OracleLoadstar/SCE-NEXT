#pragma once

#include "MainWindow.g.h"

namespace winrt::App2::implementation
{

    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
            m_activatedRevoker = Activated(winrt::auto_revoke, { this, &MainWindow::OnWindowFirstActivated });

        };

        int32_t MyProperty();
        void MyProperty(int32_t value);
        void NavigationMain_SelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args);
    private:
        // ˽�з����������ڵ�һ�μ�����߼�
        void OnWindowFirstActivated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args);

        // �����Զ�ȡ�����ĵ� revoker
        winrt::Microsoft::UI::Xaml::Window::Activated_revoker m_activatedRevoker;
    };


}

namespace winrt::App2::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
