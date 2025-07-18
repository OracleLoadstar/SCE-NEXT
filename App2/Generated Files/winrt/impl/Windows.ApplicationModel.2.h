// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.250303.1

#pragma once
#ifndef WINRT_Windows_ApplicationModel_2_H
#define WINRT_Windows_ApplicationModel_2_H
#include "winrt/impl/Windows.System.1.h"
#include "winrt/impl/Windows.ApplicationModel.1.h"
WINRT_EXPORT namespace winrt::Windows::ApplicationModel
{
    struct PackageInstallProgress
    {
        uint32_t PercentComplete {};
    };
    inline bool operator==(PackageInstallProgress const& left, PackageInstallProgress const& right) noexcept
    {
        return left.PercentComplete == right.PercentComplete;
    }
    inline bool operator!=(PackageInstallProgress const& left, PackageInstallProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct PackageVersion
    {
        uint16_t Major {};
        uint16_t Minor {};
        uint16_t Build {};
        uint16_t Revision {};
    };
    inline bool operator==(PackageVersion const& left, PackageVersion const& right) noexcept
    {
        return left.Major == right.Major && left.Minor == right.Minor && left.Build == right.Build && left.Revision == right.Revision;
    }
    inline bool operator!=(PackageVersion const& left, PackageVersion const& right) noexcept
    {
        return !(left == right);
    }
    struct WINRT_IMPL_EMPTY_BASES AppDisplayInfo : winrt::Windows::ApplicationModel::IAppDisplayInfo
    {
        AppDisplayInfo(std::nullptr_t) noexcept {}
        AppDisplayInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IAppDisplayInfo(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES AppInfo : winrt::Windows::ApplicationModel::IAppInfo,
        impl::require<AppInfo, winrt::Windows::ApplicationModel::IAppInfo2, winrt::Windows::ApplicationModel::IAppInfo3, winrt::Windows::ApplicationModel::IAppInfo4>
    {
        AppInfo(std::nullptr_t) noexcept {}
        AppInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IAppInfo(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto GetFromAppUserModelId(param::hstring const& appUserModelId);
        static auto GetFromAppUserModelIdForUser(winrt::Windows::System::User const& user, param::hstring const& appUserModelId);
    };
    struct WINRT_IMPL_EMPTY_BASES AppInstallerInfo : winrt::Windows::ApplicationModel::IAppInstallerInfo,
        impl::require<AppInstallerInfo, winrt::Windows::ApplicationModel::IAppInstallerInfo2>
    {
        AppInstallerInfo(std::nullptr_t) noexcept {}
        AppInstallerInfo(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IAppInstallerInfo(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES AppInstance : winrt::Windows::ApplicationModel::IAppInstance
    {
        AppInstance(std::nullptr_t) noexcept {}
        AppInstance(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IAppInstance(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto RecommendedInstance();
        static auto GetActivatedEventArgs();
        static auto FindOrRegisterInstanceForKey(param::hstring const& key);
        static auto Unregister();
        static auto GetInstances();
    };
    struct DesignMode
    {
        DesignMode() = delete;
        [[nodiscard]] static auto DesignModeEnabled();
        [[nodiscard]] static auto DesignMode2Enabled();
    };
    struct WINRT_IMPL_EMPTY_BASES EnteredBackgroundEventArgs : winrt::Windows::ApplicationModel::IEnteredBackgroundEventArgs
    {
        EnteredBackgroundEventArgs(std::nullptr_t) noexcept {}
        EnteredBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IEnteredBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES FindRelatedPackagesOptions : winrt::Windows::ApplicationModel::IFindRelatedPackagesOptions
    {
        FindRelatedPackagesOptions(std::nullptr_t) noexcept {}
        FindRelatedPackagesOptions(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IFindRelatedPackagesOptions(ptr, take_ownership_from_abi) {}
        explicit FindRelatedPackagesOptions(winrt::Windows::ApplicationModel::PackageRelationship const& Relationship);
    };
    struct WINRT_IMPL_EMPTY_BASES LeavingBackgroundEventArgs : winrt::Windows::ApplicationModel::ILeavingBackgroundEventArgs
    {
        LeavingBackgroundEventArgs(std::nullptr_t) noexcept {}
        LeavingBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::ILeavingBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES LimitedAccessFeatureRequestResult : winrt::Windows::ApplicationModel::ILimitedAccessFeatureRequestResult
    {
        LimitedAccessFeatureRequestResult(std::nullptr_t) noexcept {}
        LimitedAccessFeatureRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::ILimitedAccessFeatureRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct LimitedAccessFeatures
    {
        LimitedAccessFeatures() = delete;
        static auto TryUnlockFeature(param::hstring const& featureId, param::hstring const& token, param::hstring const& attestation);
    };
    struct WINRT_IMPL_EMPTY_BASES Package : winrt::Windows::ApplicationModel::IPackage,
        impl::require<Package, winrt::Windows::ApplicationModel::IPackage2, winrt::Windows::ApplicationModel::IPackage3, winrt::Windows::ApplicationModel::IPackageWithMetadata, winrt::Windows::ApplicationModel::IPackage4, winrt::Windows::ApplicationModel::IPackage5, winrt::Windows::ApplicationModel::IPackage6, winrt::Windows::ApplicationModel::IPackage7, winrt::Windows::ApplicationModel::IPackage8, winrt::Windows::ApplicationModel::IPackage9>
    {
        Package(std::nullptr_t) noexcept {}
        Package(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackage(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
    struct WINRT_IMPL_EMPTY_BASES PackageCatalog : winrt::Windows::ApplicationModel::IPackageCatalog,
        impl::require<PackageCatalog, winrt::Windows::ApplicationModel::IPackageCatalog2, winrt::Windows::ApplicationModel::IPackageCatalog3, winrt::Windows::ApplicationModel::IPackageCatalog4>
    {
        PackageCatalog(std::nullptr_t) noexcept {}
        PackageCatalog(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageCatalog(ptr, take_ownership_from_abi) {}
        static auto OpenForCurrentPackage();
        static auto OpenForCurrentUser();
        static auto OpenForPackage(winrt::Windows::ApplicationModel::Package const& package);
    };
    struct WINRT_IMPL_EMPTY_BASES PackageCatalogAddOptionalPackageResult : winrt::Windows::ApplicationModel::IPackageCatalogAddOptionalPackageResult
    {
        PackageCatalogAddOptionalPackageResult(std::nullptr_t) noexcept {}
        PackageCatalogAddOptionalPackageResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageCatalogAddOptionalPackageResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageCatalogAddResourcePackageResult : winrt::Windows::ApplicationModel::IPackageCatalogAddResourcePackageResult
    {
        PackageCatalogAddResourcePackageResult(std::nullptr_t) noexcept {}
        PackageCatalogAddResourcePackageResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageCatalogAddResourcePackageResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageCatalogRemoveOptionalPackagesResult : winrt::Windows::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult
    {
        PackageCatalogRemoveOptionalPackagesResult(std::nullptr_t) noexcept {}
        PackageCatalogRemoveOptionalPackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageCatalogRemoveOptionalPackagesResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageCatalogRemoveResourcePackagesResult : winrt::Windows::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult
    {
        PackageCatalogRemoveResourcePackagesResult(std::nullptr_t) noexcept {}
        PackageCatalogRemoveResourcePackagesResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageCatalogRemoveResourcePackagesResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageContentGroup : winrt::Windows::ApplicationModel::IPackageContentGroup
    {
        PackageContentGroup(std::nullptr_t) noexcept {}
        PackageContentGroup(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageContentGroup(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto RequiredGroupName();
    };
    struct WINRT_IMPL_EMPTY_BASES PackageContentGroupStagingEventArgs : winrt::Windows::ApplicationModel::IPackageContentGroupStagingEventArgs
    {
        PackageContentGroupStagingEventArgs(std::nullptr_t) noexcept {}
        PackageContentGroupStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageContentGroupStagingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageId : winrt::Windows::ApplicationModel::IPackageId,
        impl::require<PackageId, winrt::Windows::ApplicationModel::IPackageIdWithMetadata>
    {
        PackageId(std::nullptr_t) noexcept {}
        PackageId(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageId(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageInstallingEventArgs : winrt::Windows::ApplicationModel::IPackageInstallingEventArgs
    {
        PackageInstallingEventArgs(std::nullptr_t) noexcept {}
        PackageInstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageInstallingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageStagingEventArgs : winrt::Windows::ApplicationModel::IPackageStagingEventArgs
    {
        PackageStagingEventArgs(std::nullptr_t) noexcept {}
        PackageStagingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageStagingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageStatus : winrt::Windows::ApplicationModel::IPackageStatus,
        impl::require<PackageStatus, winrt::Windows::ApplicationModel::IPackageStatus2>
    {
        PackageStatus(std::nullptr_t) noexcept {}
        PackageStatus(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageStatus(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageStatusChangedEventArgs : winrt::Windows::ApplicationModel::IPackageStatusChangedEventArgs
    {
        PackageStatusChangedEventArgs(std::nullptr_t) noexcept {}
        PackageStatusChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageStatusChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageUninstallingEventArgs : winrt::Windows::ApplicationModel::IPackageUninstallingEventArgs
    {
        PackageUninstallingEventArgs(std::nullptr_t) noexcept {}
        PackageUninstallingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageUninstallingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageUpdateAvailabilityResult : winrt::Windows::ApplicationModel::IPackageUpdateAvailabilityResult
    {
        PackageUpdateAvailabilityResult(std::nullptr_t) noexcept {}
        PackageUpdateAvailabilityResult(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageUpdateAvailabilityResult(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES PackageUpdatingEventArgs : winrt::Windows::ApplicationModel::IPackageUpdatingEventArgs
    {
        PackageUpdatingEventArgs(std::nullptr_t) noexcept {}
        PackageUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IPackageUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES StartupTask : winrt::Windows::ApplicationModel::IStartupTask
    {
        StartupTask(std::nullptr_t) noexcept {}
        StartupTask(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::IStartupTask(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentPackageAsync();
        static auto GetAsync(param::hstring const& taskId);
    };
    struct WINRT_IMPL_EMPTY_BASES SuspendingDeferral : winrt::Windows::ApplicationModel::ISuspendingDeferral
    {
        SuspendingDeferral(std::nullptr_t) noexcept {}
        SuspendingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::ISuspendingDeferral(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES SuspendingEventArgs : winrt::Windows::ApplicationModel::ISuspendingEventArgs
    {
        SuspendingEventArgs(std::nullptr_t) noexcept {}
        SuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::ISuspendingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WINRT_IMPL_EMPTY_BASES SuspendingOperation : winrt::Windows::ApplicationModel::ISuspendingOperation
    {
        SuspendingOperation(std::nullptr_t) noexcept {}
        SuspendingOperation(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Windows::ApplicationModel::ISuspendingOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
