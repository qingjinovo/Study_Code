#include <windows.h>
#include <string>
#include <sstream>
#include <stdexcept>

// 定义窗口类名称
const char *g_szClassName = "CalculatorWindowClass";

// 全局变量用于存储输入的数字和运算符
std::string input1, input2;
char operation = '\0';
bool isSecondNumber = false;
// 显示控件句柄
HWND hDisplay = NULL;
// 另一个输出显示（例如历史/结果）
HWND hOutput = NULL;

// 消息处理函数
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case 1:
        { // 数字按钮1
            if (isSecondNumber)
            {
                input2 += '1';
            }
            else
            {
                input1 += '1';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 2:
        { // 数字按钮2
            if (isSecondNumber)
            {
                input2 += '2';
            }
            else
            {
                input1 += '2';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 3:
        { // 数字按钮3
            if (isSecondNumber)
            {
                input2 += '3';
            }
            else
            {
                input1 += '3';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 4:
        { // 数字按钮4
            if (isSecondNumber)
            {
                input2 += '4';
            }
            else
            {
                input1 += '4';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 5:
        { // 数字按钮5
            if (isSecondNumber)
            {
                input2 += '5';
            }
            else
            {
                input1 += '5';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 6:
        { // 数字按钮6
            if (isSecondNumber)
            {
                input2 += '6';
            }
            else
            {
                input1 += '6';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 7:
        { // 数字按钮7
            if (isSecondNumber)
            {
                input2 += '7';
            }
            else
            {
                input1 += '7';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 8:
        { // 数字按钮8
            if (isSecondNumber)
            {
                input2 += '8';
            }
            else
            {
                input1 += '8';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 9:
        { // 数字按钮9
            if (isSecondNumber)
            {
                input2 += '9';
            }
            else
            {
                input1 += '9';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 14:
        { // 数字按钮0 (id 14)
            if (isSecondNumber)
            {
                input2 += '0';
            }
            else
            {
                input1 += '0';
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 40:
        { // 小数点按钮
            if (isSecondNumber)
            {
                if (input2.find('.') == std::string::npos)
                { // 防止重复添加小数点
                    input2 += '.';
                }
            }
            else
            {
                if (input1.find('.') == std::string::npos)
                { // 防止重复添加小数点
                    input1 += '.';
                }
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        case 10:
        { // 加号
            operation = '+';
            isSecondNumber = true;
            break;
        }
        case 11:
        { // 减号
            operation = '-';
            isSecondNumber = true;
            break;
        }
        case 12:
        { // 乘号
            operation = '*';
            isSecondNumber = true;
            break;
        }
        case 13:
        { // 除号
            operation = '/';
            isSecondNumber = true;
            break;
        }
        case 20:
        { // 等号
            double result = 0.0;
            double num1 = 0.0, num2 = 0.0;
            try
            {
                num1 = std::stod(input1);
                if (!input2.empty())
                {
                    num2 = std::stod(input2);
                }
            }
            catch (const std::invalid_argument &e)
            {
                MessageBox(hwnd, "Invalid input!", "Error", MB_OK | MB_ICONERROR);
                return 0;
            }

            switch (operation)
            {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2 != 0)
                {
                    result = num1 / num2;
                }
                else
                {
                    MessageBox(hwnd, "Division by zero!", "Error", MB_OK | MB_ICONERROR);
                    return 0;
                }
                break;
            default:
                MessageBox(hwnd, "No operation selected!", "Error", MB_OK | MB_ICONERROR);
                return 0;
            }
            std::ostringstream oss;
            oss << result;
            SetWindowText(hDisplay, oss.str().c_str());
            // 将结果追加到下方的输出框（历史记录）
            if (hOutput) {
                int len = GetWindowTextLength(hOutput);
                std::string history;
                history.resize(len + 1);
                if (len > 0) {
                    GetWindowText(hOutput, &history[0], len + 1);
                    history.resize(len);
                } else {
                    history.clear();
                }
                std::ostringstream entry;
                entry << input1 << (operation ? std::string(1, operation) : "") << input2 << " = " << oss.str();
                if (!history.empty()) history += "\r\n";
                history += entry.str();
                SetWindowText(hOutput, history.c_str());
            }
            input1 = oss.str();
            input2 = "";
            isSecondNumber = false;
            break;
        }
        case 30:
        { // 清除按钮 (C)
            input1 = "";
            input2 = "";
            operation = '\0';
            isSecondNumber = false;
            SetWindowText(hDisplay, "0");
            break;
        }
        case 31:
        { // 清除当前输入按钮 (CE)
            if (isSecondNumber)
            {
                input2 = "";
            }
            else
            {
                input1 = "";
            }
            {
                std::string displayStr = input1;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
            break;
        }
        }
        break;
    case WM_KEYDOWN:
        {
            WPARAM key = wParam;
            bool update = false;
            switch (key) {
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
            case VK_NUMPAD0: case VK_NUMPAD1: case VK_NUMPAD2: case VK_NUMPAD3: case VK_NUMPAD4:
            case VK_NUMPAD5: case VK_NUMPAD6: case VK_NUMPAD7: case VK_NUMPAD8: case VK_NUMPAD9:
                {
                    char ch = 0;
                    if (key >= VK_NUMPAD0 && key <= VK_NUMPAD9) ch = '0' + (key - VK_NUMPAD0);
                    else ch = (char)key;
                    if (isSecondNumber) input2.push_back(ch);
                    else input1.push_back(ch);
                    update = true;
                }
                break;
            case VK_BACK:
                {
                    // Backspace behavior
                    if (isSecondNumber && !input2.empty()) {
                        input2.pop_back();
                    } else if (isSecondNumber && input2.empty()) {
                        // remove operator
                        operation = '\0';
                        isSecondNumber = false;
                    } else if (!input1.empty()) {
                        input1.pop_back();
                    }
                    update = true;
                }
                break;
            case VK_OEM_PLUS: case VK_ADD:
                operation = '+'; isSecondNumber = true; update = true; break;
            case VK_OEM_MINUS: case VK_SUBTRACT:
                operation = '-'; isSecondNumber = true; update = true; break;
            case VK_MULTIPLY:
                operation = '*'; isSecondNumber = true; update = true; break;
            case VK_DIVIDE:
                operation = '/'; isSecondNumber = true; update = true; break;
            case VK_OEM_PERIOD: case VK_DECIMAL:
                {
                    if (isSecondNumber) {
                        if (input2.find('.') == std::string::npos) input2.push_back('.');
                    } else {
                        if (input1.find('.') == std::string::npos) input1.push_back('.');
                    }
                    update = true;
                }
                break;
            case VK_RETURN: case VK_SPACE:
                // simulate '=' press
                SendMessage(hwnd, WM_COMMAND, MAKELONG(20, 0), 0);
                break;
            }
            if (update) {
                std::string displayStr = input1;
                if (operation) displayStr += operation;
                if (isSecondNumber) displayStr += input2;
                if (hDisplay) SetWindowText(hDisplay, displayStr.c_str());
            }
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwnd);
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}
void CreateButton(HWND hwnd, const char *text, int x, int y, int width, int height, int id)
{
    CreateWindow(
        "BUTTON", text, WS_VISIBLE | WS_CHILD,
        x, y, width, height, hwnd, (HMENU)id, NULL, NULL);
}
extern "C" int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    (void)hInstance; // 避免未使用参数警告
    (void)hPrevInstance;
    (void)lpCmdLine;
    (void)nCmdShow;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(wc)); // 初始化为0
    wc.cbSize = sizeof(WNDCLASSEX);
wc.style = 0;
wc.lpfnWndProc = WndProc;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor = LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
wc.lpszMenuName = NULL;
wc.lpszClassName = g_szClassName;
wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

if (!RegisterClassEx(&wc)) {
    MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

    HWND hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Simple Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 260, 420,
        NULL, NULL, hInstance, NULL);

if (hwnd == NULL) {
    MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
    return 0;
}

ShowWindow(hwnd, nCmdShow);
UpdateWindow(hwnd);
    // 创建只读显示框，放在窗口顶部
    hDisplay = CreateWindowEx(
        0,
        "EDIT",
        "0",
        WS_CHILD | WS_VISIBLE | ES_RIGHT | ES_READONLY | WS_BORDER,
        10, 10, 230, 40,
        hwnd, NULL, hInstance, NULL);

    // 按钮向下移动以腾出显示框空间
    CreateButton(hwnd, "1", 10, 60, 50, 50, 1);
    CreateButton(hwnd, "2", 70, 60, 50, 50, 2);
    CreateButton(hwnd, "3", 130, 60, 50, 50, 3);
    CreateButton(hwnd, "+", 190, 60, 50, 50, 10);
    CreateButton(hwnd, "4", 10, 120, 50, 50, 4);
    CreateButton(hwnd, "5", 70, 120, 50, 50, 5);
    CreateButton(hwnd, "6", 130, 120, 50, 50, 6);
    CreateButton(hwnd, "-", 190, 120, 50, 50, 11);
    CreateButton(hwnd, "7", 10, 180, 50, 50, 7);
    CreateButton(hwnd, "8", 70, 180, 50, 50, 8);
    CreateButton(hwnd, "9", 130, 180, 50, 50, 9);
    CreateButton(hwnd, "*", 190, 180, 50, 50, 12);
    CreateButton(hwnd, "0", 10, 240, 50, 50, 14);
    CreateButton(hwnd, "=", 70, 240, 110, 50, 20);
    CreateButton(hwnd, "/", 190, 240, 50, 50, 13);
    CreateButton(hwnd, "C", 10, 300, 50, 50, 30);
    CreateButton(hwnd, "CE", 70, 300, 50, 50, 31);
    CreateButton(hwnd, ".", 130, 300, 50, 50, 40);

    // 创建下方的多行只读输出框用于历史记录
    hOutput = CreateWindowEx(
        0,
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | ES_LEFT | ES_READONLY | ES_MULTILINE | WS_BORDER | WS_VSCROLL,
        10, 360, 230, 70,
        hwnd, NULL, hInstance, NULL);

MSG Msg;
while (GetMessage(&Msg, NULL, 0, 0) > 0) {
    TranslateMessage(&Msg);
    DispatchMessage(&Msg);
}
return Msg.wParam;
}