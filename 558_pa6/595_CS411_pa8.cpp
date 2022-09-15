#include <iostream>
using namespace std;

int main()
{
    string str;
    bool exit = false;
    while (!exit)
    {
        cin >> str;
        if (str == "io")
        {
            system("wmic path CIM_LogicalDevice where \"Description like 'USB%'\" get /value");
            exit = true;
        }
        else
        {
            cout << "UnIdentified command\n";
        }
    }
    return 0;
}
/*------------------------OUTPUT--------------------------------

hj
UnIdentified command
jk
UnIdentified command
sat
UnIdentified command
pal
UnIdentified command
io


Availability=
Caption=Enhanced (101- or 102-key)
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_Keyboard
Description=USB Input Device
DeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_00\6&amp;1E1DD5B8&amp;0&amp;0000
ErrorCleared=
ErrorDescription=
InstallDate=
IsLocked=
LastErrorCode=
Layout=00004009
Name=Enhanced (101- or 102-key)
NumberOfFunctionKeys=12
Password=
PNPDeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_00\6&amp;1E1DD5B8&amp;0&amp;0000
PowerManagementCapabilities=
PowerManagementSupported=FALSE
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=USB Input Device
ClassGuid={745a17a0-74d3-11d0-b6fe-00a0c90f57da}
CompatibleID={"USB\Class_03&amp;SubClass_01&amp;Prot_01","USB\Class_03&amp;SubClass_01","USB\Class_03"}
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PnPEntity
Description=USB Input Device
DeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_00\6&amp;1E1DD5B8&amp;0&amp;0000
ErrorCleared=
ErrorDescription=
HardwareID={"USB\VID_C0F4&amp;PID_04E0&amp;REV_0110&amp;MI_00","USB\VID_C0F4&amp;PID_04E0&amp;MI_00"}
InstallDate=
LastErrorCode=
Manufacturer=(Standard system devices)
Name=USB Input Device
PNPClass=HIDClass
PNPDeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_00\6&amp;1E1DD5B8&amp;0&amp;0000
PowerManagementCapabilities=
PowerManagementSupported=
Present=TRUE
Service=HidUsb
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=USB Input Device
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PointingDevice
Description=USB Input Device
DeviceID=USB\VID_275D&amp;PID_0BA6\5&amp;396D75D&amp;0&amp;6
DeviceInterface=162
DoubleSpeedThreshold=
ErrorCleared=
ErrorDescription=
Handedness=
HardwareType=USB Input Device
InfFileName=input.inf
InfSection=HID_Inst.NT
InstallDate=
IsLocked=
LastErrorCode=
Manufacturer=(Standard system devices)
Name=USB Input Device
NumberOfButtons=0
PNPDeviceID=USB\VID_275D&amp;PID_0BA6\5&amp;396D75D&amp;0&amp;6
PointingType=2
PowerManagementCapabilities=
PowerManagementSupported=FALSE
QuadSpeedThreshold=
Resolution=
SampleRate=
Status=OK
StatusInfo=
Synch=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_USBController
Description=USB xHCI Compliant Host Controller
DeviceID=PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019&amp;REV_31\3&amp;11583659&amp;0&amp;A0
ErrorCleared=
ErrorDescription=
InstallDate=
LastErrorCode=
Manufacturer=Generic USB xHCI Host Controller
MaxNumberControlled=
Name=Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)
PNPDeviceID=PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019&amp;REV_31\3&amp;11583659&amp;0&amp;A0
PowerManagementCapabilities=
PowerManagementSupported=
ProtocolSupported=16
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9
TimeOfLastReset=


Availability=
Caption=USB Composite Device
ClassCode=
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_USBHub
CurrentAlternateSettings=
CurrentConfigValue=
Description=USB Composite Device
DeviceID=USB\VID_C0F4&amp;PID_04E0\5&amp;396D75D&amp;0&amp;2
ErrorCleared=
ErrorDescription=
GangSwitched=
InstallDate=
LastErrorCode=
Name=USB Composite Device
NumberOfConfigs=
NumberOfPorts=
PNPDeviceID=USB\VID_C0F4&amp;PID_04E0\5&amp;396D75D&amp;0&amp;2
PowerManagementCapabilities=
PowerManagementSupported=
ProtocolCode=
Status=OK
StatusInfo=
SubclassCode=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9
USBVersion=


Availability=
Caption=USB Root Hub (USB 3.0)
ClassCode=
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_USBHub
CurrentAlternateSettings=
CurrentConfigValue=
Description=USB Root Hub (USB 3.0)
DeviceID=USB\ROOT_HUB30\4&amp;B9EB813&amp;0&amp;0
ErrorCleared=
ErrorDescription=
GangSwitched=
InstallDate=
LastErrorCode=
Name=USB Root Hub (USB 3.0)
NumberOfConfigs=
NumberOfPorts=
PNPDeviceID=USB\ROOT_HUB30\4&amp;B9EB813&amp;0&amp;0
PowerManagementCapabilities=
PowerManagementSupported=
ProtocolCode=
Status=OK
StatusInfo=
SubclassCode=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9
USBVersion=


Availability=
Caption=USB Composite Device
ClassGuid={36fc9e60-c465-11cf-8056-444553540000}
CompatibleID={"USB\DevClass_00&amp;SubClass_00&amp;Prot_00","USB\DevClass_00&amp;SubClass_00","USB\DevClass_00","USB\COMPOSITE"}     
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PnPEntity
Description=USB Composite Device
DeviceID=USB\VID_C0F4&amp;PID_04E0\5&amp;396D75D&amp;0&amp;2
ErrorCleared=
ErrorDescription=
HardwareID={"USB\VID_C0F4&amp;PID_04E0&amp;REV_0110","USB\VID_C0F4&amp;PID_04E0"}
InstallDate=
LastErrorCode=
Manufacturer=(Standard USB Host Controller)
Name=USB Composite Device
PNPClass=USB
PNPDeviceID=USB\VID_C0F4&amp;PID_04E0\5&amp;396D75D&amp;0&amp;2
PowerManagementCapabilities=
PowerManagementSupported=
Present=TRUE
Service=usbccgp
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)
ClassGuid={36fc9e60-c465-11cf-8056-444553540000}
CompatibleID={"PCI\VEN_8086&amp;DEV_A12F&amp;REV_31","PCI\VEN_8086&amp;DEV_A12F","PCI\VEN_8086&amp;CC_0C0330","PCI\VEN_8086&amp;CC_0C03","PCI\VEN_8086","PCI\CC_0C0330","PCI\CC_0C03"}
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PnPEntity
Description=USB xHCI Compliant Host Controller
DeviceID=PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019&amp;REV_31\3&amp;11583659&amp;0&amp;A0
ErrorCleared=
ErrorDescription=
HardwareID={"PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019&amp;REV_31","PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019","PCI\VEN_8086&amp;DEV_A12F&amp;CC_0C0330","PCI\VEN_8086&amp;DEV_A12F&amp;CC_0C03"}
InstallDate=
LastErrorCode=
Manufacturer=Generic USB xHCI Host Controller
Name=Intel(R) USB 3.0 eXtensible Host Controller - 1.0 (Microsoft)
PNPClass=USB
PNPDeviceID=PCI\VEN_8086&amp;DEV_A12F&amp;SUBSYS_9C561019&amp;REV_31\3&amp;11583659&amp;0&amp;A0
PowerManagementCapabilities=
PowerManagementSupported=
Present=TRUE
Service=USBXHCI
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=USB Input Device
ClassGuid={745a17a0-74d3-11d0-b6fe-00a0c90f57da}
CompatibleID={"USB\Class_03&amp;SubClass_00&amp;Prot_00","USB\Class_03&amp;SubClass_00","USB\Class_03"}
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PnPEntity
Description=USB Input Device
DeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_01\6&amp;1E1DD5B8&amp;0&amp;0001
ErrorCleared=
ErrorDescription=
HardwareID={"USB\VID_C0F4&amp;PID_04E0&amp;REV_0110&amp;MI_01","USB\VID_C0F4&amp;PID_04E0&amp;MI_01"}
InstallDate=
LastErrorCode=
Manufacturer=(Standard system devices)
Name=USB Input Device
PNPClass=HIDClass
PNPDeviceID=USB\VID_C0F4&amp;PID_04E0&amp;MI_01\6&amp;1E1DD5B8&amp;0&amp;0001
PowerManagementCapabilities=
PowerManagementSupported=
Present=TRUE
Service=HidUsb
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=USB Input Device
ClassGuid={745a17a0-74d3-11d0-b6fe-00a0c90f57da}
CompatibleID={"USB\Class_03&amp;SubClass_01&amp;Prot_02","USB\Class_03&amp;SubClass_01","USB\Class_03"}
ConfigManagerErrorCode=0
ConfigManagerUserConfig=FALSE
CreationClassName=Win32_PnPEntity
Description=USB Input Device
DeviceID=USB\VID_275D&amp;PID_0BA6\5&amp;396D75D&amp;0&amp;6
ErrorCleared=
ErrorDescription=
HardwareID={"USB\VID_275D&amp;PID_0BA6&amp;REV_0100","USB\VID_275D&amp;PID_0BA6"}
InstallDate=
LastErrorCode=
Manufacturer=(Standard system devices)
Name=USB Input Device
PNPClass=HIDClass
PNPDeviceID=USB\VID_275D&amp;PID_0BA6\5&amp;396D75D&amp;0&amp;6
PowerManagementCapabilities=
PowerManagementSupported=
Present=TRUE
Service=HidUsb
Status=OK
StatusInfo=
SystemCreationClassName=Win32_ComputerSystem
SystemName=DESKTOP-QHQHEV9


Availability=
Caption=USB Root Hub (USB 3.0)
ClassGuid={36fc9e60-c465-11cf-8056-444553540000}
CompatibleID=*/