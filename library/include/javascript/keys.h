#pragma once

namespace KEY {
    // Null (or key up)
    constexpr uint16_t NONE = 0;

    // Letters
    constexpr uint16_t A = 65;
    constexpr uint16_t B = 66;
    constexpr uint16_t C = 67;
    constexpr uint16_t D = 68;
    constexpr uint16_t E = 69;
    constexpr uint16_t F = 70;
    constexpr uint16_t G = 71;
    constexpr uint16_t H = 72;
    constexpr uint16_t I = 73;
    constexpr uint16_t J = 74;
    constexpr uint16_t K = 75;
    constexpr uint16_t L = 76;
    constexpr uint16_t M = 77;
    constexpr uint16_t N = 78;
    constexpr uint16_t O = 79;
    constexpr uint16_t P = 80;
    constexpr uint16_t Q = 81;
    constexpr uint16_t R = 82;
    constexpr uint16_t S = 83;
    constexpr uint16_t T = 84;
    constexpr uint16_t U = 85;
    constexpr uint16_t V = 86;
    constexpr uint16_t W = 87;
    constexpr uint16_t X = 88;
    constexpr uint16_t Y = 89;
    constexpr uint16_t Z = 90;

    // Numbers
    constexpr uint16_t NUM_0 = 48;
    constexpr uint16_t NUM_1 = 49;
    constexpr uint16_t NUM_2 = 50;
    constexpr uint16_t NUM_3 = 51;
    constexpr uint16_t NUM_4 = 52;
    constexpr uint16_t NUM_5 = 53;
    constexpr uint16_t NUM_6 = 54;
    constexpr uint16_t NUM_7 = 55;
    constexpr uint16_t NUM_8 = 56;
    constexpr uint16_t NUM_9 = 57;

    // Function Keys
    constexpr uint16_t F1 = 112;
    constexpr uint16_t F2 = 113;
    constexpr uint16_t F3 = 114;
    constexpr uint16_t F4 = 115;
    constexpr uint16_t F5 = 116;
    constexpr uint16_t F6 = 117;
    constexpr uint16_t F7 = 118;
    constexpr uint16_t F8 = 119;
    constexpr uint16_t F9 = 120;
    constexpr uint16_t F10 = 121;
    constexpr uint16_t F11 = 122;
    constexpr uint16_t F12 = 123;

    // Numpad
    constexpr uint16_t NUMPAD_0 = 96;
    constexpr uint16_t NUMPAD_1 = 97;
    constexpr uint16_t NUMPAD_2 = 98;
    constexpr uint16_t NUMPAD_3 = 99;
    constexpr uint16_t NUMPAD_4 = 100;
    constexpr uint16_t NUMPAD_5 = 101;
    constexpr uint16_t NUMPAD_6 = 102;
    constexpr uint16_t NUMPAD_7 = 103;
    constexpr uint16_t NUMPAD_8 = 104;
    constexpr uint16_t NUMPAD_9 = 105;
    constexpr uint16_t NUMPAD_MULTIPLY = 106;
    constexpr uint16_t NUMPAD_ADD = 107;
    constexpr uint16_t NUMPAD_SUBTRACT = 109;
    constexpr uint16_t NUMPAD_DECIMAL = 110;
    constexpr uint16_t NUMPAD_DIVIDE = 111;

    // Special Characters
    constexpr uint16_t SEMICOLON = 186;
    constexpr uint16_t EQUALS = 187;
    constexpr uint16_t COMMA = 188;
    constexpr uint16_t MINUS = 189;
    constexpr uint16_t PERIOD = 190;
    constexpr uint16_t FORWARD_SLASH = 191;
    constexpr uint16_t GRAVE_ACCENT = 192;
    constexpr uint16_t OPEN_BRACKET = 219;
    constexpr uint16_t BACK_SLASH = 220;
    constexpr uint16_t CLOSE_BRACKET = 221;
    constexpr uint16_t SINGLE_QUOTE = 222;

    // Control Keys
    constexpr uint16_t BACKSPACE = 8;
    constexpr uint16_t TAB = 9;
    constexpr uint16_t ENTER = 13;
    constexpr uint16_t SHIFT = 16;
    constexpr uint16_t CTRL = 17;
    constexpr uint16_t ALT = 18;
    constexpr uint16_t PAUSE_BREAK = 19;
    constexpr uint16_t CAPS_LOCK = 20;
    constexpr uint16_t ESCAPE = 27;
    constexpr uint16_t SPACE = 32;
    constexpr uint16_t PAGE_UP = 33;
    constexpr uint16_t PAGE_DOWN = 34;
    constexpr uint16_t END = 35;
    constexpr uint16_t HOME = 36;
    constexpr uint16_t LEFT_ARROW = 37;
    constexpr uint16_t UP_ARROW = 38;
    constexpr uint16_t RIGHT_ARROW = 39;
    constexpr uint16_t DOWN_ARROW = 40;
    constexpr uint16_t INSERT = 45;
    constexpr uint16_t DELETE = 46;
    constexpr uint16_t LEFT_WINDOW = 91;
    constexpr uint16_t RIGHT_WINDOW = 92;
    constexpr uint16_t SELECT = 93;
    constexpr uint16_t PRINT_SCREEN = 44;
    constexpr uint16_t SCROLL_LOCK = 145;
    constexpr uint16_t NUM_LOCK = 144;

    // Media Keys
    constexpr uint16_t VOLUME_MUTE = 173;
    constexpr uint16_t VOLUME_DOWN = 174;
    constexpr uint16_t VOLUME_UP = 175;
    constexpr uint16_t MEDIA_NEXT_TRACK = 176;
    constexpr uint16_t MEDIA_PREV_TRACK = 177;
    constexpr uint16_t MEDIA_STOP = 178;
    constexpr uint16_t MEDIA_PLAY_PAUSE = 179;

    // Browser Keys
    constexpr uint16_t BROWSER_BACK = 166;
    constexpr uint16_t BROWSER_FORWARD = 167;
    constexpr uint16_t BROWSER_REFRESH = 168;
    constexpr uint16_t BROWSER_STOP = 169;
    constexpr uint16_t BROWSER_SEARCH = 170;
    constexpr uint16_t BROWSER_FAVORITES = 171;
    constexpr uint16_t BROWSER_HOME = 172;

    // Modifier States
    constexpr uint16_t SHIFT_LEFT = 160;
    constexpr uint16_t SHIFT_RIGHT = 161;
    constexpr uint16_t CTRL_LEFT = 162;
    constexpr uint16_t CTRL_RIGHT = 163;
    constexpr uint16_t ALT_LEFT = 164;
    constexpr uint16_t ALT_RIGHT = 165;
}
