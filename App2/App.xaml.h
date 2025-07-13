#pragma once

#include "App.xaml.g.h"

namespace winrt::App2::implementation
{
    struct App : AppT<App>
    {
        App();

        void OnLaunched(Microsoft::UI::Xaml::LaunchActivatedEventArgs const&);
        // 新增：加载和保存设置的方法（基于 LocalSettings）
        void LoadSettingsFromLocalSettings();
        void SaveSettingsToLocalSettings();
        void OnSuspending(
            winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Windows::ApplicationModel::SuspendingEventArgs const& args);

        // Resuming 事件处理方法
        void OnResuming(
            winrt::Windows::Foundation::IInspectable const& sender,
            winrt::Windows::Foundation::IInspectable const& args);


    private:
        winrt::Microsoft::UI::Xaml::Window window{ nullptr };
        winrt::event_token m_suspendingToken;
        winrt::event_token m_resumingToken;
    };
}
