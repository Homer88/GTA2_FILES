#!/usr/bin/env python3
"""
Script to analyze and rename functions in GTA2 decompiled code
with meaningful names based on their functionality.
"""

import re
import os

# Function name mapping based on analysis
FUNCTION_RENAMES = {
    # Game class functions
    "Game::Game_FUN_003f113c": "Game__GetCurrentPlayerSlot",
    "Game::Game_FUN_003f11a8": "Game__FindNextActivePlayer",
    "Game::Game_FUN_003f1208": "Game__SwitchToNextPlayer",
    "Game::Game_FUN_003f12a8": "Game__CycleToNextPlayer",
    
    # Registry functions
    "Registry::GetrRplayNum": "Registry__GetReplayNumber",
    "Registry::Registry_FUN_003f1422": "Registry__InitReplaySettings",
    "Registry::FUN_00406250": "Registry__GetDwordValue",
    "Registry::RegNetwork": "Registry__InitNetworkSettings",
    "Registry::GetPlayerNameNetwork": "Registry__GetNetworkPlayerName",
    "Registry::FUN_00407930": "Registry__LoadAllSettings",
    
    # Replay functions
    "Replay::PlayReplay": "Replay__PlaySegment",
    "Replay::StartPlayReplay": "Replay__StartPlayback",
    
    # Mission functions
    "MissionManager::MissionManager_FUN_00476200": "MissionManager__StartMission",
    "MissionManager::FUN_003f163c": "MissionManager__UpdateMissionState",
    
    # File Manager functions
    "FileMgr::FUN_0044dbb0": "FileMgr__SetFilePath",
    "FileMgr::CloseFile": "FileMgr__Close",
    "FileMgr::Seek": "FileMgr__SeekPosition",
    "FileMgr::Read": "FileMgr__ReadData",
    "FileMgr::FileOpen": "FileMgr__OpenFile",
    
    # Sprite functions
    "SpriteS1::FUN_00401ad0": "SpriteS1__LinkToS3",
    
    # Car System functions
    "CarSystemManager::Clamp": "CarSystemManager__ClampValues",
    "CarSystemManager::FUN_00401c40": "CarSystemManager__AddCarToSystem",
    
    # Ped functions
    "Ped::SetSearchType": "Ped__SetSearchMode",
    "Ped::SetAutoClass4": "Ped__SetAIController",
    "Ped::SetCarId": "Ped__SetAssignedCarIndex",
    "Ped::S49_Set_FUN_00403950": "Ped__ClearFlags",
    "Ped::S49_FUN_00403960": "Ped__UpdateState",
    "Ped::SetOccupation": "Ped__SetCurrentOccupation",
    "Ped::GetOccupation": "Ped__GetCurrentOccupation",
    "Ped::GetCurrentState": "Ped__GetPedState",
    "Ped::SetHealthPlayer": "Ped__SetHealth",
    "Ped::SetTargetCarDoor": "Ped__SetTargetCarDoorIndex",
    "Ped::S49_Get_FUN_004039c0": "Ped__GetFlags1",
    "Ped::S49_Get_FUN_004039d0": "Ped__GetFlags2",
    "Ped::S49_Get_FUN_004039e0": "Ped__GetDamageState",
    "Ped::GetPositionX": "Ped__GetXCoordinate",
    "Ped::GetPositionY": "Ped__GetYCoordinate",
    "Ped::SetDefaut_Pararam0x228": "Ped__ResetSpecialParam",
    "Ped::SetDefault": "Ped__ResetToDefaults",
    "Ped::Ped_Set_FUN_00403a40": "Ped__Initialize",
    "Ped::S49_FUN_00403a50": "Ped__SetFlags",
    "Ped::S49_Get_FUN_00403a60": "Ped__GetAnimationState",
    "Ped::S49_FUN_00403a70": "Ped__SetAnimationState",
    "Ped::S49_Get_FUN_00403a80": "Ped__GetActionParam",
    "Ped::GetCurrentAction": "Ped__GetCurrentAction",
    "Ped::S49_FUN_00403aa0": "Ped__EnterCar",
    "Ped::GetCarPed": "Ped__GetVehicle",
    "Ped::SetDriverPed": "Ped__SetAsDriver",
    "Ped::S49_Get_FUN_00403ad0": "Ped__GetPassenger",
    "Ped::SetLinkedPed": "Ped__SetLinkedPedestrian",
    "Ped::GetPed": "Ped__GetLinkedPed",
    "Ped::SetObjectiveTargetCar": "Ped__SetTargetVehicle",
    "Ped::GetCurrentCar": "Ped__GetCurrentVehicle",
    "Ped::SetCarDamageState": "Ped__SetVehicleDamageState",
    "Ped::SetExitAnimState": "Ped__SetExitAnimationState",
    "Ped::S49_Get_FUN_00403b70": "Ped__GetExitAnimState",
    "Ped::IsInCar": "Ped__IsInsideVehicle",
    "Ped::IsCrouching": "Ped__GetStance",
    
    # Car functions
    "Car::isSWATVANOrBankVan": "Car__IsSpecialVehicle",
    
    # S169 (Ped Manager) functions
    "S169::AreAnyPedActive": "PedManager__HasActivePeds",
    "S169::FUN_00403be0": "PedManager__UpdateAll",
    "S169::S169_FUN_00403c40": "PedManager__CheckPedStatus",
    "S169::FUN_00403da0": "PedManager__ProcessPeds",
    "S169::FUN_00403e90": "PedManager__UpdatePedStates",
    "S169::FUN_00403fb0": "PedManager__HandlePedAction",
    "S169::FUN_00404120": "PedManager__SetPedIndex",
    "S169::FUN_00404450": "PedManager__GetPedCount",
    "S169::FUN_00404480": "PedManager__ClearAll",
    "S169::FUN_00404490": "PedManager__GetPedByIndex",
    "S169::FUN_00404d40": "PedManager__RemovePed",
    "S169::FUN_00404ef0": "PedManager__ProcessGroup",
    "S169::FUN_00405240": "PedManager__UpdateGroup",
    
    # AutoClass4 (AI Controller) functions
    "AutoClass4::~AutoClass4": "AIController__Destructor",
    "AutoClass4::FUN_004038e0": "AIController__Initialize",
    "AutoClass4::FUN_00404400": "AIController__AssignPed",
    "AutoClass4::FUN_00404420": "AIController__SetPedIndex",
    "AutoClass4::FUN_004045d0": "AIController__Update",
    "AutoClass4::FUN_004046f0": "AIController__ProcessPed",
    "AutoClass4::FUN_00405760": "AIController__ExecuteAction",
    
    # GameObject functions
    "GameObject::GetCar": "GameObject__GetVehicle",
    "GameObject::FUN_00403910": "GameObject__LinkTo",
    
    # Utility functions
    "FUN_003f1004": "FindNearestPlayer",
    "FUN_003f10b0": "Callback_MissionComplete",
    "FUN_003f1314": "CheckPlayerLimit",
    "FUN_003f1338": "ValidatePlayerAction",
    "FUN_003f135c": "ShouldPauseGame",
    "FUN_003f1380": "SaveGameData",
    "FUN_003f14c0": "CopyObject",
    "FUN_003f14d8": "InitializeGlobals",
    "FUN_003f158c": "ProcessReplayData",
    "FUN_003f15bc": "InitReplaySystem",
    "FUN_003f1614": "GetMissionStatus",
    "FUN_003f1674": "UpdateMissionTimer",
    "FUN_003f1afa": "MainGameLoop",
    "FUN_00401050": "Math_ScaleVector",
    "FUN_00401080": "Math_RotatePoint",
    "FUN_004010e0": "Math_TransformCoords",
    "FUN_00401180": "Math_CalculateNormal",
    "FUN_004012c0": "Renderer_SetTransform",
    "FUN_004012f0": "Renderer_Reset",
    "FUN_004018a0": "Pool_Allocate",
    "FUN_004018c0": "Pool_Free",
    "FUN_004019a0": "Pool_Init",
    "FUN_00401ae0": "Decoder_SetValue",
    "bitShiftLeft1": "Decoder_ShiftLeft",
    "DecoderFloat": "Decoder_DecodeFloat",
    "S110_FUN_00401b40": "Decoder_ProcessData",
    "FUN_00401b90": "Decoder_ReadInt",
    "FUN_00401c60": "CarPool_Get",
    "FUN_00401c80": "PedPool_Get",
    "FUN_00401d20": "String_ParseLine",
    "FUN_00402180": "DataStream_Read",
    "FUN_004021e0": "DataStream_Allocate",
    "FUN_004023e0": "DataStream_Close",
    "Fread": "DataStream_ReadBlock",
    "Style::FUN_00402cf0": "StyleLoader_Load",
    "FUN_00402f00": "ErrorHandler_Init",
    "Error": "ErrorHandler_Throw",
    "FUN_00403040": "Checksum_Calculate",
    "InitDirectX": "DirectX_Initialize",
    "FUN_004035a0": "Direct3D_CreateDevice",
    "FUN_004035e0": "Direct3D_SetRenderState",
    "FUN_00403650": "Direct3D_CheckCaps",
    "FUN_00403770": "Texture_Load",
    "FUN_00403780": "Texture_Find",
    "FUN_00403840": "Matrix_Multiply",
    "FUN_00403870": "Matrix_Identity",
    "PedGroupAddPed": "PedGroup_AddMember",
    "FUN_00404ce0": "PedGroup_RemoveMember",
    "FUN_004048a0": "PathFind_CalculateRoute",
    "FUN_00404900": "PathFind_SetTarget",
    "FUN_00404ad0": "PathFind_UpdatePosition",
    "CreateBuffer": "Memory_Allocate",
    "FUN_00405a40": "Memory_Free",
    "FUN_00405a50": "Memory_Set",
    "ShowWindows": "UI_ShowWindow",
    "FUN_00405b10": "UI_CreateDialog",
    "FUN_00405b20": "UI_DestroyDialog",
    "FUN_00405b50": "UI_SetTextW",
    "__chkstk": "Stack_Check",
    "FUN_004061c0": "Config_Load",
    "FUN_00406210": "Config_GetInt",
    "FUN_00406220": "Config_GetBool",
    "FUN_00406230": "Config_GetFloat",
    "FUN_00406240": "Config_GetString",
    "FUN_004063c0": "Network_Connect",
    "FUN_00406450": "Network_SendData",
    "FUN_00406470": "Network_ReceiveData",
    "FUN_0040653e": "Network_Disconnect",
    "FUN_00406550": "String_Hash1",
    "FUN_00406570": "String_Hash2",
    "FUN_00406590": "String_Hash3",
    "MessageBoXErrorOpenFile": "UI_ShowFileError",
    "FUN_004065f0": "UI_InitDialog",
    "FUN_00406660": "UI_CloseDialog",
    "FUN_0040667c": "UI_SetControlText",
    "FUN_004066e0": "UI_CreateButton",
    "FUN_00406720": "UI_CreateLabel",
    "FUN_004068c0": "UI_CreateEdit",
    "FUN_00406980": "UI_CreateListBox",
    "FUN_00406b10": "UI_CreateCombo",
    "FUN_00406b80": "UI_CreateCheckbox",
    "FUN_00406bc0": "UI_AllocateControl",
    "FUN_00406be0": "Registry_Init",
    "FUN_00406c92": "UI_SetEnabled",
    "FUN_00406cc0": "UI_SetTextW2",
    "FUN_00406e40": "UI_DestroyControl",
    "FUN_00406f20": "UI_GetTextW",
    "FUN_00407030": "UI_CopyData",
    "FUN_00407070": "UI_ClearData",
    "FUN_0040720d": "UI_SetProperty",
    "FUN_00407362": "UI_UpdateLayout",
    "FUN_004073d0": "UI_ProcessMessage",
    "FUN_00407402": "UI_HandleInput",
    "FUN_00407476": "Debug_Print",
    "FUN_0040748d": "Debug_Update",
    "FUN_004075c0": "Console_AddLine",
    "FUN_00407800": "Options_LoadFromRegistry",
    "FUN_00407c90": "Multiplayer_JoinGame",
    "FUN_00407d10": "Multiplayer_LeaveGame",
    "FUN_00407d8b": "Multiplayer_UpdateLobby",
    "FUN_004086a0": "WindowProc_Handler",
}

