#ifndef IRSDK_UTILS_H
#define IRSDK_UTILS_H

#ifndef _WIN32_WINNT
#	define _WIN32_WINNT		MIN_WIN_VER
#endif

#define MIN_WIN_VER 0x0501

#ifndef WINVER
#	define WINVER			MIN_WIN_VER
#endif


#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

#ifdef _MSC_VER
#include <crtdbg.h>
#endif

#include "irsdk_defines.h"

// for timeBeginPeriod()
#pragma comment(lib, "Winmm")
// for RegisterWindowMessage() and SendMessage()
#pragma comment(lib, "User32")

class irsdk_utils{
public:
  bool irsdk_startup();
  void irsdk_shutdown();
  bool irsdk_getNewData(char *data);
  bool irsdk_waitForDataReady(int timeOut, char *data);
  bool irsdk_isConnected();
  const irsdk_header *irsdk_getHeader();
  const char *irsdk_getData(int index);
  const char *irsdk_getSessionInfoStr();
  const irsdk_varHeader *irsdk_getVarHeaderPtr();
  const irsdk_varHeader *irsdk_getVarHeaderEntry(int index);
  int irsdk_varNameToIndex(const char *name);
  int irsdk_varNameToOffset(const char *name);
  unsigned int irsdk_getBroadcastMsgID();
  void irsdk_broadcastMsg(irsdk_BroadcastMsg msg, int var1, int var2, int var3);
  void irsdk_broadcastMsg(irsdk_BroadcastMsg msg, int var1, float var2);
  void irsdk_broadcastMsg(irsdk_BroadcastMsg msg, int var1, int var2);
  int irsdk_padCarNum(int num, int zero);

private:
  // Local memory
  HANDLE hDataValidEvent = NULL;
  HANDLE hMemMapFile = NULL;

  const char *pSharedMem = NULL;
  const irsdk_header *pHeader = NULL;

  int lastTickCount = INT_MAX;
  bool isInitialized = false;

  const double timeout = 30.0; // timeout after 30 seconds with no communication
  time_t lastValidTime = 0;

  // Function Implementations

};

#endif // IRSDK_UTILS_H
