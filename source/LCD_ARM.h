#include "main.h"

void RCC_Configuration_LCD(void) {
	RCC_LCD_ON;
}

void GPIO_Configuration_LCD(void) {
	GPIO_InitTypeDef GPIO_InitStructure;		// GPIO structure was used to initialize port

	GPIO_InitStructure.GPIO_Pin = GPIO_LCD;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;		// select output push-pull mode
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LCD, &GPIO_InitStructure);
}

// LCD 초기화
void LCD_init(void) {
	// LCD 포트에 LCD 출력 설정
	GPIO_ResetBits(LCD, GPIO_LCD_EN);		// E = 0;

	delay_cnt_LCD(72000);		// 4800 * 15 = 72000번
	Command(0x0020);
	delay_cnt_LCD(24000);		// 4800 * 5 = 24000번
	Command(0x0020);
	delay_cnt_LCD(480000);		// 4800 * 100 = 480000번
	Command(0x0020);
	Command(FUNCSET);
	Command(DISPON);
	Command(ALLCLR);
	Command(ENTMODE);
}

// 문자열 출력 함수
/*void LCD_String(char flash str[])		// flash : 프로그램 구동 중 바뀌지 않는 값에 사용
{
	char flash *pStr=0;

	pStr = str;
	while(*pStr) Data(*pStr++);
}*/

void LCD_Value(char val[]) {
	char *pVal=0;

	pVal = val;
	while(*pVal) Data(*pVal++);
}

void LCD_print(void) {		// LCD 화면 한 번 출력하기
	Command(ALLCLR);
	Command(HOME);
	LCD_Value(LCD_LINE1);		// 첫 번째 라인 배열 출력
	Command(LINE2);
	LCD_Value(LCD_LINE2);		// 두 번째 라인 배열 출력
}

void LCD_print_nonCLR(void) {		// LCD 화면 한 번 출력하기(Clear 없이 덮어쓰기)
	Command(HOME);
	LCD_Value(LCD_LINE1);		// 첫 번째 라인 배열 출력
	Command(LINE2);
	LCD_Value(LCD_LINE2);		// 두 번째 라인 배열 출력
}

// 인스트럭션 쓰기 함수
void Command(unsigned char byte) {
	Busy();

	// 인스트럭션 상위 바이트
	GPIO_Write(LCD, (byte & 0x00F0));		// 데이터
	GPIO_ResetBits(LCD, GPIO_LCD_RS | GPIO_LCD_RW);		// RS = 0; RW = 0;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_SetBits(LCD, GPIO_LCD_EN);		// E = 1;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_ResetBits(LCD, GPIO_LCD_EN);		// E = 0;

	// 인스트럭션 하위 바이트
	GPIO_Write(LCD, ((byte<<4) & 0x00F0));		// 데이터
	GPIO_ResetBits(LCD, GPIO_LCD_RS | GPIO_LCD_RW);		// RS = 0; RW = 0;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_SetBits(LCD, GPIO_LCD_EN);		// E = 1;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_ResetBits(LCD, GPIO_LCD_EN);		// E = 0;
}

// 데이터 쓰기 함수
void Data(unsigned char byte) {
	Busy();

	// 데이터 상위 바이트
	GPIO_Write(LCD, (byte & 0x00F0));		// 데이터
	GPIO_SetBits(LCD, GPIO_LCD_RS);		// RS = 1;
	GPIO_ResetBits(LCD, GPIO_LCD_RW);		// RW = 0;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_SetBits(LCD, GPIO_LCD_EN);		// E = 1;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_ResetBits(LCD, GPIO_LCD_EN);		// E = 0;

	// 데이터 하위 바이트
	GPIO_Write(LCD, (byte<<4 & 0x00F0));		// 데이터
	GPIO_SetBits(LCD, GPIO_LCD_RS);		// RS = 1;
	GPIO_ResetBits(LCD, GPIO_LCD_RW);		// RW = 0;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_SetBits(LCD, GPIO_LCD_EN);		// E = 1;
	delay_cnt_LCD(5);		// 1us에 근접한 delay
	GPIO_ResetBits(LCD, GPIO_LCD_EN);		// E = 0;
}

// Busy Flag Check -> 일반적인 BF를 체크하는 것이 아니라
// 일정한 시간 지연을 이용한다.
void Busy(void) {
	delay_cnt_LCD(9600);		// 4800 * 2 = 9600번
}

void delay_cnt_LCD(uint32_t delay) {
	// ★4800번 = 1ms 딜레이 발생
	// ★240번 = 50us
	// ★24번 = 5us
	// ★1번 = 24/5 보다 더 긴 딜레이. 함수 호출할 때 필요한 시간때문
	uint32_t cnt = 0;
	while (cnt++ < delay);
}
