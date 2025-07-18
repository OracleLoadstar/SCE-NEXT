// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.250303.1

#pragma once
#ifndef WINRT_Windows_System_UserProfile_2_H
#define WINRT_Windows_System_UserProfile_2_H
#include "winrt/impl/Windows.Foundation.Collections.1.h"
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.System.UserProfile.1.h"
WINRT_EXPORT namespace winrt::Windows::System::UserProfile
{
    struct AdvertisingManager
    {
        AdvertisingManager() = delete;
        [[nodiscard]] static auto AdvertisingId();
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct WINRT_IMPL_EMPTY_BASES AdvertisingManagerForUser : winrt::Windows::System::UserProfile::IAdvertisingManagerForUser
    {
        AdvertisingManagerForUser(std::nullptr_t) noexcept {}
        AdvertisingManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IAdvertisingManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES AssignedAccessSettings : winrt::Windows::System::UserProfile::IAssignedAccessSettings
    {
        AssignedAccessSettings(std::nullptr_t) noexcept {}
        AssignedAccessSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IAssignedAccessSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct WINRT_IMPL_EMPTY_BASES DiagnosticsSettings : winrt::Windows::System::UserProfile::IDiagnosticsSettings
    {
        DiagnosticsSettings(std::nullptr_t) noexcept {}
        DiagnosticsSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IDiagnosticsSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct WINRT_IMPL_EMPTY_BASES FirstSignInSettings : winrt::Windows::System::UserProfile::IFirstSignInSettings
    {
        FirstSignInSettings(std::nullptr_t) noexcept {}
        FirstSignInSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IFirstSignInSettings(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct GlobalizationPreferences
    {
        GlobalizationPreferences() = delete;
        [[nodiscard]] static auto Calendars();
        [[nodiscard]] static auto Clocks();
        [[nodiscard]] static auto Currencies();
        [[nodiscard]] static auto Languages();
        [[nodiscard]] static auto HomeGeographicRegion();
        [[nodiscard]] static auto WeekStartsOn();
        static auto TrySetHomeGeographicRegion(param::hstring const& region);
        static auto TrySetLanguages(param::iterable<hstring> const& languageTags);
        static auto GetForUser(winrt::Windows::System::User const& user);
    };
    struct WINRT_IMPL_EMPTY_BASES GlobalizationPreferencesForUser : winrt::Windows::System::UserProfile::IGlobalizationPreferencesForUser
    {
        GlobalizationPreferencesForUser(std::nullptr_t) noexcept {}
        GlobalizationPreferencesForUser(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IGlobalizationPreferencesForUser(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES UserProfilePersonalizationSettings : winrt::Windows::System::UserProfile::IUserProfilePersonalizationSettings
    {
        UserProfilePersonalizationSettings(std::nullptr_t) noexcept {}
        UserProfilePersonalizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::System::UserProfile::IUserProfilePersonalizationSettings(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto IsSupported();
    };
}
#endif
