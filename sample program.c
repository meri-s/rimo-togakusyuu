#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void main(void) {
	/* 変数宣言 */
	char sInputBuf[5] = { 0 };			/* 入力した値を格納する配列 */
	char sFileData[1000][261] = { 0 };	/* ファイルのデータを格納する二次元配列 */
	FILE *fp = NULL;
	char cFlag = 0;						/* フラグ [ON:1/OFF:0] */

	/* data.txtファイルオープン */
	/* ファイルを開けなかった場合 */
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("ファイルを開けませんでした。\n");
		return;		/* プログラム終了 */
	}

	/* ファイルのデータを読み込み */
	for (short hCount = 0;hCount < 1000;hCount++) {	/* hCount が1000より小さい場合ループ */
		fgets(&(sFileData[hCount][0]), 261, fp);	/* ファイルデータを読み込み */
	}

	/* data.txtファイルクローズ */
	fclose(fp);

	/* 永久ループ */
	while (1) {
		/* フラグ初期化 */
		cFlag = 0;

		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		gets(&(sInputBuf[0]));			/* 検索キーを入力 */

		/* "EXIT"と入力するとループ終了 */
		if (strcmp(&(sInputBuf[0]), "EXIT") == 0) {		/* 入力した値と"EXIT"を比べて、等しい時 0 を返し、==で判定 */
			break;
		}

		/* 1000回ループ */
		for (short hCount = 0;hCount < 1000;hCount++) {

			/* 入力した値とファイルの検索キー部 3byte が同じとき */
			if (strncmp(&(sInputBuf[0]), &(sFileData[hCount][0]), 3) == 0) {
				printf("[該当データ]:%s", &(sFileData[hCount][4]));	/* 二次元配列の先頭から4番目のアドレス(データ部)を渡している */
				cFlag = 1;		/* フラグ：ON */
				break;		/* ループ終了 */
			}

		}

		/* フラグ：OFFの場合 */
		if (cFlag == 0) {
			printf("[検索結果]:該当データなし\n");
		}
		
	}
	return;
}