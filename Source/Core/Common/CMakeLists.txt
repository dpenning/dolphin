set(SRCS BreakPoints.cpp
         CDUtils.cpp
         ColorUtil.cpp
         FileSearch.cpp
         FileUtil.cpp
         GameState.cpp
         Hash.cpp
         IniFile.cpp
         MathUtil.cpp
         MemArena.cpp
         MemoryUtil.cpp
         Misc.cpp
         MsgHandler.cpp
         NandPaths.cpp
         Network.cpp
         PcapFile.cpp
         SettingsHandler.cpp
         SDCardUtil.cpp
         StringUtil.cpp
         SymbolDB.cpp
         SysConf.cpp
         Thread.cpp
         Timer.cpp
         Version.cpp
         x64ABI.cpp
         x64Analyzer.cpp
         x64Emitter.cpp
         Crypto/bn.cpp
         Crypto/ec.cpp
         Logging/ConsoleListener.cpp
         Logging/LogManager.cpp)


if(_M_ARM_32) #ARMv7
    set(SRCS ${SRCS}
         ArmCPUDetect.cpp
         ArmEmitter.cpp
         GenericFPURoundMode.cpp)
elseif(_M_X86) #X86
    set(SRCS ${SRCS}
         x64CPUDetect.cpp
         x64FPURoundMode.cpp)
else() #Generic
    set(SRCS ${SRCS}
         GenericFPURoundMode.cpp
         x64CPUDetect.cpp)
endif()
if(WIN32)
    set(SRCS ${SRCS} ExtendedTrace.cpp)
endif(WIN32)

enable_precompiled_headers(stdafx.h stdafx.cpp SRCS)

add_dolphin_library(common "${SRCS}" "${CMAKE_THREAD_LIBS_INIT}")
