/* �ϐ��錾 */
char str[1000][261] = { 0 };	/* �t�@�C���̃f�[�^���i�[����񎟌��z�� */
FILE *fp = NULL;

/* data.txt�t�@�C���I�[�v�� */
fp = fopen("data.txt", "r");

/* �t�@�C�����J���Ȃ������ꍇ */
if (fp == NULL) {
	printf("�t�@�C�����J���܂���ł����B\n");
	return;		/* �v���O�����I�� */
}

/* �t�@�C���̃f�[�^��ǂݍ��� */
for (short count = 0;count < 1000;count++) {	/* count ��1000��菬�����ꍇ���[�v */
	fgets(&(str[count][0]), 261, fp);	/* �f�[�^����ǂݍ��� */
}

/* data.txt�t�@�C���N���[�Y */
fclose(fp);