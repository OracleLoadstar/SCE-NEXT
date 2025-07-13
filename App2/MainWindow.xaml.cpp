#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <winrt/Windows.UI.Xaml.Interop.h>

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using json = nlohmann::json;
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
extern nlohmann::json settings_;
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
            this->Title(L"SCE-NEXT-��ҳ");
        }
        else if (tag == L"calculator") {
            Content().Navigate(winrt::xaml_typename < App2::Calculator_pg>());
            //Content().Navigate(winrt::xaml_typename<App2::Calculator>());
            //this->Title(L"SEC-NEXT-����");
            this->Title(L"SCE-NEXT-����");
        }
        if (args.IsSettingsSelected()) {
            // Handle settings selection
            Content().Navigate(winrt::xaml_typename<App2::Setting>());
            this->Title(L"SCE-NEXT-����");

            return;
        }
    }

    void MainWindow::OnWindowFirstActivated(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::WindowActivatedEventArgs const& args)
    {
        winrt::Microsoft::UI::Xaml::Controls::NavigationView myNavigationView = NavigationMain();
        
        // ���� MenuItems ����������Ҫ�Ƴ�����Ŀ
        if (settings_["IsShowWelcome"] == false)
        {
            Content().Navigate(winrt::xaml_typename<App2::Calculator_pg>());
			this->Title(L"SEC-NEXT-����");
            for (uint32_t i = 0; i < myNavigationView.MenuItems().Size(); ++i)
            {
                winrt::Windows::Foundation::IInspectable item = myNavigationView.MenuItems().GetAt(i);

                // ���Խ���ת��Ϊ NavigationViewItem
                if (winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem navItem = item.try_as<winrt::Microsoft::UI::Xaml::Controls::NavigationViewItem>())
                {
                    // ��� Tag �����Ƿ�ƥ��
                    if (navItem.Tag().try_as<winrt::hstring>() == L"home")
                    {
                        myNavigationView.MenuItems().RemoveAt(i);
                        // �ҵ����Ƴ��ˣ���������ѭ��
                        break;
                    }
                }
            }
        }
        else {
            Content().Navigate(winrt::xaml_typename<App2::Home>());
			this->Title(L"SCE-NEXT-��ҳ");
        };
    }

}

