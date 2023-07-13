// To avoid conflicts with ctrulib, only include what we need 

#pragma once 

#ifdef PLATFORM_3DS 

#include <3ds/svc.h> 
#include <3ds/gfx.h> 
#include <3ds/services/apt.h> 

#define TICKS_PER_SEC 268123480.0 

#define KEY_TOUCH 0x100000

typedef struct { u16 x, y; } touchPosition;
typedef struct { s16 x, y; } circlePosition;

void hidScanInput(void);

uint32_t hidKeysHeld(void);
uint32_t hidKeysDown(void);
uint32_t hidKeysUp(void);

void hidTouchRead (touchPosition* pos);
void hidCircleRead(circlePosition* pos);
void irrstCstickRead(circlePosition* pos);

// Work around the VFP not supporting 64-bit integer <--> floating point conversion 
static inline double u64_to_double(u64 value) { 
	return (((double)(u32)(value >> 32))*0x100000000ULL+(u32)value); 
}

#endif
