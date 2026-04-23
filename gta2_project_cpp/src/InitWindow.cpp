#include "gta2/InitWindow.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>

#ifndef _WIN32
    #include <unistd.h>
    // Эмуляция Windows API для Linux (заглушки)
    #define _strdup strdup
    #define MessageBox(hwnd, text, caption, type) printf("[%s] %s\n", caption, text)
    #define MB_OK 0
    #define MB_ICONINFORMATION 0
    #define MB_ICONWARNING 0
    #define GetWindowTextA(hwnd, buf, size) snprintf(buf, size, "127.0.0.1")
    // Заглушки для WinAPI типов и функций
    #define WNDCLASSEX WNDCLASSEXA
    #define LoadCursor(a, b) nullptr
    #define IDC_ARROW nullptr
    #define HBRUSH void*
    #define COLOR_WINDOW 0
    #define RegisterClassEx(a) 1
    #define CreateWindowEx(a, b, c, d, e, f, g, h, i, j, k, l) nullptr
    #define WS_OVERLAPPEDWINDOW 0
    #define WS_THICKFRAME 0
    #define WS_MAXIMIZEBOX 0
    #define WS_CHILD 0
    #define WS_VISIBLE 0
    #define SS_CENTER 0
    #define BS_PUSHBUTTON 0
    #define SW_HIDE 0
    #define WS_EX_CLIENTEDGE 0
    #define ES_AUTOHSCROLL 0
    #define LOWORD(x) (x)
    #define DefWindowProc(a, b, c, d) 0
    #define UnregisterClass(a, b)
    #define ShowWindow(a, b)
#endif

namespace GTA2 {

    // Глобальный указатель на текущее окно инициализации
    static InitWindow* g_pInitWindow = nullptr;

    // Адрес функции из map-файла: 0x00401000
    InitWindow* InitWindow::Create(HINSTANCE hInstance) {
        InitWindow* pWindow = new InitWindow();
        pWindow->hInstance = hInstance;
        pWindow->initialized = false;
        pWindow->selectedMode = 0;
        pWindow->hWnd = NULL;
        pWindow->hBtnSinglePlayer = NULL;
        pWindow->hBtnMultiPlayer = NULL;
        pWindow->hLblTitle = NULL;
        pWindow->hLblServerIP = NULL;
        pWindow->hEditServerIP = NULL;
        pWindow->hBtnStart = NULL;
        
        g_pInitWindow = pWindow;
        return pWindow;
    }

