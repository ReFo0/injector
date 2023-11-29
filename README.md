## A simple dll injector for Windows based on WINAPI's LoadLibrary function. Ring3 Injector project
![](https://img.shields.io/github/stars/refo0/injector)
![](https://img.shields.io/github/forks/refo0/injector)
## What is NtSetSystemTime 

NtSetSystemTime is a Windows operating system function. This function is used to change the system time. However, it is not recommended to use this function directly, and it is typically utilized by software developers working on low-level processes in the Windows operating system.

This function is part of the Native API (Nt) functions in Windows NT-based operating systems. Such functions are generally not directly called by user applications and are commonly used by software development libraries that provide low-level access to the operating system kernel or services.

However, low-level operations like these can often lead to security issues, and direct manipulation of operating system resources is generally discouraged. Users typically adjust the system time through high-level APIs or tools provided by the operating system. For example, on Windows, the system time is usually modified by changing the time and date in the taskbar or through the Date and Time settings in the Control Panel.

## What is Loadlibary

LoadLibrary is a function within the Windows API. This function is used to load a dynamic-link library (DLL) into the address space of a process. DLLs contain code and data that multiple programs can use simultaneously. By using LoadLibrary, a program can access the functionality provided by a DLL.

##

![image](https://github.com/ReFo0/injector/assets/77904942/1915078c-b6bf-4523-a209-e0a3c7515169)
