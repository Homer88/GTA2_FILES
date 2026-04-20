# Отчёт о переименовании функций GTA 2 Reversing Project

## Статус на момент завершения

### Обработанные файлы (structures/)

**Часть 1:** Animation.c, BrakeInfo.c, BuildingModel.c, BusInfo.c, Camera.c, CarGenerator.c, CarModel.c
- ~35 функций переименовано

**Часть 2:** Checkpoint.c, CollisionBox.c, ColorRGBA.c, Controller.c
- ~40 функций переименовано

**Часть 3:** CrashData.c, DamageInfo.c, DebrisInfo.c, DecalInfo.c, EngineInfo.c, EventHandler.c, ExplosionInfo.c, FenceInfo.c, FireInfo.c, FiretruckInfo.c, GameObject.c, GameState.c, GangInfo.c, GarageInfo.c
- ~50 функций переименовано

**Часть 4:** GlassInfo.c, HeadlightInfo.c, HelicopterInfo.c, HudElement.c, ImpactInfo.c, JetInfo.c, LevelInfo.c, LightInfo.c, LinkedList.c, LoadScreen.c, Matrix3D.c, MemoryBlock.c, MenuInfo.c, MissionData.c, ModelIndex.c, MusicTrack.c
- ~55 функций переименовано

**Часть 5:** NetworkPlayer.c, ObjectModel.c, ObjectPool.c, PacketInfo.c, ParkingSpot.c, Particle.c, PathNode.c, PedGenerator.c, PedModel.c, PedPool.c, PedStats.c, PhoneCall.c, PickupInfo.c, Plane3D.c, PlaneInfo.c, Point2D.c, PoliceInfo.c, Powerup.c, Radar.c, RadioStation.c, Rect2D.c, ReflectionInfo.c, RenderQueue.c, RouteInfo.c
- ~70 функций переименовано

**Часть 6:** SaveGameData.c, ScriptCommand.c, ScriptThread.c, ScriptVar.c, ShadowInfo.c, SirenInfo.c, SkidmarkInfo.c, SmokeInfo.c, SoundInfo.c, SpawnPoint.c, SpeechInfo.c, Sphere3D.c, SpriteInfo.c, StainInfo.c, SteeringInfo.c, SubmarineInfo.c, SuspensionInfo.c, TaillightInfo.c, TaxiInfo.c, Teleporter.c, TextLabel.c, TextureInfo.c, TimeCycle.c, TrafficCar.c, TrafficLight.c, TrainInfo.c, TransmissionInfo.c, TriggerVolume.c, Vector3D.c, VehiclePool.c, VertexBuffer.c, Viewport.c, WantedLevel.c, WaterInfo.c, WeaponInfo.c, Weather.c, WheelInfo.c, s65.c, s66.c, s67.c, other.c
- ~120 функций переименовано

## Итого переименовано: ~370+ функций

## Оставшиеся FUN_XXXXXX ссылки: ~2033

Это внутренние вызовы функций, которые требуют дополнительного анализа для корректного переименования.

## Конвенции именования

| Паттерн IDA Pro | Новое имя | Пример |
|----------------|-----------|--------|
| `SXX__SXX` | `ClassName_ctor` | `S27__S27` → `S27_ctor` |
| `SXX__FUN_XXXXXXXX` | `ClassName_ActionName` | `S124__GetS125` → `BrakeInfo_GetCurrent` |
| `FUN_XXXXXXXX` (внутри) | `HelperFunction` | `FUN_004751b0` → `S28_dtor` |

## Следующие шаги

1. Обработать файлы в папках:
   - `src/world/`
   - `src/ai/`
   - `src/systems/`
   - `src/platform/`
   - `src/ui/`
   - `src/network/`

2. Создать карту соответствий старых и новых имён функций

3. Обновить заголовочные файлы (.h) с новыми прототипами

## Дата завершения: $(date)
