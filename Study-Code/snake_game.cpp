#include <windows.h>
#include <stdlib.h>
#include <time.h>

// 濠电偞鎸搁幉锟犲垂濞嗘垹鐜绘俊銈傚亾鐟滅増绋掑鍕槻闁活煉鎷�
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define CELL_SIZE 20
#define GRID_WIDTH (WINDOW_WIDTH / CELL_SIZE)
#define GRID_HEIGHT (WINDOW_HEIGHT / CELL_SIZE)

// 濠电偞鎸搁幉锟犲垂濞嗘挻鍋愰柤鍝ヮ暯閸嬫捇鏁撻敓锟�
#define GAME_RUNNING 0
#define GAME_OVER 1

// 闂佸搫鍊婚幊鎾诲箖閿燂拷
#define DIR_UP 0
#define DIR_DOWN 1
#define DIR_LEFT 2
#define DIR_RIGHT 3

// 闂佺儤鏌ㄥú鈺備繆椤撱垺鍊烽柛锔诲幘濞夈垽鏌＄€ｈ埖瀚�
typedef struct SnakeNode {
    int x, y;
    struct SnakeNode* next;
} SnakeNode;

// 闂佺ǹ绻堥崝宀勬儑椤掑嫬鐭楁慨妞诲亾闁革綇鎷�
static SnakeNode* snakeHead = NULL;
static int snakeLength = 3;
static int direction = DIR_RIGHT;
static int nextDirection = DIR_RIGHT;
static int foodX, foodY;
static int score = 0;
static int gameState = GAME_RUNNING;
static HWND hwndMain = NULL;

// 闂佸憡鍨兼慨銈夊汲閻斿摜鐝堕柣妤€鐗婇～锟�
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void InitializeGame();
void UpdateGame();
void DrawGame(HDC hdc);
void CreateFood();
void MoveSnake();
void GameOver();
void CleanUp();

