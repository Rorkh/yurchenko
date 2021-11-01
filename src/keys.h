namespace keys {
	#ifdef _WIN32
		inline constexpr int NUMPAD_0 = 0x60;
		inline constexpr int NUMPAD_1 = 0x61;
		inline constexpr int NUMPAD_2 = 0x62;
		inline constexpr int NUMPAD_3 = 0x63;
		inline constexpr int NUMPAD_4 = 0x64;
		inline constexpr int NUMPAD_5 = 0x65;
		inline constexpr int NUMPAD_6 = 0x66;
		inline constexpr int NUMPAD_7 = 0x67;
		inline constexpr int NUMPAD_8 = 0x68;
		inline constexpr int NUMPAD_9 = 0x69;

		inline constexpr int F1 = 0x70;
		inline constexpr int F2 = 0x71;
		inline constexpr int F3 = 0x72;
		inline constexpr int F4 = 0x73;
		inline constexpr int F5 = 0x74;
		inline constexpr int F6 = 0x75;
		inline constexpr int F7 = 0x76;
		inline constexpr int F8 = 0x77;
		inline constexpr int F9 = 0x78;
		inline constexpr int F10 = 0x79;
		inline constexpr int F11 = 0x7A;

		inline constexpr int RSHIFT = 0xA1;
		inline constexpr int LSHIFT = 0xA0;

		inline constexpr int KEY_0 = 0x30;
		inline constexpr int KEY_1 = 0x31;
		inline constexpr int KEY_2 = 0x32;
		inline constexpr int KEY_3 = 0x33;
		inline constexpr int KEY_4 = 0x34;
		inline constexpr int KEY_5 = 0x35;
		inline constexpr int KEY_6 = 0x36;
		inline constexpr int KEY_7 = 0x37;
		inline constexpr int KEY_8 = 0x38;
		inline constexpr int KEY_9 = 0x39;

		inline constexpr int KEY_A = 0x41;
		inline constexpr int KEY_B = 0x42;
		inline constexpr int KEY_C = 0x43;
		inline constexpr int KEY_D = 0x44;
		inline constexpr int KEY_E = 0x45;
		inline constexpr int KEY_F = 0x46;
		inline constexpr int KEY_G = 0x47;
		inline constexpr int KEY_H = 0x48;
		inline constexpr int KEY_I = 0x49;
		inline constexpr int KEY_J = 0x4A;
		inline constexpr int KEY_K = 0x4B;
		inline constexpr int KEY_L = 0x4C;
		inline constexpr int KEY_M = 0x4D;
		inline constexpr int KEY_N = 0x4E;
		inline constexpr int KEY_O = 0x4F;
		inline constexpr int KEY_P = 0x50;
		inline constexpr int KEY_Q = 0x51;
		inline constexpr int KEY_R = 0x52;
		inline constexpr int KEY_S = 0x53;
		inline constexpr int KEY_T = 0x54;
		inline constexpr int KEY_U = 0x55;
		inline constexpr int KEY_V = 0x56;
		inline constexpr int KEY_W = 0x57;
		inline constexpr int KEY_X = 0x58;
		inline constexpr int KEY_Y = 0x59;
		inline constexpr int KEY_Z = 0x5A;
	#elif defined(__linux__)
		inline constexpr int NUMPAD_0 = 0xFFB0;
		inline constexpr int NUMPAD_1 = 0xFFB1;
		inline constexpr int NUMPAD_2 = 0xFFB2;
		inline constexpr int NUMPAD_3 = 0xFFB3;
		inline constexpr int NUMPAD_4 = 0xFFB4;
		inline constexpr int NUMPAD_5 = 0xFFB5;
		inline constexpr int NUMPAD_6 = 0xFFB5;
		inline constexpr int NUMPAD_7 = 0xFFB7;
		inline constexpr int NUMPAD_8 = 0xFFB8;
		inline constexpr int NUMPAD_9 = 0xFFB9;

		inline constexpr int F1 = 0xFFBE;
		inline constexpr int F2 = 0xFFBF;
		inline constexpr int F3 = 0xFFC0;
		inline constexpr int F4 = 0xFFC1;
		inline constexpr int F5 = 0xFFC2;
		inline constexpr int F6 = 0xFFC3;
		inline constexpr int F7 = 0xFFC4;
		inline constexpr int F8 = 0xFFC5;
		inline constexpr int F9 = 0xFFC6;
		inline constexpr int F10 = 0xFFC7;
		inline constexpr int F11 = 0xFFC8;

		inline constexpr int RSHIFT = 0xFFE1;
		inline constexpr int LSHIFT = 0xFFE2;

		inline constexpr int KEY_0 = 0x030;
		inline constexpr int KEY_1 = 0x031;
		inline constexpr int KEY_2 = 0x032;
		inline constexpr int KEY_3 = 0x033;
		inline constexpr int KEY_4 = 0x034;
		inline constexpr int KEY_5 = 0x035;
		inline constexpr int KEY_6 = 0x036;
		inline constexpr int KEY_7 = 0x037;
		inline constexpr int KEY_8 = 0x038;
		inline constexpr int KEY_9 = 0x039;

		inline constexpr int KEY_A = 0x041;
		inline constexpr int KEY_B = 0x042;
		inline constexpr int KEY_C = 0x043;
		inline constexpr int KEY_D = 0x044;
		inline constexpr int KEY_E = 0x045;
		inline constexpr int KEY_F = 0x046;
		inline constexpr int KEY_G = 0x047;
		inline constexpr int KEY_H = 0x048;
		inline constexpr int KEY_I = 0x049;
		inline constexpr int KEY_J = 0x04a;
		inline constexpr int KEY_K = 0x04b;
		inline constexpr int KEY_L = 0x04c;
		inline constexpr int KEY_M = 0x04d;
		inline constexpr int KEY_N = 0x04e;
		inline constexpr int KEY_O = 0x04f;
		inline constexpr int KEY_P = 0x050;
		inline constexpr int KEY_Q = 0x051;
		inline constexpr int KEY_R = 0x052;
		inline constexpr int KEY_S = 0x053;
		inline constexpr int KEY_T = 0x054;
		inline constexpr int KEY_U = 0x055;
		inline constexpr int KEY_V = 0x056;
		inline constexpr int KEY_W = 0x057;
		inline constexpr int KEY_X = 0x058;
		inline constexpr int KEY_Y = 0x059;
		inline constexpr int KEY_Z = 0x05a;
	#endif
}