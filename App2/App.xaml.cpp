#include "pch.h"
#include "App.xaml.h"
#include "MainWindow.xaml.h"
#include "Setting.xaml.h"

using namespace winrt;
using namespace Microsoft::UI::Xaml; 
using json = nlohmann::json;
nlohmann::json settings_ = {};
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
winrt::hstring to_hstring(const std::string& s) { return winrt::to_hstring(s); };
std::string to_string(const winrt::hstring& h) { return winrt::to_string(h); };

namespace winrt::App2::implementation
{
    /// <summary>
    /// Initializes the singleton application object.  This is the first line of authored code
    /// executed, and as such is the logical equivalent of main() or WinMain().
    /// </summary>
    App::App()
    {
        // Xaml objects should not call InitializeComponent during construction.
        // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent

#if defined _DEBUG && !defined DISABLE_XAML_GENERATED_BREAK_ON_UNHANDLED_EXCEPTION
        UnhandledException([](IInspectable const&, UnhandledExceptionEventArgs const& e)
        {
            if (IsDebuggerPresent())
            {
                auto errorMessage = e.Message();
                __debugbreak();
            }
        });
#endif

        m_suspendingToken = winrt::Windows::ApplicationModel::Core::CoreApplication::Suspending({ this, &App::OnSuspending });
        m_resumingToken = winrt::Windows::ApplicationModel::Core::CoreApplication::Resuming({ this, &App::OnResuming });

    }


    /// <summary>
    /// Invoked when the application is launched.
    /// </summary>
    /// <param name="e">Details about the launch request and process.</param>
    void App::OnLaunched([[maybe_unused]] LaunchActivatedEventArgs const& e)
    {
        settings_ = {
            {"IsShowWelcome", true}, // Default value for IsShowWelcome
            {"culselect", 1},
            {"ResultPrecision", 2},
            {"IsAutoSave", true},
            {"SavePath", L"%USERPROFILE%\.SCE\save"}
        };
        winrt::Windows::Storage::ApplicationDataContainer localSettings = winrt::Windows::Storage::ApplicationData::Current().LocalSettings();
		// Check if the "IsShowWelcome" setting exists, if not, set it to true
        if (localSettings.Values().HasKey(L"IsShowWelcome"))
        {
            auto isShowWelcome = localSettings.Values().Lookup(L"IsShowWelcome").as<bool>();
            settings_["IsShowWelcome"] = isShowWelcome;
        }
        else
        {
            settings_["IsShowWelcome"] = true;
		}
        if (localSettings.Values().HasKey(L"culselect"))
        {
            auto culselect = localSettings.Values().Lookup(L"culselect").as<int>();
            settings_["culselect"] = culselect;
        }
        else
        {
            settings_["culselect"] = 1; // Default value
		}
        if (localSettings.Values().HasKey(L"ResultPrecision"))
        {
            auto resultPrecision = localSettings.Values().Lookup(L"ResultPrecision").as<int>();
            settings_["ResultPrecision"] = resultPrecision;
        }
        else
        {
            settings_["ResultPrecision"] = 2; // Default value
        }
        if (localSettings.Values().HasKey(L"SavePath")) {
			auto savepath = localSettings.Values().Lookup(L"SavePath").as<winrt::hstring>();
			settings_["SavePath"] = savepath;
            }
		else {
			settings_["SavePath"] = L"%USERPROFILE%\\.SCE\\save"; // Default value
		}


        window = make<MainWindow>();
        window.Activate();
    }
    void App::SaveSettingsToLocalSettings()
    {
        winrt::Windows::Storage::ApplicationDataContainer localSettings =
            winrt::Windows::Storage::ApplicationData::Current().LocalSettings();

        // �� JSON �е�ֵ������浽 LocalSettings
        // ע�⣺LocalSettings ֻ�ܴ洢�������ͻ� PropertySet������ֱ�Ӵ洢���ӵ� JSON �ṹ
        if (settings_.contains("IsShowWelcome"))
        {
            localSettings.Values().Insert(L"IsShowWelcome", winrt::box_value(settings_["IsShowWelcome"].get<bool>()));
        }
        if (settings_.contains("culselect"))
        {
            localSettings.Values().Insert(L"culselect", winrt::box_value(settings_["culselect"].get<int>()));
        }
        if (settings_.contains("ResultPrecision"))
        {
            localSettings.Values().Insert(L"ResultPrecision", winrt::box_value(settings_["ResultPrecision"].get<int>()));
        }
        if (settings_.contains("IsAutoSave"))
        {
            localSettings.Values().Insert(L"IsAutoSave", winrt::box_value(settings_["IsAutoSave"].get<bool>()));
        }
        if (settings_.contains("SavePath"))
        {
            // �� JSON ��ȡ std::string��ת��Ϊ hstring ���浽 LocalSettings
            localSettings.Values().Insert(L"SavePath", winrt::box_value(to_hstring(settings_["SavePath"].get<std::string>())));
        }

        OutputDebugString(L"Settings saved to LocalSettings.\n");
    }
    void App::OnSuspending(IInspectable const& sender, winrt::Windows::ApplicationModel::SuspendingEventArgs const& args)
    {
        auto deferral = args.SuspendingOperation().GetDeferral();
        // Ӧ�ó������ʱ��������
        SaveSettingsToLocalSettings();
        deferral.Complete();
        OutputDebugString(L"App Suspending and settings saved.\n");
    }

    void App::OnResuming(IInspectable const& sender, IInspectable const& args)
    {
        // Ӧ�ó���ӹ���״̬�ָ�ʱ����
        OutputDebugString(L"App Resumed.\n");
        // ͨ������Ҫ���������¼��أ���Ϊ settings_ �������ڴ���
        // ��������Ӧ�������ⲿ���������ļ�����������Ҫˢ��UI���������������¼���
    }
}
