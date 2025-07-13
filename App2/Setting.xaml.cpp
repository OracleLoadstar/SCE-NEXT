#include "pch.h"
#include "Setting.xaml.h"
#if __has_include("Setting.g.cpp")
#include "Setting.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
extern nlohmann::json settings_;
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t Setting::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Setting::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
  //  void Setting::IsShowWelcome_Toggled(IInspectable const&, RoutedEventArgs const&)
  //  {
  //      auto localSettings = Windows::Storage::ApplicationData::Current().LocalSettings();
  //      localSettings.Values().Insert(L"IsShowWelcome", box_value(IsShowWelcome().IsOn()));
		//printf("IsShowWelcome_Toggled: %d\n", IsShowWelcome().IsOn());
  //  }

    void winrt::App2::implementation::Setting::IsShowWelcome_Toggled(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
    {
		winrt::Microsoft::UI::Xaml::Controls::ToggleSwitch toggleSwitch = sender.as<winrt::Microsoft::UI::Xaml::Controls::ToggleSwitch>();
        if (toggleSwitch != NULL) {
            if(toggleSwitch.IsOn()) {
                // 开启状态
                winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(L"IsShowWelcome", winrt::box_value(true));
				settings_["IsShowWelcome"] = true; // 更新全局设置
            } else {
                // 关闭状态
                winrt::Windows::Storage::ApplicationData::Current().LocalSettings().Values().Insert(L"IsShowWelcome", winrt::box_value(false));
				settings_["IsShowWelcome"] = false; // 更新全局设置
            }
        }
    }


}



void winrt::App2::implementation::Setting::Page_Loaded(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    winrt::Microsoft::UI::Xaml::Controls::ToggleSwitch myWelcomeToggle = IsShowWelcome();
    if (settings_["IsShowWelcome"] == false)
    {
        myWelcomeToggle.IsOn(false);
    }
    else
    {
        //this->Visibility(Microsoft::UI::Xaml::Visibility::Visible);
        myWelcomeToggle.IsOn(true);
    }
}
