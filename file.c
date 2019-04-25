/* 変数宣言 */
char str[1000][261] = { 0 };	/* ファイルのデータを格納する二次元配列 */
FILE *fp = NULL;

/* data.txtファイルオープン */
fp = fopen("data.txt", "r");

/* ファイルを開けなかった場合 */
if (fp == NULL) {
	printf("ファイルを開けませんでした。\n");
	return;		/* プログラム終了 */
}

/* ファイルのデータを読み込み */
for (short count = 0;count < 1000;count++) {	/* count が1000より小さい場合ループ */
	fgets(&(str[count][0]), 261, fp);	/* データ部を読み込み */
}

/* data.txtファイルクローズ */
fclose(fp);