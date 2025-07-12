#include "pch.h"
#include "Resuit.xaml.h"
#if __has_include("Resuit.g.cpp")
#include "Resuit.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t Resuit::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Resuit::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
