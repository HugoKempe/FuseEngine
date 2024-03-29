#pragma once

namespace Fuse
{
	using KeyCode = uint16_t;

	namespace Key
	{
		enum : KeyCode
		{
			// From glfw3.h
			Space = 32,
			Apostrophe = 39, /* ' */
			Comma = 44, /* , */
			Minus = 45, /* - */
			Period = 46, /* . */
			Slash = 47, /* / */

			D0 = 48, /* 0 */
			D1 = 49, /* 1 */
			D2 = 50, /* 2 */
			D3 = 51, /* 3 */
			D4 = 52, /* 4 */
			D5 = 53, /* 5 */
			D6 = 54, /* 6 */
			D7 = 55, /* 7 */
			D8 = 56, /* 8 */
			D9 = 57, /* 9 */

			Semicolon = 59, /* ; */
			Equal = 61, /* = */

			A = 65,
			B = 66,
			C = 67,
			D = 68,
			E = 69,
			F = 70,
			G = 71,
			H = 72,
			I = 73,
			J = 74,
			K = 75,
			L = 76,
			M = 77,
			N = 78,
			O = 79,
			P = 80,
			Q = 81,
			R = 82,
			S = 83,
			T = 84,
			U = 85,
			V = 86,
			W = 87,
			X = 88,
			Y = 89,
			Z = 90,

			LeftBracket = 91,  /* [ */
			Backslash = 92,  /* \ */
			RightBracket = 93,  /* ] */
			GraveAccent = 96,  /* ` */

			World1 = 161, /* non-US #1 */
			World2 = 162, /* non-US #2 */

			/* Function keys */
			Escape = 256,
			Enter = 257,
			Tab = 258,
			Backspace = 259,
			Insert = 260,
			Delete = 261,
			Right = 262,
			Left = 263,
			Down = 264,
			Up = 265,
			PageUp = 266,
			PageDown = 267,
			Home = 268,
			End = 269,
			CapsLock = 280,
			ScrollLock = 281,
			NumLock = 282,
			PrintScreen = 283,
			Pause = 284,
			F1 = 290,
			F2 = 291,
			F3 = 292,
			F4 = 293,
			F5 = 294,
			F6 = 295,
			F7 = 296,
			F8 = 297,
			F9 = 298,
			F10 = 299,
			F11 = 300,
			F12 = 301,
			F13 = 302,
			F14 = 303,
			F15 = 304,
			F16 = 305,
			F17 = 306,
			F18 = 307,
			F19 = 308,
			F20 = 309,
			F21 = 310,
			F22 = 311,
			F23 = 312,
			F24 = 313,
			F25 = 314,

			/* Keypad */
			KP0 = 320,
			KP1 = 321,
			KP2 = 322,
			KP3 = 323,
			KP4 = 324,
			KP5 = 325,
			KP6 = 326,
			KP7 = 327,
			KP8 = 328,
			KP9 = 329,
			KPDecimal = 330,
			KPDivide = 331,
			KPMultiply = 332,
			KPSubtract = 333,
			KPAdd = 334,
			KPEnter = 335,
			KPEqual = 336,