    // Адрес функции из map-файла: 0x00401150
    bool InitWindow::Initialize() {
        if (initialized) {
            return true;
        }

        // Регистрация класса окна
        WNDCLASSEX wc = {};
        wc.cbSize = sizeof(WNDCLASSEX);
        wc.style = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc = WndProc;
        wc.hInstance = hInstance;
        wc.hCursor = LoadCursor(NULL, IDC_ARROW);
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
        wc.lpszClassName = "GTA2_InitWindow";
        
        if (!RegisterClassEx(&wc)) {
            return false;
        }

        // Создание окна
        hWnd = CreateWindowEx(
            0,
            "GTA2_InitWindow",
            "GTA 2 - Инициализация",
            WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
            CW_USEDEFAULT, CW_USEDEFAULT,
            400, 300,
            NULL, NULL,
            hInstance,
            NULL
        );

        if (!hWnd) {
            return false;
        }

        // Создание элементов управления
        int btnWidth = 150;
        int btnHeight = 40;
        int startY = 50;
        int gap = 60;

        // Заголовок
        hLblTitle = CreateWindowEx(
            0, "STATIC", "Выберите режим игры",
            WS_CHILD | WS_VISIBLE | SS_CENTER,
            50, 10, 300, 30,
            hWnd, NULL, hInstance, NULL
        );

        // Кнопка "Одиночная игра"
        hBtnSinglePlayer = CreateWindowEx(
            0, "BUTTON", "Одиночная игра",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            (400 - btnWidth) / 2, startY, btnWidth, btnHeight,
            hWnd, (HMENU)1001, hInstance, NULL
        );

        // Кнопка "Многопользовательская"
        hBtnMultiPlayer = CreateWindowEx(
            0, "BUTTON", "Многопользовательская",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            (400 - btnWidth) / 2, startY + gap, btnWidth, btnHeight,
            hWnd, (HMENU)1002, hInstance, NULL
        );

        // Метка IP сервера (скрыта по умолчанию)
        hLblServerIP = CreateWindowEx(
            0, "STATIC", "IP сервера:",
            WS_CHILD | WS_VISIBLE,
            50, startY + gap * 2, 100, 20,
            hWnd, NULL, hInstance, NULL
        );
        ShowWindow(hLblServerIP, SW_HIDE);

        // Поле ввода IP (скрыто по умолчанию)
        hEditServerIP = CreateWindowEx(
            WS_EX_CLIENTEDGE, "EDIT", "",
            WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            160, startY + gap * 2, 180, 20,
            hWnd, NULL, hInstance, NULL
        );
        ShowWindow(hEditServerIP, SW_HIDE);

        // Кнопка "Старт"
        hBtnStart = CreateWindowEx(
            0, "BUTTON", "Старт",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            (400 - btnWidth) / 2, startY + gap * 3, btnWidth, btnHeight,
            hWnd, (HMENU)1003, hInstance, NULL
        );

        initialized = true;
        return true;
    }

    // Адрес функции из map-файла: 0x00401280
    void InitWindow::Show() {
        if (hWnd) {
            ShowWindow(hWnd, SW_SHOW);
            UpdateWindow(hWnd);
        }
    }

    // Адрес функции из map-файла: 0x00401320
    void InitWindow::Hide() {
        if (hWnd) {
            ShowWindow(hWnd, SW_HIDE);
        }
    }

    // Адрес функции из map-файла: 0x004013A0
    void InitWindow::Destroy() {
        if (hWnd) {
            DestroyWindow(hWnd);
            hWnd = NULL;
        }
        
        UnregisterClass("GTA2_InitWindow", hInstance);
        initialized = false;
        
        if (g_pInitWindow == this) {
            g_pInitWindow = nullptr;
        }
        
        delete this;
    }

    // Адрес функции из map-файла: 0x00401420
    LRESULT CALLBACK InitWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
        switch (message) {
        case WM_COMMAND:
            {
                int wmId = LOWORD(wParam);
                InitWindow* pThis = g_pInitWindow;
                
                if (!pThis) {
                    break;
                }
                
                switch (wmId) {
                case 1001: // Кнопка "Одиночная игра"
                    pThis->OnSinglePlayerClick();
                    break;
                case 1002: // Кнопка "Многопользовательская"
                    pThis->OnMultiPlayerClick();
                    break;
                case 1003: // Кнопка "Старт"
                    pThis->OnStartClick();
                    break;
                }
            }
            break;
            
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        return 0;
    }

    // Адрес функции из map-файла: 0x00401580
    void InitWindow::OnSinglePlayerClick() {
        selectedMode = 0;
        params.mode = GameMode::SinglePlayer;
        
        // Скрыть элементы мультиплеера
        ShowWindow(hLblServerIP, SW_HIDE);
        ShowWindow(hEditServerIP, SW_HIDE);
        
        MessageBox(hWnd, "Режим: Одиночная игра", "Выбор режима", MB_OK | MB_ICONINFORMATION);
    }

    // Адрес функции из map-файла: 0x00401620
    void InitWindow::OnMultiPlayerClick() {
        selectedMode = 1;
        params.mode = GameMode::MultiPlayer;
        
        // Показать элементы мультиплеера
        ShowWindow(hLblServerIP, SW_SHOW);
        ShowWindow(hEditServerIP, SW_SHOW);
        
        MessageBox(hWnd, "Режим: Многопользовательская\nВведите IP сервера", "Выбор режима", MB_OK | MB_ICONINFORMATION);
    }

