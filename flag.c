char num[5] = { 0 };			/* 入力した値を格納する配列 */
char str[1000][261] = { 0 };	/* ファイルのデータを格納する二次元配列 */
char flag = 0;					/* フラグ */

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