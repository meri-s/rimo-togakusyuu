#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

void main(void) {
	/* �ϐ��錾 */
	char num[5] = { 0 };			/* ���͂����l���i�[����z�� */
	char str[1000][261] = { 0 };	/* �t�@�C���̃f�[�^���i�[����񎟌��z�� */
	FILE *fp = NULL;
	char flag = 0;					/* �t���O [ON:1/OFF:0] */

	/* data.txt�t�@�C���I�[�v�� */
	fp = fopen("data.txt", "r");

	/* �t�@�C�����J���Ȃ������ꍇ */
	if (fp == NULL) {
		printf("�t�@�C�����J���܂���ł����B\n");
		return;		/* �v���O�����I�� */
	}

	/* �t�@�C���̃f�[�^��ǂݍ��� */
	for (short count = 0;count < 1000;count++) {	/* count ��1000��菬�����ꍇ���[�v */
		fgets(&(str[count][0]), 261, fp);			/* �f�[�^����ǂݍ��� */
	}

	/* data.txt�t�@�C���N���[�Y */
	fclose(fp);

	/* �i�v���[�v */
	while (1) {
		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		gets(&(num[0]));			/* �����L�[����� */

		/* "EXIT"�Ɠ��͂���ƃ��[�v�I�� */
		if (strcmp(&(num[0]), "EXIT") == 0) {		/* ���͂����l��"EXIT"���ׂāA�������� 0 ��Ԃ��A==�Ŕ��� */
			break;
		}

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

	}
	return;
}