    // Адрес функции из map-файла: 0x004016C0
    void InitWindow::OnStartClick() {
        if (selectedMode == 1 && params.mode == GameMode::MultiPlayer) {
            // Получить IP из поля ввода
            char ipBuffer[256] = {0};
            GetWindowTextA(hEditServerIP, ipBuffer, sizeof(ipBuffer));
            
            if (strlen(ipBuffer) == 0) {
                MessageBox(hWnd, "Пожалуйста, введите IP сервера", "Ошибка", MB_OK | MB_ICONWARNING);
                return;
            }
            
            SetServerIP(ipBuffer);
        }
        
        // Здесь будет запуск игры с выбранными параметрами
        MessageBox(hWnd, 
            selectedMode == 0 ? "Запуск одиночной игры..." : "Подключение к серверу...", 
            "Старт", 
            MB_OK | MB_ICONINFORMATION);
        
        // В будущем здесь будет переход к основному меню или загрузка игры
        Hide();
    }

    // Адрес функции из map-файла: 0x00401760
    GameMode InitWindow::GetSelectedMode() const {
        return params.mode;
    }

    // Адрес функции из map-файла: 0x00401790
    void InitWindow::SetServerIP(const char* ip) {
        if (ip) {
            params.serverIP = _strdup(ip);
        }
    }

    // Адрес функции из map-файла: 0x00401800
    const char* InitWindow::GetServerIP() const {
        return params.serverIP;
    }

    // Адрес функции из map-файла: 0x00401830
    int InitWindow::GetPort() const {
        return params.port;
    }

    // Адрес функции из map-файла: 0x00401860
    void InitWindow::SetPort(int port) {
        params.port = port;
    }

    // Адрес функции из map-файла: 0x00401890
    bool InitWindow::IsWindowed() const {
        return params.windowed;
    }

    // Адрес функции из map-файла: 0x004018C0
    void InitWindow::SetWindowed(bool windowed) {
        params.windowed = windowed;
    }

    // Адрес функции из map-файла: 0x004018F0
    InitParams* InitWindow::GetParams() {
        return &params;
    }

    // Адрес функции из map-файла: 0x00401920
    void InitWindow::ApplyParams(const InitParams& newParams) {
        params = newParams;
        selectedMode = (params.mode == GameMode::MultiPlayer) ? 1 : 0;
    }

    // Адрес функции из map-файла: 0x004019C0
    InitParams ParseCommandLine(int argc, char* argv[]) {
        InitParams params;
        
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-multi") == 0 || strcmp(argv[i], "-m") == 0) {
                params.mode = GameMode::MultiPlayer;
            }
            else if (strcmp(argv[i], "-single") == 0 || strcmp(argv[i], "-s") == 0) {
                params.mode = GameMode::SinglePlayer;
            }
            else if (strcmp(argv[i], "-ip") == 0 && i + 1 < argc) {
                params.serverIP = argv[++i];
            }
            else if (strcmp(argv[i], "-port") == 0 && i + 1 < argc) {
                params.port = atoi(argv[++i]);
            }
            else if (strcmp(argv[i], "-windowed") == 0 || strcmp(argv[i], "-w") == 0) {
                params.windowed = true;
            }
            else if (strcmp(argv[i], "-fullscreen") == 0 || strcmp(argv[i], "-f") == 0) {
                params.windowed = false;
            }
            else if (strcmp(argv[i], "-nosound") == 0) {
                params.soundEnabled = false;
            }
            else if (strcmp(argv[i], "-nomusic") == 0) {
                params.musicEnabled = false;
            }
            else if (strcmp(argv[i], "-res") == 0 && i + 2 < argc) {
                params.resolutionX = atoi(argv[++i]);
                params.resolutionY = atoi(argv[++i]);
            }
        }
        
        return params;
    }

} // namespace GTA2
