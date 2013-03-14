/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2011 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "SDL_config.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
/* *INDENT-ON* */
#endif

/* Interface from the SDL library into the Android Java activity */
extern DECLSPEC SDL_bool SDLCALL Android_JNI_CreateContext(int majorVersion, int minorVersion);
extern DECLSPEC void SDLCALL Android_JNI_SwapWindow();
extern DECLSPEC void SDLCALL Android_JNI_SetActivityTitle(const char *title);
extern DECLSPEC void SDLCALL Android_JNI_GetAccelerometerValues(float values[3]);

// Audio support
extern DECLSPEC int SDLCALL Android_JNI_OpenAudioDevice(int sampleRate, int is16Bit, int channelCount, int desiredBufferFrames);
extern DECLSPEC void* SDLCALL Android_JNI_GetAudioBuffer();
extern DECLSPEC void SDLCALL Android_JNI_WriteAudioBuffer();
extern DECLSPEC void SDLCALL Android_JNI_CloseAudioDevice();

// Threads
#include <jni.h>
static void Android_JNI_ThreadDestroyed(void*);
JNIEnv *Android_JNI_GetEnv(void);
int Android_JNI_SetupThread(void);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

/* vi: set ts=4 sw=4 expandtab: */