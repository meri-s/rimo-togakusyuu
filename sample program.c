#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
	char num[5] = { 0 };
	FILE *fp = NULL;

	/* 永久ループ */
	while (1) {
		printf("3桁の数字を入力して下さい[終了/EXIT]:");
		gets(&(num[0]));			/* 検索キーを入力 */

		/* "EXIT"と入力するとループ終了 */
		if (strcmp(num, "EXIT") == 0) {		/* 入力した値と"EXIT"を比べて、等しい時 0 を返し、==で判定 */
			break;
		}

		/* 入力した値で分岐 */
		switch (atoi(num)) {	/* 文字列を数値に変換 */
			case  1:	printf("[該当データ]:\n");				break;	/* 検索キー 001 の場合		*/
			case  2:	printf("[該当データ]:\n");				break;	/* 検索キー 002 の場合		*/
			case  3:	printf("[該当データ]:\n");				break;	/* 検索キー 003 の場合		*/
			case  4:	printf("[該当データ]:\n");				break;	/* 検索キー 004 の場合		*/
			case  5:	printf("[該当データ]:\n");				break;	/* 検索キー 005 の場合		*/
			case  6:	printf("[該当データ]:\n");				break;	/* 検索キー 006 の場合		*/
			case  7:	printf("[該当データ]:\n");				break;	/* 検索キー 007 の場合		*/
			case  8:	printf("[該当データ]:\n");				break;	/* 検索キー 008 の場合		*/
			case  9:	printf("[該当データ]:\n");				break;	/* 検索キー 009 の場合		*/
			case 10:	printf("[該当データ]:\n");				break;	/* 検索キー 010 の場合		*/
			case 11:	printf("[該当データ]:\n");				break;	/* 検索キー 011 の場合		*/
			case 12:	printf("[該当データ]:\n");				break;	/* 検索キー 012 の場合		*/
			case 13:	printf("[該当データ]:\n");				break;	/* 検索キー 013 の場合		*/
			case 15:	printf("[該当データ]:\n");				break;	/* 検索キー 015 の場合		*/
			case 16:	printf("[該当データ]:\n");				break;	/* 検索キー 016 の場合		*/
			case 17:	printf("[該当データ]:\n");				break;	/* 検索キー 017 の場合		*/
			case 18:	printf("[該当データ]:\n");				break;	/* 検索キー 018 の場合		*/
			case 19:	printf("[該当データ]:\n");				break;	/* 検索キー 019 の場合		*/
			case 20:	printf("[該当データ]:\n");				break;	/* 検索キー 020 の場合		*/
			default:	printf("[検索結果]:該当データなし\n");	break;	/* 検索キーと合致しない場合 */
		}

	}
	return;
}