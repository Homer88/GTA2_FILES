/**
 * @file Passenger.h
 * @brief Структура пассажира
 * 
 * Основано на: gta2.exe/ida_pro/gta2.exe.h (line 3687)
 */

#pragma once

struct Passenger
{
    Passenger* Passenger;     // 0x0000 - Предыдущий пассажир
    Passenger* PassengerPrev; // 0x0004 - Следующий пассажир
};

static_assert(sizeof(Passenger) == 0x8, "Passenger size mismatch");

#endif // PASSENGER_H
