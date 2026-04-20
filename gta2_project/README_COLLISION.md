# Система коллизий для GTA2

## Обзор
Данный модуль реализует физику столкновений автомобилей в стиле GTA 2.

## Структуры

### math_types/vector2d.h
- `Vector2D` - 2D вектор (X, Y)
- Функции: Add, Sub, Mul, Div, Dot, Length, Normalize, Lerp, Rotate

### math_types/rect2d.h
- `Rect2D` - Ориентированный прямоугольник (OBB)
- Поля: Center, HalfSize, Angle, AxisX, AxisY
- Функции: Init, UpdateAxes, Intersects, ContainsPoint, GetVertices

### collision.h
- `CollisionResult` - Результат проверки столкновения
- `CollisionInfo` - Информация о последней аварии автомобиля
- Функции:
  - `Car_CheckCollision()` - основная проверка всех коллизий
  - `Car_CollisionOnCar()` - столкновение машина-машина
  - `Car_ApplyImpulse()` - применение импульса
  - `Car_ApplyDamage()` - расчет урона

## Интеграция с Car

Структура `Car` теперь содержит:
```c
Rect2D BoundingBox;       // OBB для проверок
CollisionInfo LastCollision; // Данные о последней аварии
```

## Алгоритм работы

1. **SAT (Separating Axis Theorem)** - используется для проверки пересечения OBB
2. **Импульсная физика** - расчет отскока с учетом масс и упругости
3. **Урон** - пропорционален силе удара, может заглушить двигатель

## Файлы

```
gta2_project/
├── include/
│   ├── math_types/
│   │   ├── vector2d.h
│   │   └── rect2d.h
│   ├── collision.h
│   └── car.h (обновлен)
└── src/
    ├── math_types/
    │   ├── vector2d.c
    │   └── rect2d.c
    └── collision.c
```

## Пример использования

```c
// В Car_Update или Car_Move:
CollisionResult result = Car_CheckCollision(myCar, &g_vehicle_pool);
if (result.HasCollision) {
    if (result.LastHit.ImpulseMagnitude > 10.0f) {
        // Серьезная авария
        PlayCrashSound();
    }
}
```