// 缂備礁顑呴鍛姳椤撱垹绀傞柕澶堝劚缂嶏拷
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow) {
    const char* className = "SnakeGame";
    WNDCLASSEX wc;
    MSG msg;

    // 婵炲鍔岄崬鐣岀玻濡も偓瑜版稓鐚�
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = className;
    wc.hIcon = NULL;
    wc.hIconSm = NULL;
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "缁愭褰涘▔銊ュ斀婢惰精瑙�!", "闁挎瑨顕�", MB_ICONERROR);
        return 1;
    }

    // 闁告帗缂傛挾绮ｅΔ鈧ぐ锟�
    hwndMain = CreateWindowEx(
        0,
        className,
        "鐠愵亜鎮嗛摂鍥ㄧ埗閹达拷",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        WINDOW_WIDTH + 16,
        WINDOW_HEIGHT + 39,
        NULL, NULL, hInstance, NULL
    );

    if (!hwndMain) {
        MessageBox(NULL, "缁愭褰涢崚娑樼紦婢惰精瑙�!", "闁挎瑨顕�", MB_ICONERROR);
        return 1;
    }

    ShowWindow(hwndMain, nCmdShow);
    UpdateWindow(hwndMain);

    // 闁告帗绻傞～鎰板礌閺嶃劎鍩楅柟锟�
    srand((unsigned int)time(NULL));
    InitializeGame();

    // 婵炴垵鐗婃导鍛嚗椤忓棗绠�
    while (TRUE) {
        int returnValue = GetMessage(&msg, NULL, 0, 0);
        if (returnValue == 0) {
            // WM_QUIT濞戝牊浼�
            break;
        } else if (returnValue == -1) {
            // 闁挎瑨顕ら崣鎴犳晸
            MessageBox(NULL, "濞戝牊浼呭顏嗗箚閸欐垹鏁撻柨娆掝嚖!", "闁挎瑨顕�", MB_ICONERROR);
            return 1;
        } else {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

// 缂備焦鍔栭〃鍛般亹濞戞瑦浜ら柛銉㈡杹閺屻倝鏌涢幋锝呅撻柡鍡嫹
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            SetTimer(hwnd, 1, 200, NULL); // 闁荤姳绀佹晶浠嬫偪閸℃ぜ鈧帡宕ㄦ繝鍌滀簽闁诲氦顫夌喊宥咁渻閸岀偛闂柨鐕傛嫹
            break;

        case WM_KEYDOWN:
            switch (wParam) {
                case VK_UP:
                    if (direction != DIR_DOWN)
                        nextDirection = DIR_UP;
                    break;
                case VK_DOWN:
                    if (direction != DIR_UP)
                        nextDirection = DIR_DOWN;
                    break;
                case VK_LEFT:
                    if (direction != DIR_RIGHT)
                        nextDirection = DIR_LEFT;
                    break;
                case VK_RIGHT:
                    if (direction != DIR_LEFT)
                        nextDirection = DIR_RIGHT;
                    break;
                case VK_SPACE:
                    if (gameState == GAME_OVER) {
                        // 闂備焦褰冪粔鐢稿蓟婵犲偆鍤曢柍褜鍓氶幈銊р偓锝庡亞閸╂鏌熸潏鐐
                        CleanUp();
                        InitializeGame();
                        gameState = GAME_RUNNING;
                        score = 0;
                        InvalidateRect(hwnd, NULL, TRUE);
                    }
                    break;
            }
            break;

        case WM_TIMER:
            if (gameState == GAME_RUNNING) {
                UpdateGame();
                InvalidateRect(hwnd, NULL, FALSE);
            }
            break;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            
            // 闁荤姳绀佹晶浠嬫偪閸℃稑妫橀柛銉ｅ妽閹疯京绱撻崒娑氬⒈闁绘牗绮嶇粙澶屽姬瀵ゅ湠
            SetBkMode(hdc, TRANSPARENT);
            SetTextColor(hdc, RGB(0, 0, 0));
            
            DrawGame(hdc);
            EndPaint(hwnd, &ps);
            break;
        }

        case WM_DESTROY:
            KillTimer(hwnd, 1);
            CleanUp();
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 闂佸憡甯楃换鍌烇綖閹版澘绀岄柡宥冨妿閸╂鏌熸潏鐐
void InitializeGame() {
    // 闂佸憡甯楃紓鍌涙崌瀹曟艾鈹戦崱鈺傜稄闂佺偓鏌ㄥù鍕濞嗘挻鈷愰柛顭戝枛椤斿﹤鈽夐幙鍕3闂佹寧鍐婚幏锟�
    snakeHead = (SnakeNode*)malloc(sizeof(SnakeNode));
    snakeHead->x = GRID_WIDTH / 2;
    snakeHead->y = GRID_HEIGHT / 2;
    snakeHead->next = NULL;

    SnakeNode* node1 = (SnakeNode*)malloc(sizeof(SnakeNode));
    node1->x = snakeHead->x - 1;
    node1->y = snakeHead->y;
    node1->next = NULL;
    snakeHead->next = node1;

    SnakeNode* node2 = (SnakeNode*)malloc(sizeof(SnakeNode));
    node2->x = node1->x - 1;
    node2->y = node1->y;
    node2->next = NULL;
    node1->next = node2;

    direction = DIR_RIGHT;
    nextDirection = DIR_RIGHT;
    snakeLength = 3;

    // 闂佸憡甯楃紓鍌涙尰椤︿即鎮㈤崫鍕ㄦ寘
    CreateFood();
}

// 闂佸搫娲ら悺銊╁蓟婵犲倶鈧帡宕ㄦ繝鍌滀簽闂佺粯枪閸╂牠鍩€椤掑﹥瀚�
void UpdateGame() {
    direction = nextDirection;
    MoveSnake();
}

// 缂傚倷鐒﹂敋闁糕晜顨呴妴鎺楀川婵犲倻浜為梺姹囧灩椤嘲岣块敓锟�
void DrawGame(HDC hdc) {
    RECT rect;
    HBRUSH hBrush, oldBrush;
    HPEN hPen, oldPen;
    
    // 闁荤姳绀佹晶浠嬫偪閸℃瑢鍋撳☉娆嶄沪缂傚秴顑嗛柕澶涘瘜閸斺偓缂佺虎鍙庨崰妤€螣婢跺瞼鐭嗛弶鐐村閸橆剟鏌￠崒锔藉
    LOGFONT lf;
    ZeroMemory(&lf, sizeof(LOGFONT));
    lf.lfHeight = 18;
    lf.lfWidth = 0;
    lf.lfWeight = FW_NORMAL;
    lf.lfCharSet = GB2312_CHARSET;
    lstrcpy(lf.lfFaceName, "閻庣敻鍋婇崰娑㈡嫃鐎ｎ喗鈷栭柛娑橆嚟閹凤拷");
    HFONT hFont = CreateFontIndirect(&lf);
    HFONT oldFont = (HFONT)SelectObject(hdc, hFont);

    // 闂佸憡甯楃紓鍌涙崌閹粙鎳￠妶鍥ㄥ櫝闂佸憡绮岄惉濂稿极妤ｅ啫绀嗛柨鐕傛嫹
    hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
    oldPen = (HPEN)SelectObject(hdc, hPen);

    // 缂傚倷鐒﹂敋闁糕晜顨呴妴鎺楀川婵犲倻浜為梺鍛婄墪閹碱偊鎮″▎鎰秶闁革富鍘藉▍锟�
    MoveToEx(hdc, 0, 0, NULL);
    LineTo(hdc, WINDOW_WIDTH, 0);
    LineTo(hdc, WINDOW_WIDTH, WINDOW_HEIGHT);
    LineTo(hdc, 0, WINDOW_HEIGHT);
    LineTo(hdc, 0, 0);

    if (gameState == GAME_RUNNING) {
        // 缂傚倷鐒﹂敋闁糕晜顨婇幗鍌炴晸閿燂拷
        hBrush = CreateSolidBrush(RGB(0, 255, 0)); // 缂傚倷娴囬崕缁樼珶婵犲洦鎲橀柛銉邯閻擄拷
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

        SnakeNode* current = snakeHead;
        while (current != NULL) {
            rect.left = current->x * CELL_SIZE;
            rect.top = current->y * CELL_SIZE;
            rect.right = rect.left + CELL_SIZE;
            rect.bottom = rect.top + CELL_SIZE;
            FillRect(hdc, &rect, hBrush);
            current = current->next;
        }

        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);

        // 缂傚倷鐒﹂敋闁糕晜顨嗛ˇ浼存偄閸濆嫧鎸�
        hBrush = CreateSolidBrush(RGB(255, 0, 0)); // 缂備椒鍕橀崹鍏肩珶婵犲喚妲归柣鏂挎惈閳凤拷
        oldBrush = (HBRUSH)SelectObject(hdc, hBrush);

        rect.left = foodX * CELL_SIZE;
        rect.top = foodY * CELL_SIZE;
        rect.right = rect.left + CELL_SIZE;
        rect.bottom = rect.top + CELL_SIZE;
        FillRect(hdc, &rect, hBrush);

        SelectObject(hdc, oldBrush);
        DeleteObject(hBrush);
    } else if (gameState == GAME_OVER) {
        // 闂佸搫瀚晶浠嬪Φ濮橆兙鈧帡宕ㄦ繝鍌滀簽缂傚倷鐒﹂幐璇册缚椤愶絿鈹嶉柍鍟╃槐锟�
        SetBkMode(hdc, TRANSPARENT);
        TextOut(hdc, WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 - 50, "濠电偞鎸搁幉锟犲垂濞嗘垹纾奸柟鎯х摠鐏忥拷!", 6);
        
        char scoreText[50];
        wsprintf(scoreText, "閻庣數澧楅〃鍛村垂閿燂拷: %d", score);
        TextOut(hdc, WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2, scoreText, lstrlen(scoreText));
        
        TextOut(hdc, WINDOW_WIDTH / 2 - 100, WINDOW_HEIGHT / 2 + 50, "闂佸湱枪椤﹂亶鍩為弽顓炲唨濠靛倸鎲￠弳娑㈡⒑閹绘帞校闁哄苯锕ら锝夊焵椤掍焦鍙忛柨鐕傛嫹", 9);
    }

    // 闂佸搫瀚晶浠嬪Φ濮橆剦鍤楁俊銈傚亾闁割煉鎷�
    char scoreText[50];
    wsprintf(scoreText, "閻庣數澧楅〃鍛村垂閿燂拷: %d", score);
    TextOut(hdc, 10, 10, scoreText, lstrlen(scoreText));

    SelectObject(hdc, oldPen);
    DeleteObject(hPen);
    
    SelectObject(hdc, oldFont);
    DeleteObject(hFont);
}

