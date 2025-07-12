#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
    void MainWindow::NavigationMain_SelectionChanged(winrt::Microsoft::UI::Xaml::Controls::NavigationView const& sender, winrt::Microsoft::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
    {
        auto selectedItem = args.SelectedItem().as<winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem>();
		auto tag = winrt::unbox_value<winrt::hstring>(selectedItem.Tag());

        if (tag == L"home") {
            Content().Navigate(winrt::xaml_typename<App2::Home>());
            this->Title(L"SEC-NEXT-首页");
        }
        else if (tag == L"calculator") {
            Content().Navigate(winrt::xaml_typename < App2::Calculator_pg>());
            //Content().Navigate(winrt::xaml_typename<App2::Calculator>());
            //this->Title(L"SEC-NEXT-关于");
            this->Title(L"SCE-NEXT-计算");
        }
        if (args.IsSettingsSelected()) {
            // Handle settings selection
            Content().Navigate(winrt::xaml_typename<App2::Setting>());
            this->Title(L"SEC-NEXT-设置");

            return;
        }
    }

}

