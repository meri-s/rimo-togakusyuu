#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void main(void) {
	/* 変数宣言 */
	char num[5] = { 0 };			/* 入力した値を格納する配列 */
	char str[1000][261] = { 0 };	/* ファイルのデータを格納する二次元配列 */
	FILE *fp = NULL;
	char flag = 0;					/* フラグ [ON:1/OFF:0] */

	/* data.txtファイルオープン */
	fp = fopen("data.txt", "r");

	/* ファイルを開けなかった場合 */
	if (fp == NULL) {
		printf("ファイルを開けませんでした。\n");
		return;		/* プログラム終了 */
	}

	/* ファイルのデータを読み込み */
	for (short count = 0;count < 1000;count++) {	/* count が1000より小さい場合ループ */
		fgets(&(str[count][0]), 261, fp);			/* データ部を読み込み */
	}

	/* data.txtファイルクローズ */
	fclose(fp);

	/* 永久ループ */
	while (1) {
		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		gets(&(num[0]));			/* 検索キーを入力 */

		/* "EXIT"と入力するとループ終了 */
		if (strcmp(&(num[0]), "EXIT") == 0) {		/* 入力した値と"EXIT"を比べて、等しい時 0 を返し、==で判定 */
			break;
		}

		/* 1000回ループ */
		for (short count = 0;count < 1000;count++) {

			/* 入力した値とファイルの検索部 3byte が同じとき */
			if (strncmp(&(num[0]), &(str[count][0]), 3) == 0) {
				printf("[該当データ]:%s", &(str[count][4]));	/* 二次元配列の先頭から4番目のアドレスを渡している */
				flag = 1;		/* フラグ：ON */
				break;		/* ループ終了 */
			}

		}

		/* フラグ：OFFの場合 */
		if (flag == 0) {
			printf("[検索結果]:該当データなし\n");
		}
		/* フラグ：ONの場合 */
		else if (flag == 1) {
			flag = 0;	/* フラグ：OFF */
		}

	}
	return;
}