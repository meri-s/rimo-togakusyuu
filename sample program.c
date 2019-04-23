#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
	/* 変数宣言 */
	char num[5] = { 0 };
	char str[256] = { 0 };
	short h = 0;
	FILE *fp = NULL;

	/* 永久ループ */
	while (1) {
		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		gets(&(num[0]));			/* 検索キーを入力 */

		/* "EXIT"と入力するとループ終了 */
		if (strcmp(&(num[0]), "EXIT") == 0) {		/* 入力した値と"EXIT"を比べて、等しい時 0 を返し、==で判定 */
			break;
		}

		/* data.txtファイルオープン */
		fp = fopen("data.txt", "r");

		/* 入力した値が 001 ～ 013 の場合 */
		if ((atoi(num) <= 13) && (atoi(num) >= 1)) {
			h = atoi(num);							/* 入力した値を数値で h に代入 */
			while (h != 0) {						/* h が0でない時ループ */
				fseek(fp, 4, SEEK_CUR);				/* ファイルの読み込み位置を4byteずらす */
				fgets(&(str[0]), sizeof(str), fp);	/* ファイル1行分読み込み */
				h--;								/* hをデクリメント */
			}
		}

		/* 入力した値が 015 ～ 020 の場合 */
		if ((atoi(num) <= 20) && (atoi(num) >= 15)) {
			h = atoi(num);							/* 入力した値を数値で h に代入 */
			while (h != 1) {						/* h が0でない時ループ */
				fseek(fp, 4, SEEK_CUR);				/* ファイルの読み込み位置を4byteずらす */
				fgets(&(str[0]), sizeof(str), fp);	/* ファイル1行分読み込み */
				h--;								/* hをデクリメント */
			}
		}

		/* 入力した値が 1 ～ 20 の場合 (14を除く) */
		if ((atoi(num) >= 1) && (atoi(num) <= 20) && (atoi(num) != 14)) {	
			printf("[該当データ]:%s", &(str[0]));
		}
		/* 上記以外の場合 */
		else {																
			printf("[検索結果]:該当データなし\n");
		}

		/* data.txtファイルクローズ */
		fclose(fp);

	}
	return;
}