def generate_rename_script():
    """Generate a comprehensive rename script."""
    
    # Read the original .c file
    c_file_path = "/workspace/gta2.exe/gid/gta2.exe.c"
    h_file_path = "/workspace/gta2.exe/gid/gta2.exe.h"
    
    with open(c_file_path, 'r', encoding='utf-8') as f:
        c_content = f.read()
    
    with open(h_file_path, 'r', encoding='utf-8') as f:
        h_content = f.read()
    
    # Apply renames
    for old_name, new_name in FUNCTION_RENAMES.items():
        # Escape special regex characters
        old_escaped = re.escape(old_name)
        
        # Replace function definitions in .c file
        # Pattern: old_name( or old_name::old_name(
        c_content = re.sub(
            rf'\b{old_escaped}(?=\s*\(|::)',
            new_name,
            c_content
        )
        
        # Replace in .h file
        h_content = re.sub(
            rf'\b{old_escaped}(?=\s*\(|::)',
            new_name,
            h_content
        )
    
    # Write updated files
    output_c_path = "/workspace/gta2_project/src/gta2_renamed.c"
    output_h_path = "/workspace/gta2_project/include/gta2_renamed.h"
    
    with open(output_c_path, 'w', encoding='utf-8') as f:
        f.write(c_content)
    
    with open(output_h_path, 'w', encoding='utf-8') as f:
        f.write(h_content)
    
    print(f"Renamed {len(FUNCTION_RENAMES)} functions")
    print(f"Output files:")
    print(f"  - {output_c_path}")
    print(f"  - {output_h_path}")
    
    return FUNCTION_RENAMES

if __name__ == "__main__":
    renames = generate_rename_script()
    print("\nFunction renames applied:")
    for old, new in sorted(renames.items()):
        print(f"  {old} -> {new}")
