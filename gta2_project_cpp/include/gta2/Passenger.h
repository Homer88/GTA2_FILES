/**
 * @file Passenger.h
 * @brief Структура пассажира
 * 
 * Основано на: gta2.exe/ida_pro/gta2.exe.h (line 3687)
 */

#pragma once

struct Passenger
{
    Passenger* PassengerNext;     // 0x0000 - Следующий пассажир
    Passenger* PassengerPrev;     // 0x0004 - Предыдущий пассажир
};


