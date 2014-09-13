/**
 ******************************************************************************
 * @file      ini.c
 * @brief     C Source file of ini.c.
 * @details   This file including all API functions's 
 *            implement of ini.c.	
 *
 * @copyright
 ******************************************************************************
 */
 
/*-----------------------------------------------------------------------------
 Section: Includes
 ----------------------------------------------------------------------------*/
#include <stdio.h>

#include "config.h"
#include "iniparser.h"

/*-----------------------------------------------------------------------------
 Section: Type Definitions
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Constant Definitions
 ----------------------------------------------------------------------------*/
/* NONE */ 

/*-----------------------------------------------------------------------------
 Section: Global Variables
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Local Variables
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Local Function Prototypes
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Global Function Prototypes
 ----------------------------------------------------------------------------*/
/* NONE */

/*-----------------------------------------------------------------------------
 Section: Function Definitions
 ----------------------------------------------------------------------------*/
/**
 ******************************************************************************
 * @brief   ����Ĭ�������ļ�
 * @param[in]  None
 * @param[out] None
 * @retval     None
 ******************************************************************************
 */
static void
create_example_ini_file(void)
{
    FILE    *   ini ;

    ini = fopen(DEFAULT_INI_FILE, "w");
    fprintf(ini,
    "#��Ѷ�ƽ�����By LiuNing\n"
    "[client]\n"
    "#·����ip(Ĭ��192.168.1.1)\n"
    "ip     = 192.168.1.1\n"
    "#�������˿ں�(Ĭ��80)\n"
    "port   = 80\n"
    "#�Ƿ��¼��־\n"
    "log    = yes\n"
    "#·��������\n"
    "#0: ˮ��\n"
    "#1: TP-link   WR710\n"
    "#2: TP-link   WR800\n"
    "#3: Tenda\n"
    "#4: 9x25(ע��˿ں����޸�Ϊ2233)\n"
    "#5: TP-link   WR842N\n"
    "type   = 1\n"
    "\n");
    fclose(ini);
}

/**
 ******************************************************************************
 * @brief   �������ļ��л�ȡ������ip�ַ���
 * @param[out] *pserverip   : ���ط�����ip�ַ���
 *
 * @retval     -1 ʧ��
 * @retval      0 �ɹ�
 ******************************************************************************
 */
int
ini_get_server_ip(char * pserverip)
{
    dictionary  *   ini ;
    char *pstr = NULL;

    ini = iniparser_load(DEFAULT_INI_FILE);
    if (NULL == ini)
    {
        create_example_ini_file();
        ini = iniparser_load(DEFAULT_INI_FILE);
        if (ini == NULL)
        {
            return -1;
        }
    }

    iniparser_dump(ini, NULL);
    pstr = iniparser_getstring(ini, "client:ip", NULL);
    if (pstr == NULL)
    {
        return -1;
    }
    strncpy(pserverip, pstr, 16);   //ip�ַ����16�ֽ�

    iniparser_freedict(ini);

    return 0;
}

/**
 ******************************************************************************
 * @brief   �������ļ��л�ȡ�������˿�
 * @param[out] *pserverip   : ���ط�����ip�ַ���
 *
 * @retval     -1 ʧ��
 * @retval      0 �ɹ�
 ******************************************************************************
 */
int
ini_get_server_port(unsigned short *pport)
{
    dictionary  *   ini ;

    ini = iniparser_load(DEFAULT_INI_FILE);
    if (NULL == ini)
    {
        create_example_ini_file();
        ini = iniparser_load(DEFAULT_INI_FILE);
        if (ini == NULL)
        {
            return -1;
        }
    }

    iniparser_dump(ini, NULL);
    *pport = (unsigned short)iniparser_getint(ini, "client:port", -1);

    iniparser_freedict(ini);

    return 0;
}

/**
 ******************************************************************************
 * @brief   �������ļ��л�ȡ�Ƿ������־��־
 * @param[out] *pserverip   : ���ط�����ip�ַ���
 *
 * @retval     -1 ʧ��
 * @retval      0 �ɹ�
 ******************************************************************************
 */
int
ini_get_log_flag(char *pflag)
{
    dictionary  *   ini ;

    ini = iniparser_load(DEFAULT_INI_FILE);
    if (NULL == ini)
    {
        create_example_ini_file();
        ini = iniparser_load(DEFAULT_INI_FILE);
        if (ini == NULL)
        {
            return -1;
        }
    }

    iniparser_dump(ini, NULL);//stderr
    *pflag = (char)iniparser_getboolean(ini, "client:log", -1);

    iniparser_freedict(ini);

    return 0;
}


/**
 ******************************************************************************
 * @brief   �������ļ��л�ȡ·��������
 * @param[out] *pserverip   : ����type
 *
 * @retval     -1 ʧ��
 * @retval      0 �ɹ�
 ******************************************************************************
 */
int
ini_get_log_type(int *ptype)
{
    dictionary  *   ini ;

    ini = iniparser_load(DEFAULT_INI_FILE);
    if (NULL == ini)
    {
        create_example_ini_file();
        ini = iniparser_load(DEFAULT_INI_FILE);
        if (ini == NULL)
        {
            return -1;
        }
    }

    iniparser_dump(ini, NULL);//stderr
    *ptype = iniparser_getint(ini, "client:type", -1);

    iniparser_freedict(ini);

    return 0;
}
/*----------------------------ini.c--------------------------------*/
