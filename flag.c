char num[5] = { 0 };			/* ���͂����l���i�[����z�� */
char str[1000][261] = { 0 };	/* �t�@�C���̃f�[�^���i�[����񎟌��z�� */
char flag = 0;					/* �t���O [ON:1/OFF:0] */

/* 1000�񃋁[�v */
for (short count = 0;count < 1000;count++) {

	/* ���͂����l�ƃt�@�C���̌����� 3byte �������Ƃ� */
	if (strncmp(&(num[0]), &(str[count][0]), 3) == 0) {
		printf("[�Y���f�[�^]:%s", &(str[count][4]));	/* �񎟌��z��̐擪����4�Ԗڂ̃A�h���X��n���Ă��� */
		flag = 1;		/* �t���O�FON */
		break;		/* ���[�v�I�� */
	}

}

/* �t���O�FOFF�̏ꍇ */
if (flag == 0) {
	printf("[��������]:�Y���f�[�^�Ȃ�\n");
}
/* �t���O�FON�̏ꍇ */
else if (flag == 1) {
	flag = 0;	/* �t���O�FOFF */
}