			LeftShift = 340,
			LeftControl = 341,
			LeftAlt = 342,
			LeftSuper = 343,
			RightShift = 344,
			RightControl = 345,
			RightAlt = 346,
			RightSuper = 347,
			Menu = 348
		};
	}
}
//
///* Key and button actions */
//#define FB_RELEASE                0
//#define FB_PRESS                  1
//#define FB_REPEAT                 2
//
// /* Joystick hat states */
//#define FB_HAT_CENTERED           0
//#define FB_HAT_UP                 1
//#define FB_HAT_RIGHT              2
//#define FB_HAT_DOWN               4
//#define FB_HAT_LEFT               8
//#define FB_HAT_RIGHT_UP           (FB_HAT_RIGHT | FB_HAT_UP)
//#define FB_HAT_RIGHT_DOWN         (FB_HAT_RIGHT | FB_HAT_DOWN)
//#define FB_HAT_LEFT_UP            (FB_HAT_LEFT  | FB_HAT_UP)
//#define FB_HAT_LEFT_DOWN          (FB_HAT_LEFT  | FB_HAT_DOWN)
//
///* The unknown key */
//#define FB_KEY_UNKNOWN            (-1)
//
///* Printable keys */
//#define FB_KEY_SPACE              32
//#define FB_KEY_APOSTROPHE         39  /* ' */
//#define FB_KEY_COMMA              44  /* , */
//#define FB_KEY_MINUS              45  /* - */
//#define FB_KEY_PERIOD             46  /* . */
//#define FB_KEY_SLASH              47  /* / */
//#define FB_KEY_0                  48
//#define FB_KEY_1                  49
//#define FB_KEY_2                  50
//#define FB_KEY_3                  51
//#define FB_KEY_4                  52
//#define FB_KEY_5                  53
//#define FB_KEY_6                  54
//#define FB_KEY_7                  55
//#define FB_KEY_8                  56
//#define FB_KEY_9                  57
//#define FB_KEY_SEMICOLON          59  /* ; */
//#define FB_KEY_EQUAL              61  /* = */
//#define FB_KEY_A                  65
//#define FB_KEY_B                  66
//#define FB_KEY_C                  67
//#define FB_KEY_D                  68
//#define FB_KEY_E                  69
//#define FB_KEY_F                  70
//#define FB_KEY_G                  71
//#define FB_KEY_H                  72
//#define FB_KEY_I                  73
//#define FB_KEY_J                  74
//#define FB_KEY_K                  75
//#define FB_KEY_L                  76
//#define FB_KEY_M                  77
//#define FB_KEY_N                  78
//#define FB_KEY_O                  79
//#define FB_KEY_P                  80
//#define FB_KEY_Q                  81
//#define FB_KEY_R                  82
//#define FB_KEY_S                  83
//#define FB_KEY_T                  84
//#define FB_KEY_U                  85
//#define FB_KEY_V                  86
//#define FB_KEY_W                  87
//#define FB_KEY_X                  88
//#define FB_KEY_Y                  89
//#define FB_KEY_Z                  90
//#define FB_KEY_LEFT_BRACKET       91  /* [ */
//#define FB_KEY_BACKSLASH          92  /* \ */
//#define FB_KEY_RIGHT_BRACKET      93  /* ] */
//#define FB_KEY_GRAVE_ACCENT       96  /* ` */
//#define FB_KEY_WORLD_1            161 /* non-US #1 */
//#define FB_KEY_WORLD_2            162 /* non-US #2 */
//
///* Function keys */
//#define FB_KEY_ESCAPE             256
//#define FB_KEY_ENTER              257
//#define FB_KEY_TAB                258
//#define FB_KEY_BACKSPACE          259
//#define FB_KEY_INSERT             260
//#define FB_KEY_DELETE             261
//#define FB_KEY_RIGHT              262
//#define FB_KEY_LEFT               263
//#define FB_KEY_DOWN               264
//#define FB_KEY_UP                 265
//#define FB_KEY_PAGE_UP            266
//#define FB_KEY_PAGE_DOWN          267
//#define FB_KEY_HOME               268
//#define FB_KEY_END                269
//#define FB_KEY_CAPS_LOCK          280
//#define FB_KEY_SCROLL_LOCK        281
//#define FB_KEY_NUM_LOCK           282
//#define FB_KEY_PRINT_SCREEN       283
//#define FB_KEY_PAUSE              284
//#define FB_KEY_F1                 290
//#define FB_KEY_F2                 291
//#define FB_KEY_F3                 292
//#define FB_KEY_F4                 293
//#define FB_KEY_F5                 294
//#define FB_KEY_F6                 295
//#define FB_KEY_F7                 296
//#define FB_KEY_F8                 297
//#define FB_KEY_F9                 298
//#define FB_KEY_F10                299
//#define FB_KEY_F11                300
//#define FB_KEY_F12                301
//#define FB_KEY_F13                302
//#define FB_KEY_F14                303
//#define FB_KEY_F15                304
//#define FB_KEY_F16                305
//#define FB_KEY_F17                306
//#define FB_KEY_F18                307
//#define FB_KEY_F19                308
//#define FB_KEY_F20                309
//#define FB_KEY_F21                310
//#define FB_KEY_F22                311
//#define FB_KEY_F23                312
//#define FB_KEY_F24                313
//#define FB_KEY_F25                314
//#define FB_KEY_KP_0               320
//#define FB_KEY_KP_1               321
//#define FB_KEY_KP_2               322
//#define FB_KEY_KP_3               323
//#define FB_KEY_KP_4               324
//#define FB_KEY_KP_5               325
//#define FB_KEY_KP_6               326
//#define FB_KEY_KP_7               327
//#define FB_KEY_KP_8               328
//#define FB_KEY_KP_9               329
//#define FB_KEY_KP_DECIMAL         330
//#define FB_KEY_KP_DIVIDE          331
//#define FB_KEY_KP_MULTIPLY        332
//#define FB_KEY_KP_SUBTRACT        333
//#define FB_KEY_KP_ADD             334
//#define FB_KEY_KP_ENTER           335
//#define FB_KEY_KP_EQUAL           336
//#define FB_KEY_LEFT_SHIFT         340
//#define FB_KEY_LEFT_CONTROL       341
//#define FB_KEY_LEFT_ALT           342
//#define FB_KEY_LEFT_SUPER         343
//#define FB_KEY_RIGHT_SHIFT        344
//#define FB_KEY_RIGHT_CONTROL      345
//#define FB_KEY_RIGHT_ALT          346
//#define FB_KEY_RIGHT_SUPER        347
//#define FB_KEY_MENU               348
//
//#define FB_KEY_LAST               FB_KEY_MENU
//
///* Modifier key flags */
//#define FB_MOD_SHIFT           0x0001
//#define FB_MOD_CONTROL         0x0002
//#define FB_MOD_ALT             0x0004
//#define FB_MOD_SUPER           0x0008
//#define FB_MOD_CAPS_LOCK       0x0010
//#define FB_MOD_NUM_LOCK        0x0020
//
///* Mouse buttons */
//#define FB_MOUSE_BUTTON_1         0
//#define FB_MOUSE_BUTTON_2         1
//#define FB_MOUSE_BUTTON_3         2
//#define FB_MOUSE_BUTTON_4         3
//#define FB_MOUSE_BUTTON_5         4
//#define FB_MOUSE_BUTTON_6         5
//#define FB_MOUSE_BUTTON_7         6
//#define FB_MOUSE_BUTTON_8         7
//#define FB_MOUSE_BUTTON_LAST      FB_MOUSE_BUTTON_8
//#define FB_MOUSE_BUTTON_LEFT      FB_MOUSE_BUTTON_1
//#define FB_MOUSE_BUTTON_RIGHT     FB_MOUSE_BUTTON_2
//#define FB_MOUSE_BUTTON_MIDDLE    FB_MOUSE_BUTTON_3
//
///* Joysticks */
//#define FB_JOYSTICK_1             0
//#define FB_JOYSTICK_2             1
//#define FB_JOYSTICK_3             2
//#define FB_JOYSTICK_4             3
//#define FB_JOYSTICK_5             4
//#define FB_JOYSTICK_6             5
//#define FB_JOYSTICK_7             6
//#define FB_JOYSTICK_8             7
//#define FB_JOYSTICK_9             8
//#define FB_JOYSTICK_10            9
//#define FB_JOYSTICK_11            10
//#define FB_JOYSTICK_12            11
//#define FB_JOYSTICK_13            12
//#define FB_JOYSTICK_14            13
//#define FB_JOYSTICK_15            14
//#define FB_JOYSTICK_16            15
//#define FB_JOYSTICK_LAST          FB_JOYSTICK_16
//
///* Gamepad buttons */
//#define FB_GAMEPAD_BUTTON_A               0
//#define FB_GAMEPAD_BUTTON_B               1
//#define FB_GAMEPAD_BUTTON_X               2
//#define FB_GAMEPAD_BUTTON_Y               3
//#define FB_GAMEPAD_BUTTON_LEFT_BUMPER     4
//#define FB_GAMEPAD_BUTTON_RIGHT_BUMPER    5
//#define FB_GAMEPAD_BUTTON_BACK            6
//#define FB_GAMEPAD_BUTTON_START           7
//#define FB_GAMEPAD_BUTTON_GUIDE           8
//#define FB_GAMEPAD_BUTTON_LEFT_THUMB      9
//#define FB_GAMEPAD_BUTTON_RIGHT_THUMB     10
//#define FB_GAMEPAD_BUTTON_DPAD_UP         11
//#define FB_GAMEPAD_BUTTON_DPAD_RIGHT      12
//#define FB_GAMEPAD_BUTTON_DPAD_DOWN       13
//#define FB_GAMEPAD_BUTTON_DPAD_LEFT       14
//#define FB_GAMEPAD_BUTTON_LAST            FB_GAMEPAD_BUTTON_DPAD_LEFT
//
//#define FB_GAMEPAD_BUTTON_CROSS       FB_GAMEPAD_BUTTON_A
//#define FB_GAMEPAD_BUTTON_CIRCLE      FB_GAMEPAD_BUTTON_B
//#define FB_GAMEPAD_BUTTON_SQUARE      FB_GAMEPAD_BUTTON_X
//#define FB_GAMEPAD_BUTTON_TRIANGLE    FB_GAMEPAD_BUTTON_Y
//
///* Gamepad axes */
//#define FB_GAMEPAD_AXIS_LEFT_X        0
//#define FB_GAMEPAD_AXIS_LEFT_Y        1
//#define FB_GAMEPAD_AXIS_RIGHT_X       2
//#define FB_GAMEPAD_AXIS_RIGHT_Y       3
//#define FB_GAMEPAD_AXIS_LEFT_TRIGGER  4
//#define FB_GAMEPAD_AXIS_RIGHT_TRIGGER 5
//#define FB_GAMEPAD_AXIS_LAST          FB_GAMEPAD_AXIS_RIGHT_TRIGGER