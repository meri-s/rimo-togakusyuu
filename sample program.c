#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(void) {
	char num[5] = { 0 };
	FILE *fp = NULL;

	/* �i�v���[�v */
	while (1) {
		printf("3���̐�������͂��ĉ�����[�I��/EXIT]:");
		gets(&(num[0]));			/* �����L�[����� */

		/* "EXIT"�Ɠ��͂���ƃ��[�v�I�� */
		if (strcmp(num, "EXIT") == 0) {		/* ���͂����l��"EXIT"���ׂāA�������� 0 ��Ԃ��A==�Ŕ��� */
			break;
		}

		/* ���͂����l�ŕ��� */
		switch (atoi(num)) {	/* ������𐔒l�ɕϊ� */
			case  1:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 001 �̏ꍇ		*/
			case  2:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 002 �̏ꍇ		*/
			case  3:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 003 �̏ꍇ		*/
			case  4:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 004 �̏ꍇ		*/
			case  5:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 005 �̏ꍇ		*/
			case  6:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 006 �̏ꍇ		*/
			case  7:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 007 �̏ꍇ		*/
			case  8:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 008 �̏ꍇ		*/
			case  9:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 009 �̏ꍇ		*/
			case 10:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 010 �̏ꍇ		*/
			case 11:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 011 �̏ꍇ		*/
			case 12:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 012 �̏ꍇ		*/
			case 13:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 013 �̏ꍇ		*/
			case 15:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 015 �̏ꍇ		*/
			case 16:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 016 �̏ꍇ		*/
			case 17:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 017 �̏ꍇ		*/
			case 18:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 018 �̏ꍇ		*/
			case 19:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 019 �̏ꍇ		*/
			case 20:	printf("[�Y���f�[�^]:\n");				break;	/* �����L�[ 020 �̏ꍇ		*/
			default:	printf("[��������]:�Y���f�[�^�Ȃ�\n");	break;	/* �����L�[�ƍ��v���Ȃ��ꍇ */
		}

	}
	return;
}