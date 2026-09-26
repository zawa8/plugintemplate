// WINDOWS-ONLY (Win32 API + Notepad++ SDK).
#pragma once

#include "PluginInterface.h"

// Called from dllmain.cpp's setInfo export.
void setNppData(NppData notepadPlusData);

// Called from dllmain.cpp's getFuncsArray export.
FuncItem* getFuncsArray(int* nbF);

// Menu command callbacks (registered in getFuncsArray's table in
// PluginDefinition.cpp). Each replaces the current Scintilla selection
// with the transliterated text.
void menu_transliterate_xi38();
void menu_transliterate_u38();

void pluginCleanUp();
