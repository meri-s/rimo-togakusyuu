#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
	/* �ϐ��錾 */
	char num[5] = { 0 };
	char str[256] = { 0 };
	short h = 0;
	FILE *fp = NULL;

	/* �i�v���[�v */
	while (1) {
		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		gets(&(num[0]));			/* �����L�[����� */

		/* "EXIT"�Ɠ��͂���ƃ��[�v�I�� */
		if (strcmp(&(num[0]), "EXIT") == 0) {		/* ���͂����l��"EXIT"���ׂāA�������� 0 ��Ԃ��A==�Ŕ��� */
			break;
		}

		/* data.txt�t�@�C���I�[�v�� */
		fp = fopen("data.txt", "r");

		/* ���͂����l�� 001 �` 013 �̏ꍇ */
		if ((atoi(num) <= 13) && (atoi(num) >= 1)) {
			for (h = atoi(num); h != 0; h--) {		/* h �ɓ��͂����l�𐔒l�ő�� */	/* h��0�łȂ���΃��[�v */	/* h���f�N�������g */
				fseek(fp, 4, SEEK_CUR);				/* �t�@�C���̓ǂݍ��݈ʒu��4byte���炷 */
				fgets(&(str[0]), sizeof(str), fp);	/* �t�@�C��1�s���ǂݍ��� */
			}
		}

		/* ���͂����l�� 015 �` 020 �̏ꍇ */
		if ((atoi(num) <= 20) && (atoi(num) >= 15)) {
			for (h = atoi(num); h != 1; h--) {		/* h �ɓ��͂����l�𐔒l�ő�� */	/* h��0�łȂ���΃��[�v */	/* h���f�N�������g */	
				fseek(fp, 4, SEEK_CUR);				/* �t�@�C���̓ǂݍ��݈ʒu��4byte���炷 */
				fgets(&(str[0]), sizeof(str), fp);	/* �t�@�C��1�s���ǂݍ��� */
			}
		}

		/* ���͂����l�� 1 �` 20 �̏ꍇ (14������) */
		if ((atoi(num) >= 1) && (atoi(num) <= 20) && (atoi(num) != 14)) {	
			printf("[�Y���f�[�^]:%s", &(str[0]));
		}
		/* ��L�ȊO�̏ꍇ */
		else {																
			printf("[��������]:�Y���f�[�^�Ȃ�\n");
		}

		/* data.txt�t�@�C���N���[�Y */
		fclose(fp);

	}
	return;
}