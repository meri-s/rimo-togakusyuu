#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void main(void) {
	/* �ϐ��錾 */
	char sInputBuf[5] = { 0 };			/* ���͂����l���i�[����z�� */
	char sFileData[1000][261] = { 0 };	/* �t�@�C���̃f�[�^���i�[����񎟌��z�� */
	FILE *fp = NULL;
	char cFlag = 0;						/* �t���O [ON:1/OFF:0] */

	/* data.txt�t�@�C���I�[�v�� */
	/* �t�@�C�����J���Ȃ������ꍇ */
	if ((fp = fopen("data.txt", "r")) == NULL) {
		printf("�t�@�C�����J���܂���ł����B\n");
		return;		/* �v���O�����I�� */
	}

	/* �t�@�C���̃f�[�^��ǂݍ��� */
	for (short hCount = 0;hCount < 1000;hCount++) {	/* hCount ��1000��菬�����ꍇ���[�v */
		fgets(&(sFileData[hCount][0]), 261, fp);	/* �t�@�C���f�[�^��ǂݍ��� */
	}

	/* data.txt�t�@�C���N���[�Y */
	fclose(fp);

	/* �i�v���[�v */
	while (1) {
		/* �t���O������ */
		cFlag = 0;

		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		gets(&(sInputBuf[0]));			/* �����L�[����� */

		/* "EXIT"�Ɠ��͂���ƃ��[�v�I�� */
		if (strcmp(&(sInputBuf[0]), "EXIT") == 0) {		/* ���͂����l��"EXIT"���ׂāA�������� 0 ��Ԃ��A==�Ŕ��� */
			break;
		}

		/* 1000�񃋁[�v */
		for (short hCount = 0;hCount < 1000;hCount++) {

			/* ���͂����l�ƃt�@�C���̌����L�[�� 3byte �������Ƃ� */
			if (strncmp(&(sInputBuf[0]), &(sFileData[hCount][0]), 3) == 0) {
				printf("[�Y���f�[�^]:%s", &(sFileData[hCount][4]));	/* �񎟌��z��̐擪����4�Ԗڂ̃A�h���X(�f�[�^��)��n���Ă��� */
				cFlag = 1;		/* �t���O�FON */
				break;		/* ���[�v�I�� */
			}

		}

		/* �t���O�FOFF�̏ꍇ */
		if (cFlag == 0) {
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
		}
		
	}
	return;
}