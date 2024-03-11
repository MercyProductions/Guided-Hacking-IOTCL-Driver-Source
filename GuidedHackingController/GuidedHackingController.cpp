#include <iostream>
#include "kernelinterface.hpp"

int main()
{
    KernelInterface Driver = KernelInterface("\\\\.\\guidedhacking");
    ULONG address = Driver.GetClientAddress();
    ULONG processid = Driver.GetProcessID();

    std::cout << " ClientAddress " << std::hex <<address << std::endl;
    std::cout << " ProcessID " << processid << std::endl;

    std::cout << "Hello World!\n";

    while (true)
    {
        ULONG Offset = 0x4511919765;
        uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address + Offset, sizeof(uint32_t));

        // READ
        float num = Driver.ReadVirtualMemory<float>(processid, Offset, sizeof(float));
        std::cout << " Offset Return Value : " << num << std::endl;

        // WRITE
        Driver.WriteVirtualMemory(processid, LocalPlayerAddress + Offset, 0.f, sizeof(float));
    }
}

