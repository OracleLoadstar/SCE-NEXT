// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.250303.1

#pragma once
#ifndef WINRT_App2_0_H
#define WINRT_App2_0_H
WINRT_EXPORT namespace winrt::Microsoft::UI::Xaml::Controls
{
    struct ToggleSwitch;
}
WINRT_EXPORT namespace winrt::Microsoft::UI::Xaml::Markup
{
    struct IXamlMetadataProvider;
}
WINRT_EXPORT namespace winrt::App2
{
    struct ICalculator_pg;
    struct IHome;
    struct IMainWindow;
    struct IResuit;
    struct ISetting;
    struct Calculator_pg;
    struct Home;
    struct MainWindow;
    struct Resuit;
    struct Setting;
    struct XamlMetaDataProvider;
}
namespace winrt::impl
{
    template <> struct category<winrt::App2::ICalculator_pg>{ using type = interface_category; };
    template <> struct category<winrt::App2::IHome>{ using type = interface_category; };
    template <> struct category<winrt::App2::IMainWindow>{ using type = interface_category; };
    template <> struct category<winrt::App2::IResuit>{ using type = interface_category; };
    template <> struct category<winrt::App2::ISetting>{ using type = interface_category; };
    template <> struct category<winrt::App2::Calculator_pg>{ using type = class_category; };
    template <> struct category<winrt::App2::Home>{ using type = class_category; };
    template <> struct category<winrt::App2::MainWindow>{ using type = class_category; };
    template <> struct category<winrt::App2::Resuit>{ using type = class_category; };
    template <> struct category<winrt::App2::Setting>{ using type = class_category; };
    template <> struct category<winrt::App2::XamlMetaDataProvider>{ using type = class_category; };
    template <> inline constexpr auto& name_v<winrt::App2::Calculator_pg> = L"App2.Calculator_pg";
    template <> inline constexpr auto& name_v<winrt::App2::Home> = L"App2.Home";
    template <> inline constexpr auto& name_v<winrt::App2::MainWindow> = L"App2.MainWindow";
    template <> inline constexpr auto& name_v<winrt::App2::Resuit> = L"App2.Resuit";
    template <> inline constexpr auto& name_v<winrt::App2::Setting> = L"App2.Setting";
    template <> inline constexpr auto& name_v<winrt::App2::XamlMetaDataProvider> = L"App2.XamlMetaDataProvider";
    template <> inline constexpr auto& name_v<winrt::App2::ICalculator_pg> = L"App2.ICalculator_pg";
    template <> inline constexpr auto& name_v<winrt::App2::IHome> = L"App2.IHome";
    template <> inline constexpr auto& name_v<winrt::App2::IMainWindow> = L"App2.IMainWindow";
    template <> inline constexpr auto& name_v<winrt::App2::IResuit> = L"App2.IResuit";
    template <> inline constexpr auto& name_v<winrt::App2::ISetting> = L"App2.ISetting";
    template <> inline constexpr guid guid_v<winrt::App2::ICalculator_pg>{ 0x635CA620,0xB77A,0x58B1,{ 0x9F,0xC1,0xCF,0x38,0x85,0x3B,0xE7,0xCB } }; // 635CA620-B77A-58B1-9FC1-CF38853BE7CB
    template <> inline constexpr guid guid_v<winrt::App2::IHome>{ 0x9E17E75E,0x37A1,0x5177,{ 0xB6,0x72,0x96,0xEB,0xCB,0xB5,0xF7,0x08 } }; // 9E17E75E-37A1-5177-B672-96EBCBB5F708
    template <> inline constexpr guid guid_v<winrt::App2::IMainWindow>{ 0xAC521E61,0x8FDF,0x52B6,{ 0xBF,0x8D,0x4D,0xAB,0x54,0x96,0x52,0xE7 } }; // AC521E61-8FDF-52B6-BF8D-4DAB549652E7
    template <> inline constexpr guid guid_v<winrt::App2::IResuit>{ 0xF690C5D1,0x159F,0x50C4,{ 0xBD,0xE0,0x18,0xAA,0x28,0x32,0x7A,0xDF } }; // F690C5D1-159F-50C4-BDE0-18AA28327ADF
    template <> inline constexpr guid guid_v<winrt::App2::ISetting>{ 0x00BC6989,0x72B1,0x5D2F,{ 0xB3,0x56,0xAB,0x89,0x44,0xF8,0x48,0x63 } }; // 00BC6989-72B1-5D2F-B356-AB8944F84863
    template <> struct default_interface<winrt::App2::Calculator_pg>{ using type = winrt::App2::ICalculator_pg; };
    template <> struct default_interface<winrt::App2::Home>{ using type = winrt::App2::IHome; };
    template <> struct default_interface<winrt::App2::MainWindow>{ using type = winrt::App2::IMainWindow; };
    template <> struct default_interface<winrt::App2::Resuit>{ using type = winrt::App2::IResuit; };
    template <> struct default_interface<winrt::App2::Setting>{ using type = winrt::App2::ISetting; };
    template <> struct default_interface<winrt::App2::XamlMetaDataProvider>{ using type = winrt::Microsoft::UI::Xaml::Markup::IXamlMetadataProvider; };
    template <> struct abi<winrt::App2::ICalculator_pg>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall get_MyProperty(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MyProperty(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<winrt::App2::IHome>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall get_MyProperty(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MyProperty(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<winrt::App2::IMainWindow>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall get_MyProperty(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MyProperty(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<winrt::App2::IResuit>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall get_MyProperty(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MyProperty(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<winrt::App2::ISetting>
    {
        struct WINRT_IMPL_NOVTABLE type : inspectable_abi
        {
            virtual int32_t __stdcall get_MyProperty(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MyProperty(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsShowWelcome(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_App2_ICalculator_pg
    {
        [[nodiscard]] auto MyProperty() const;
        auto MyProperty(int32_t value) const;
    };
    template <> struct consume<winrt::App2::ICalculator_pg>
    {
        template <typename D> using type = consume_App2_ICalculator_pg<D>;
    };
    template <typename D>
    struct consume_App2_IHome
    {
        [[nodiscard]] auto MyProperty() const;
        auto MyProperty(int32_t value) const;
    };
    template <> struct consume<winrt::App2::IHome>
    {
        template <typename D> using type = consume_App2_IHome<D>;
    };
    template <typename D>
    struct consume_App2_IMainWindow
    {
        [[nodiscard]] auto MyProperty() const;
        auto MyProperty(int32_t value) const;
    };
    template <> struct consume<winrt::App2::IMainWindow>
    {
        template <typename D> using type = consume_App2_IMainWindow<D>;
    };
    template <typename D>
    struct consume_App2_IResuit
    {
        [[nodiscard]] auto MyProperty() const;
        auto MyProperty(int32_t value) const;
    };
    template <> struct consume<winrt::App2::IResuit>
    {
        template <typename D> using type = consume_App2_IResuit<D>;
    };
    template <typename D>
    struct consume_App2_ISetting
    {
        [[nodiscard]] auto MyProperty() const;
        auto MyProperty(int32_t value) const;
        [[nodiscard]] auto IsShowWelcome() const;
    };
    template <> struct consume<winrt::App2::ISetting>
    {
        template <typename D> using type = consume_App2_ISetting<D>;
    };
}
#endif
