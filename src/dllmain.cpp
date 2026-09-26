// WINDOWS-ONLY. Built via GitHub Actions (see ../.github/workflows/) --
// not manually verified against a real Notepad++ install yet.
//
// Required exports for any Notepad++ plugin DLL: isUnicode, getName,
// setInfo, beNotified, messageProc, getFuncsArray -- signatures declared
// in PluginInterface.h, matched here exactly.
#include "PluginDefinition.h"

BOOL APIENTRY DllMain(HANDLE /*hModule*/, DWORD reasonForCall, LPVOID /*lpReserved*/) {
  switch (reasonForCall) {
    case DLL_PROCESS_ATTACH:
    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
      break;
  }
  return TRUE;
}

extern "C" __declspec(dllexport) void setInfo(NppData notepadPlusData) {
  setNppData(notepadPlusData);
}

extern "C" __declspec(dllexport) const wchar_t* getName() {
  return L"htr-xnglo";
}

extern "C" __declspec(dllexport) FuncItem* getFuncsArray(int* nbF) {
  return ::getFuncsArray(nbF);
}

extern "C" __declspec(dllexport) void beNotified(SCNotification* /*notifyCode*/) {
  // No notifications handled yet (pluginCleanUp() is a no-op currently).
}

extern "C" __declspec(dllexport) LRESULT messageProc(UINT /*Message*/, WPARAM /*wParam*/, LPARAM /*lParam*/) {
  return TRUE;
}

extern "C" __declspec(dllexport) BOOL isUnicode() {
  return TRUE;
}
