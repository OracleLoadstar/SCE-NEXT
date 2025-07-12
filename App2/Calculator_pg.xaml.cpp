#include "pch.h"
#include "Calculator_pg.xaml.h"
#if __has_include("Calculator_pg.g.cpp")
#include "Calculator_pg.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App2::implementation
{
    int32_t Calculator_pg::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Calculator_pg::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