// 闂佸憡甯楃紓鍌涙尰椤︿即鎮㈤崫鍕ㄦ寘
void CreateFood() {
    bool onSnake;
    do {
        onSnake = false;
        foodX = rand() % GRID_WIDTH;
        foodY = rand() % GRID_HEIGHT;

        // 缂佺虎鍙庨崰鏇犳崲濮橆収妲归柣鏂挎惈閳锋牕鈽夐幘宕囆㈡繝鈧鍫熸啒闁搞儺浜悡鈽夐幙鍕
        SnakeNode* current = snakeHead;
        while (current != NULL) {
            if (current->x == foodX && current->y == foodY) {
                onSnake = true;
                break;
            }
            current = current->next;
        }
    } while (onSnake);
}

// 缂備礁顦抽褎鎱� lesbi閹藉嫰鏁撻敓锟�
void MoveSnake() {
    // 闂佸憡甯楃紓鍌涙崌瀵剟骞嶉鐣屾殸闂佺偓鏌ㄥú銈夊Φ閿燂拷
    SnakeNode* newHead = (SnakeNode*)malloc(sizeof(SnakeNode));
    newHead->x = snakeHead->x;
    newHead->y = snakeHead->y;

    // 闂佸搫绉烽～澶婄暤娓氣偓瀵剟鎮烽悧鍫濃偓濠氭煛閸パ呮憼闁哄苯锕幗鍌炲炊瑜嬫禒鍫澝归敐鍛ら柣銈忔嫹
    switch (direction) {
        case DIR_UP:
            newHead->y--;
            break;
        case DIR_DOWN:
            newHead->y++;
            break;
        case DIR_LEFT:
            newHead->x--;
            break;
        case DIR_RIGHT:
            newHead->x++;
            break;
    }

    // 濠碘槅鍋€閸嬫捇鏌＄仦璇插姕婵″弶鎮傚畷銉╂晜閼恒儱顕℃繝鈷€宥嗗
    if (newHead->x < 0 || newHead->x >= GRID_WIDTH || 
        newHead->y < 0 || newHead->y >= GRID_HEIGHT) {
        GameOver();
        return;
    }

    // 濠碘槅鍋€閸嬫捇鏌＄仦璇插姕婵″弶鎮傚畷銉╂晜閼恒儱顕￠梺鍛婂笚婵粙宕靛⿰鍐惧晠闁跨噦鎷�
    SnakeNode* current = snakeHead;
    while (current != NULL) {
        if (newHead->x == current->x && newHead->y == current->y) {
            GameOver();
            return;
        }
        current = current->next;
    }

    // 闁诲繐绻愬Λ娆撳蓟婵犲啫绶為悗娑櫭徊濠氭煕韫囧鍔氶柛鐭傞弻褔骞戦幇鈹惧亾閸愮窞闁圭虎鍠栭崝锟�
    newHead->next = snakeHead;
    snakeHead = newHead;

    // 濠碘槅鍋€閸嬫捇鏌＄仦璇插姕婵″弶鎮傚畷銉╂晝閳ь剟骞冮崱娑樼濞村吋鎯屽Λ銊╂煟濡ゅ瀚�
    if (snakeHead->x == foodX && snakeHead->y == foodY) {
        // 闂佸憡鑹鹃崯顐﹀春鐏炵虎妲归柣鏂挎惈閳锋牠鏌ㄥ☉妯垮妞ゃ倕鍟村畷锟介幓鎺斺偓濠氭煛娓氬﹥瀚�
        score += 10;
        // 闂佸憡甯楃紓鍌涙崌瀵剚瀵奸幖顓燂紙闂佺粯顨愰幏锟�
        CreateFood();
    } else {
        // 濠电偛澶囬崜婵嗭耿娓氣偓瀹曘儵宕橀妸銉у帓婵＄偛鏋斿褍娼￠弫宥呯暆閳ь兛绨洪梻鍌氬閸婃洟鎮㈤鍕Ω閵娿儙鏌ｉ幇鑸靛
        SnakeNode* prev = NULL;
        current = snakeHead;
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        if (prev != NULL) {
            prev->next = NULL;
            free(current);
        }
    }
}

// 濠电偞鎸搁幉锟犲垂濞嗘垹纾奸柟鎯х摠鐏忥拷
void GameOver() {
    gameState = GAME_OVER;
}

// 濠电偞鎸搁幊鎰板箖婵犲嫭灏庨柛鏇ㄥ墰閻栵拷
void CleanUp() {
    SnakeNode* current = snakeHead;
    while (current != NULL) {
        SnakeNode* next = current->next;
        free(current);
        current = next;
    }
    snakeHead = NULL;
}