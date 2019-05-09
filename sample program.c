#define _CRT_SECURE_NO_WARNINGS				/* fopen関数を使用する際の警告を避ける			*/

#include<stdio.h>
#include<string.h>

#define INPUT_BUFFER_SIZE	(256)			/* 入力する値のサイズ							*/
#define DATA_ROW_MAX		(1000)			/* ファイルデータのMAX行数						*/
#define SEARCH_KEY_SIZE		(3)				/* 検索キー部のサイズ(byte)						*/
#define SEPARATOR_SIZE		(1)				/* セパレータ部のサイズ(byte)					*/
#define DATA_SIZE			(256)			/* データ部のサイズ(byte)						*/
#define DATA_COL_MAX		(SEARCH_KEY_SIZE + SEPARATOR_SIZE + DATA_SIZE + 1)
											/* ファイルデータのMAX桁数(NULL終端含む)		*/
#define DSP_POS				(SEARCH_KEY_SIZE + SEPARATOR_SIZE)
											/* 表示開始位置									*/
#define FLAG_ON				(1)				/* フラグ値(ON)									*/
#define FLAG_OFF			(0)				/* フラグ値(OFF)								*/
#define FILE_NAME			("data.txt")	/* ファイル名									*/
#define OPEN_MODE			("r")			/* ファイルオープンモード						*/
#define MESSAGE_ID_MAX		(5)				/* 文言IDのMAX値								*/
#define MESSAGE_ID_SIZE		(64)			/* 文言IDのサイズ(byte)							*/	
#define STORAGE_ID_01		(0)				/* 文言ID 01が格納されている配列番号			*/
#define STORAGE_ID_02		(1)				/* 文言ID 02が格納されている配列番号			*/
#define STORAGE_ID_03		(2)				/* 文言ID 03が格納されている配列番号			*/
#define STORAGE_ID_04		(3)				/* 文言ID 04が格納されている配列番号			*/

static char sPrintMessage[MESSAGE_ID_MAX][MESSAGE_ID_SIZE] = {
	{ "3桁の数字を入力して下さい[終了/EXIT]:" },	/* 文言ID 01	*/
	{ "[該当データ]:" },							/* 文言ID 02	*/
	{ "[検索結果]:該当データなし\n" },				/* 文言ID 03	*/
	{ "<ERROR>[検索結果値]:" },						/* 文言ID 04	*/
};

void main(void) {
	/* 変数宣言 */
	char sInputBuf[INPUT_BUFFER_SIZE] = { 0 };				/* 入力した値を格納する配列				*/
	char sFileData[DATA_ROW_MAX][DATA_COL_MAX] = { 0 };		/* ファイルのデータを格納する二次元配列	*/
	FILE *fp = NULL;
	char cFoundFlag = FLAG_OFF;								/* フラグ [ON:FLAG_ON/OFF:FLAG_OFF]		*/

	/* ファイルオープン				*/
	/* ファイルを開けなかった場合	*/
	if ((fp = fopen(FILE_NAME, OPEN_MODE)) == NULL) {
		printf("ファイルを開けませんでした。\n");
		return;		/* プログラム終了 */
	}

	/* ファイルのデータを読み込み */
	for (short hCount = 0;hCount < DATA_ROW_MAX;hCount++) {	/* hCount がDATA_ROW_MAXより小さい場合ループ	*/
		fgets(&(sFileData[hCount][0]), DATA_COL_MAX, fp);	/* ファイルデータを読み込み						*/
	}

	/* ファイルクローズ	*/
	fclose(fp);

	/* 永久ループ */
	while (1) {
		cFoundFlag = FLAG_OFF;			/* フラグ初期化	*/

		printf("%s", &(sPrintMessage[STORAGE_ID_01][0]));	/* 文言ID 01の出力	*/
		gets(&(sInputBuf[0]));					/* 検索キーを入力	*/

		/* "EXIT"と入力するとループ終了 */
		if (strcmp(&(sInputBuf[0]), "EXIT") == 0) {		/* 入力した値と"EXIT"を比べ、等しい時 0 を返し、==で判定 */
			break;
		}

		/* DATA_ROW_MAX回ループ */
		for (short hCount = 0;hCount < DATA_ROW_MAX;hCount++) {

			/* 入力した値と検索キー部が同じとき */
			if (strncmp(&(sInputBuf[0]), &(sFileData[hCount][0]), SEARCH_KEY_SIZE) == 0) {
				printf("%s%s", &(sPrintMessage[STORAGE_ID_02][0]), &(sFileData[hCount][DSP_POS]));	/* 文言ID 02の出力 */
											/* 二次元配列の先頭からDSP_POS番目のアドレス(データ部)を渡している */
				cFoundFlag = FLAG_ON;		/* フラグ：ON */
				break;		/* ループ終了 */
			}

		}

		/* フラグ：OFFの場合 */
		if (cFoundFlag == FLAG_OFF) {
			printf("%s", &(sPrintMessage[STORAGE_ID_03][0]));	/* 文言ID 03の出力 */
		}
		
	}
	return;
}