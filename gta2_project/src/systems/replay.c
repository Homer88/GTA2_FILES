// Module: replay
// Generated from gta2.exe.c
// Functions count: 25

#include "common.h"

// Было: Registry::GetReplayNum
int __thiscall Registry_GetReplayNum(Registry *this, LPCSTR param_1, byte param_2)


void __thiscall Replay_PlaySegment(Replay *this, char *Part)


void __thiscall Replay_StartPlayback(Replay *this)


bool __thiscall Replay_IsPlayingBack(Replay *this)


// Было: FUN_0044aa80
void* __thiscall Replay_InitBuffer(Replay *this)


byte __thiscall Replay_GetButton(Replay *this, int button)


void __thiscall fPlayReplay(void *this)


// Было: FUN_0045ad90
void __thiscall Replay_ResetState(Replay *this)


// Было: cInput_FUN_0045ed00
void __thiscall Replay_ProcessInput(Replay *this)


void __thiscall Replay_SetButton(Replay *this, int button)


void __thiscall Replay_ClearButton(Replay *this, int button)


// Было: Replay_FUN_0045eec0
void __thiscall Replay_StopPlayback(Replay *this)


// Было: cInput_FUN_0045f270
void __thiscall Replay_SetInputActive(Replay *this, bool param_1)


void __thiscall Replay_GetNextDataAttractAtt(Replay *this, char *DataAttractAtt)


// Было: Input_FUN_0045f640
void __thiscall Replay_StoreInput(Replay *this, void *param_1)


// Было: FUN_0045f900
void __thiscall Replay_EndRecording(Replay *this)


// Было: Replay_FUN_0045f970
byte __thiscall Replay_CheckStatus(Replay *this)


// Было: FUN_0045f990
void __thiscall Replay_ClearData(Replay *this)


// Было: FUN_0045fa00
void* __thiscall Replay_GetDataPtr(Replay *this)


// Было: FUN_0045fa50
void __thiscall Replay_SetFrame(Replay *this, uint param_1)


// Было: Replay_FUN_0045fb10
void __thiscall Replay_FlushData(Replay *this)


// Было: FUN_0045fba0
void __thiscall Replay_ReadInputs(Replay *this, uint *param_1)


// Было: FUN_0045fc20
void __thiscall Replay_WriteInputs(Replay *this, uint param_1, uint param_2)


// Было: FUN_0045fd10
uint __thiscall Replay_GetCurrentFrame(Replay *this)


// Было: Set_FUN_004d09b0
void __thiscall Replay_SetMode(Replay *this, byte param_1)


