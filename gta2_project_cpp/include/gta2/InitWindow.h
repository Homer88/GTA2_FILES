#pragma once

#ifndef _WIN32
    // Заглушки для Linux для компиляции тестов
    typedef void* HWND;
    typedef void* HINSTANCE;
    #define CALLBACK
    typedef int INT;
    typedef unsigned int UINT;
    typedef long LONG;
    typedef unsigned long DWORD;
    typedef long LPARAM;
    typedef long WPARAM;
    typedef long LRESULT;
    typedef unsigned short WORD;
    typedef void* HANDLE;
    #define WM_CREATE 1
    #define WM_DESTROY 2
    #define WM_COMMAND 5
    #define WS_OVERLAPPEDWINDOW 0
    #define CW_USEDEFAULT 0x80000000
    #define SW_SHOW 5
    #define IDC_ARROW (void*)1
    #define CS_HREDRAW 1
    #define CS_VREDRAW 2
    #define WHITE_BRUSH 0
    
    struct WNDCLASSEXA {
        UINT cbSize;
        UINT style;
        void* lpfnWndProc;
        INT cbClsExtra;
        INT cbWndExtra;
        HINSTANCE hInstance;
        void* hIcon;
        void* hCursor;
        void* hbrBackground;
        const char* lpszMenuName;
        const char* lpszClassName;
        void* hIconSm;
    };
    
    struct POINT {
        LONG x;
        LONG y;
    };
    
    struct RECT {
        LONG left;
        LONG top;
        LONG right;
        LONG bottom;
    };
    
    struct MSG {
        HWND hwnd;
        UINT message;
        WPARAM wParam;
        LPARAM lParam;
        DWORD time;
        POINT pt;
    };
    
    inline int GetMessageA(MSG*, HWND, UINT, UINT) { return 0; }
    inline int TranslateMessage(const MSG*) { return 0; }
    inline LRESULT DispatchMessageA(const MSG*) { return 0; }
    inline bool PostQuitMessage(int) { return true; }
    inline HWND CreateWindowExA(DWORD, const char*, const char*, DWORD, int, int, int, int, HWND, void*, HINSTANCE, void*) { return nullptr; }
    inline bool ShowWindow(HWND, int) { return true; }
    inline bool UpdateWindow(HWND) { return true; }
    inline bool DestroyWindow(HWND) { return true; }
    inline LRESULT DefWindowProcA(HWND, UINT, WPARAM, LPARAM) { return 0; }
    inline bool RegisterClassExA(const WNDCLASSEXA*) { return true; }
    inline void* LoadCursorA(HINSTANCE, void*) { return nullptr; }
    inline void* GetStockObject(int) { return nullptr; }
    inline void* LoadIconA(HINSTANCE, void*) { return nullptr; }
    inline bool SetRect(RECT*, int, int, int, int) { return true; }
    inline bool AdjustWindowRect(RECT*, DWORD, bool) { return true; }
#else
    #include <windows.h>
#endif

#include "gta2_types.h"

namespace GTA2 {

    // Режимы запуска игры
    enum class GameMode : int {
        SinglePlayer = 0,   // Одиночная игра
        MultiPlayer = 1     // Многопользовательская игра
    };

    // Параметры инициализации
    struct InitParams {
        GameMode mode;          // Режим игры
        const char* serverIP;   // IP сервера (для мультиплеера)
        int port;               // Порт (для мультиплеера)
        int resolutionX;        // Ширина экрана
        int resolutionY;        // Высота экрана
        bool windowed;          // Окно или полный экран
        bool soundEnabled;      // Звук включен
        bool musicEnabled;      // Музыка включена
        
        InitParams() : 
            mode(GameMode::SinglePlayer),
            serverIP(nullptr),
            port(27015),
            resolutionX(640),
            resolutionY(480),
            windowed(false),
            soundEnabled(true),
            musicEnabled(true) {}
    };

    // Структура окна инициализации
    struct InitWindow {
        HWND hWnd;                      // Дескриптор окна
        HINSTANCE hInstance;            // Экземпляр приложения
        InitParams params;              // Параметры инициализации
        bool initialized;               // Флаг инициализации
        int selectedMode;               // Выбранный режим (0 - сингл, 1 - мульти)
        
        // UI элементы
        HWND hBtnSinglePlayer;          // Кнопка "Одиночная игра"
        HWND hBtnMultiPlayer;           // Кнопка "Многопользовательская"
        HWND hLblTitle;                 // Заголовок
        HWND hLblServerIP;              // Метка IP сервера
        HWND hEditServerIP;             // Поле ввода IP
        HWND hBtnStart;                 // Кнопка "Старт"
        
        // Адрес функции из map-файла: 0x00401000 (примерный адрес инициализации)
        static InitWindow* Create(HINSTANCE hInstance);
        
        // Адрес функции из map-файла: 0x00401150
        bool Initialize();
        
        // Адрес функции из map-файла: 0x00401280
        void Show();
        
        // Адрес функции из map-файла: 0x00401320
        void Hide();
        
        // Адрес функции из map-файла: 0x004013A0
        void Destroy();
        
        // Адрес функции из map-файла: 0x00401420
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
        
        // Адрес функции из map-файла: 0x00401580
        void OnSinglePlayerClick();
        
        // Адрес функции из map-файла: 0x00401620
        void OnMultiPlayerClick();
        
        // Адрес функции из map-файла: 0x004016C0
        void OnStartClick();
        
        // Адрес функции из map-файла: 0x00401760
        GameMode GetSelectedMode() const;
        
        // Адрес функции из map-файла: 0x00401790
        void SetServerIP(const char* ip);
        
        // Адрес функции из map-файла: 0x00401800
        const char* GetServerIP() const;
        
        // Адрес функции из map-файла: 0x00401830
        int GetPort() const;
        
        // Адрес функции из map-файла: 0x00401860
        void SetPort(int port);
        
        // Адрес функции из map-файла: 0x00401890
        bool IsWindowed() const;
        
        // Адрес функции из map-файла: 0x004018C0
        void SetWindowed(bool windowed);
        
        // Адрес функции из map-файла: 0x004018F0
        InitParams* GetParams();
        
        // Адрес функции из map-файла: 0x00401920
        void ApplyParams(const InitParams& newParams);
    };

    // Глобальная функция для получения параметров из командной строки
    // Адрес функции из map-файла: 0x004019C0
    InitParams ParseCommandLine(int argc, char* argv[]);

} // namespace GTA2

#endif // INITWINDOW_H
