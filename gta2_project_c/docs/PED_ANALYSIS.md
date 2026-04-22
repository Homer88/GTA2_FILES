# Ped Structure Analysis

## MAP File Data

### Constructor/Destructor
| Function | Address | Code Size | Notes |
|----------|---------|-----------|-------|
| `Ped__Ped` | 0x49E70 | 0x110 (272) bytes | Main constructor |
| `Ped__Ped_des` | 0x44660 | 0x50 (80) bytes | Destructor |
| `Ped__PedGroupCreate` | 0x4F350 | - | Create ped group |
| `Ped__PedGroupChangeLeader` | 0x44490 | - | Change group leader |

### Key Methods (231+ total)
- `Ped__SetSearchType` (0x403920)
- `Ped__SetCarId` (0x403940)
- `Ped__SetOccupation` (0x403970)
- `Ped__GetPositionX/Y` (0x403A00/0x403A10)
- `Ped__EnterCarAsPassenger` (0x4D350)
- `Ped__GiveWeapon` (0x4D4B0)
- `Ped__SetNPCWeapon` (0x4C830)
- `Ped__AreAnyPedActive` (0x4C010)

### Global Variables
- `gPed` at 0x0EF794
- `gPed1` at 0x0E7DE0
- `gPedManager` at 0x069BBC

## Structure Layout

### Estimated Size: 0xB0 (176) bytes
Based on constructor complexity and field analysis

### Block Organization:
1. **Links & ID** (0x00-0x0F): Next, Previous, ObjectID, CarID
2. **Position & Movement** (0x10-0x2F): Position, Velocity, Direction, State
3. **Health & Stats** (0x30-0x3F): Health, Armour, WantedLevel, Money
4. **Vehicle Interaction** (0x40-0x57): CurrentCar, TargetDoor, SeatIndex
5. **Combat & Weapons** (0x58-0x73): Weapon, TargetPed, AimDirection
6. **Group AI** (0x74-0x8F): Group, Leader, FollowTarget
7. **Animation** (0x90-0xAF): Animation state, Sprite data

## Passenger Structure

### MAP Data
- Constructor: 0x42FE90 (7 bytes)
- Destructor: 0x42FEA0 (7 bytes)
- Global: gPassenger at 0x5E5EE0

### Size: 0x0C (12) bytes
```c
struct Passenger {
    struct Passenger* Next;     // 0x0
    struct Ped* PedPtr;         // 0x4
    u8 State;                   // 0x8
    u8 Padding[3];              // 0x9-0xB
};
```

## Next Steps
1. Analyze constructor ASM to verify exact field offsets
2. Check for vtable usage (potential C++ class)
3. Verify size with static_assert after full ASM review
