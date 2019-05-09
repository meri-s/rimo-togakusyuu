#define _CRT_SECURE_NO_WARNINGS				/* fopen�֐����g�p����ۂ̌x���������			*/

#include<stdio.h>
#include<string.h>

#define INPUT_BUFFER_SIZE	(256)			/* ���͂���l�̃T�C�Y							*/
#define DATA_ROW_MAX		(1000)			/* �t�@�C���f�[�^��MAX�s��						*/
#define SEARCH_KEY_SIZE		(3)				/* �����L�[���̃T�C�Y(byte)						*/
#define SEPARATOR_SIZE		(1)				/* �Z�p���[�^���̃T�C�Y(byte)					*/
#define DATA_SIZE			(256)			/* �f�[�^���̃T�C�Y(byte)						*/
#define DATA_COL_MAX		(SEARCH_KEY_SIZE + SEPARATOR_SIZE + DATA_SIZE + 1)
											/* �t�@�C���f�[�^��MAX����(NULL�I�[�܂�)		*/
#define DSP_POS				(SEARCH_KEY_SIZE + SEPARATOR_SIZE)
											/* �\���J�n�ʒu									*/
#define FLAG_ON				(1)				/* �t���O�l(ON)									*/
#define FLAG_OFF			(0)				/* �t���O�l(OFF)								*/
#define FILE_NAME			("data.txt")	/* �t�@�C����									*/
#define OPEN_MODE			("r")			/* �t�@�C���I�[�v�����[�h						*/
#define MESSAGE_ID_MAX		(5)				/* ����ID��MAX�l								*/
#define MESSAGE_ID_SIZE		(64)			/* ����ID�̃T�C�Y(byte)							*/	
#define STORAGE_ID_01		(0)				/* ����ID 01���i�[����Ă���z��ԍ�			*/
#define STORAGE_ID_02		(1)				/* ����ID 02���i�[����Ă���z��ԍ�			*/
#define STORAGE_ID_03		(2)				/* ����ID 03���i�[����Ă���z��ԍ�			*/
#define STORAGE_ID_04		(3)				/* ����ID 04���i�[����Ă���z��ԍ�			*/

static char sPrintMessage[MESSAGE_ID_MAX][MESSAGE_ID_SIZE] = {
	{ "3���̐�������͂��ĉ�����[�I��/EXIT]:" },	/* ����ID 01	*/
	{ "[�Y���f�[�^]:" },							/* ����ID 02	*/
	{ "[��������]:�Y���f�[�^�Ȃ�\n" },				/* ����ID 03	*/
	{ "<ERROR>[�������ʒl]:" },						/* ����ID 04	*/
};

void main(void) {
	/* �ϐ��錾 */
	char sInputBuf[INPUT_BUFFER_SIZE] = { 0 };				/* ���͂����l���i�[����z��				*/
	char sFileData[DATA_ROW_MAX][DATA_COL_MAX] = { 0 };		/* �t�@�C���̃f�[�^���i�[����񎟌��z��	*/
	FILE *fp = NULL;
	char cFoundFlag = FLAG_OFF;								/* �t���O [ON:FLAG_ON/OFF:FLAG_OFF]		*/

	/* �t�@�C���I�[�v��				*/
	/* �t�@�C�����J���Ȃ������ꍇ	*/
	if ((fp = fopen(FILE_NAME, OPEN_MODE)) == NULL) {
		printf("�t�@�C�����J���܂���ł����B\n");
		return;		/* �v���O�����I�� */
	}

	/* �t�@�C���̃f�[�^��ǂݍ��� */
	for (short hCount = 0;hCount < DATA_ROW_MAX;hCount++) {	/* hCount ��DATA_ROW_MAX��菬�����ꍇ���[�v	*/
		fgets(&(sFileData[hCount][0]), DATA_COL_MAX, fp);	/* �t�@�C���f�[�^��ǂݍ���						*/
	}

	/* �t�@�C���N���[�Y	*/
	fclose(fp);

	/* �i�v���[�v */
	while (1) {
		cFoundFlag = FLAG_OFF;			/* �t���O������	*/

		printf("%s", &(sPrintMessage[STORAGE_ID_01][0]));	/* ����ID 01�̏o��	*/
		gets(&(sInputBuf[0]));					/* �����L�[�����	*/

		/* "EXIT"�Ɠ��͂���ƃ��[�v�I�� */
		if (strcmp(&(sInputBuf[0]), "EXIT") == 0) {		/* ���͂����l��"EXIT"���ׁA�������� 0 ��Ԃ��A==�Ŕ��� */
			break;
		}

		/* DATA_ROW_MAX�񃋁[�v */
		for (short hCount = 0;hCount < DATA_ROW_MAX;hCount++) {

			/* ���͂����l�ƌ����L�[���������Ƃ� */
			if (strncmp(&(sInputBuf[0]), &(sFileData[hCount][0]), SEARCH_KEY_SIZE) == 0) {
				printf("%s%s", &(sPrintMessage[STORAGE_ID_02][0]), &(sFileData[hCount][DSP_POS]));	/* ����ID 02�̏o�� */
											/* �񎟌��z��̐擪����DSP_POS�Ԗڂ̃A�h���X(�f�[�^��)��n���Ă��� */
				cFoundFlag = FLAG_ON;		/* �t���O�FON */
				break;		/* ���[�v�I�� */
			}

		}

		/* �t���O�FOFF�̏ꍇ */
		if (cFoundFlag == FLAG_OFF) {
			printf("%s", &(sPrintMessage[STORAGE_ID_03][0]));	/* ����ID 03�̏o�� */
		}
		
	}
	return;
}