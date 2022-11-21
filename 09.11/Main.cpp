#include "Header.h"

#define MAX_LOADSTRING 50

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];


ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY021122, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);


    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY021122));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY021122));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = NULL;
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    TCHAR buf1[50] = TEXT("Íèêèòà");
    TCHAR buf2[50] = TEXT("Ìîõñåíè");
    TCHAR buf3[50] = TEXT("20.01.2004");
    TCHAR buf2_1[50] = TEXT("Äìèòðèé");
    TCHAR buf2_2[50] = TEXT("Øàðïèëî");
    TCHAR buf2_3[50] = TEXT("20.01.2004");
    switch (message)
    {

    case WM_LBUTTONDOWN:
    {
        int task = MessageBox(hWnd, TEXT("Ok - go\nCancel - exit"), TEXT("Multik"), MB_OKCANCEL | MB_ICONASTERISK);
        if (task == IDOK)
        {
            int rez = MessageBox(hWnd, TEXT("Yes - 1 ðåçþìå\nNo - 2 ðåçþìå\nCancel - Ñðåä. àðèô. ñèìâîëîâ"), TEXT("resume"), MB_YESNOCANCEL | MB_ICONASTERISK);
            if (rez == IDYES)
            {
                MessageBox(hWnd, buf1, TEXT("Èìÿ"), MB_OK);
                MessageBox(hWnd, buf2, TEXT("Ôàìèëèÿ"), MB_OK);
                MessageBox(hWnd, buf3, TEXT("Äàòà ðîæäåíèÿ"), MB_OK);
            }
            else if (rez == IDCANCEL)
            {
                int rez = _tcsclen(buf1) + _tcslen(buf2_1) + _tcsclen(buf2) + _tcslen(buf2_2) + _tcsclen(buf3) + _tcslen(buf2_3);
                rez /= 2;
                TCHAR buf[100];
                wsprintf(buf, TEXT("%d"), rez);
                MessageBox(hWnd, buf, TEXT("exit"), MB_OK);
            }
            else if (rez == IDNO)
            {
                MessageBox(hWnd, buf2_1, TEXT("Èìÿ"), MB_OK);
                MessageBox(hWnd, buf2_2, TEXT("Ôàìèëèÿ"), MB_OK);
                MessageBox(hWnd, buf2_3, TEXT("Äàòà ðîæäåíèÿ"), MB_OK);
            }
            break;
        }
        else if (task == IDCANCEL)
        {
            int con = 1;
            int tmp = rand() % (1 - 100) + 1;
            while (true)
            {
                TCHAR buf[50];
                wsprintf(buf, TEXT("%d?"), tmp);
                int rez = MessageBox(hWnd, buf, TEXT("Óãàäûâàíèå"), MB_YESNO | MB_ICONQUESTION);
                if (rez == IDYES)
                {
                    wsprintf(buf, TEXT("%d"), con);
                    MessageBox(hWnd, buf, TEXT("Óãàäûâàíèå"), MB_OK);
                    break;
                }
                else if (rez == IDNO)
                {
                    tmp = rand() % (1 - 100) + 1;
                    con++;
                }
            }
            break;
        }
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}