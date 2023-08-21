

#include <iostream>
#include <Windows.h>
#include <HighLevelMonitorConfigurationAPI.h>
#pragma comment(lib, "Dxva2.lib")

int main()
{
    HWND hwnd = GetForegroundWindow();

    HMONITOR hmonitor;
    hmonitor = MonitorFromWindow(hwnd, MONITOR_DEFAULTTONEAREST);
    PHYSICAL_MONITOR arr[1];
    GetPhysicalMonitorsFromHMONITOR(hmonitor, 1, arr);
    DWORD min, curr, max = 0;
    if (GetMonitorBrightness(arr[0].hPhysicalMonitor, &min, &curr, &max))
    {

        std::cout << "Minimum: " << min << std::endl;
        std::cout << "Current: " << curr << std::endl;
        std::cout << "Maximum: " << max << std::endl;
        return 0;

    }
    std::cout << ": The error code is  " << GetLastError() << std::endl;

    getchar();
    return -1;
}