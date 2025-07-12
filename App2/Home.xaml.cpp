#include "pch.h"
#include "Home.xaml.h"
#if __has_include("Home.g.cpp")
#include "Home.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t Home::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Home::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
