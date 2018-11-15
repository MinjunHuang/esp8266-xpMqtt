#ifndef __XP_MQTT_H__
#define __XP_MQTT_H__

/***********************************************************************************/
//                 ͷ�ļ�����
/***********************************************************************************/
#include "c_types.h"
#include "mqtt/MQTTClient.h"
#include "xp_mqtt_state_code.h"
#include "xp_mqtt_config.h"


/***********************************************************************************/
//                 ��
/***********************************************************************************/
#ifndef IFA
#define IFA     ICACHE_FLASH_ATTR
#endif

/***********************************************************************************/
//                 ö��
/***********************************************************************************/
//XP_MQTT_SendMsg��Ϣ����ģʽ
typedef enum
{
    SEND_MODE_BLOCK = 0,    //����ģʽ
    SEND_MODE_UNBLOCK,      //����ģʽ
}XP_MQTT_SEND_MODE;

//topic�����״̬
typedef enum
{
    ITEM_HANDLE_IDLE = 0, //�������Ϊ��(�����в���)    
    ITEM_HANDLE_ADD,      //����������Ӳ���(����)
    ITEM_HANDLE_ADD_UNSUB,//����������Ӳ���(topic�����������������borker����)
    ITEM_HANDLE_DEL,      //�������ɾ������(ȥ����)
}XP_MQTT_ITEM_HANDLE;

/***********************************************************************************/
//                 ���ݽṹ
/***********************************************************************************/
//mqtt���ñ�
typedef struct
{
//MQTTPacket_connectData
    char* borkerHost;
    char* usermame;
    char* password;
    char* clientID;
    uint8 MQTTVersion;
    uint8 cleansession;
    uint16 borkerPort;
    uint16 keepAliveInterval;
    uint32 mqttCommandTimeout;
    
    //������Ϣ�ص�����
    void (*xp_mqtt_error_cellback)( XP_MQTT_ERR_CODE err );
    //�¼��ص�����
    void (*xp_mqtt_event_cellback)( XP_MQTT_EVENT event );
}XP_MQTT_CONFIG;

//mqtt���ݰ�(���ڶ���)
typedef struct
{
    XP_MQTT_SEND_MODE sendMode;
    uint8   qos;
    uint8   retained;
    uint8   dup; //���ʹ���
    
    uint8   topic[XP_MQTT_MAX_TOPICLEN+1];
    uint8   payload[XP_MQTT_MAX_PAYLOADLEN+1];
    uint16  payloadlen;
}MQTT_MSG;

//topic�������ӻ�ɾ��������Ϣ
typedef struct
{
    XP_MQTT_ITEM_HANDLE handle;         //Ҫ���еĲ���
    uint8 qos;
    char topic[XP_MQTT_MAX_TOPICLEN+1];
}XP_MQTT_TOPIC_ITEM;


/***********************************************************************************/
//                 ����api
/***********************************************************************************/
/*****************************************************************************
 * �� �� ��  : Get_XP_MQTT_Version
 * ��������  : ���ص�ǰ�汾��
 * �������  : ��
 * �� �� ֵ  : 
                char *
 * ��    ע  : ��
*****************************************************************************/
const char* IFA Get_XP_MQTT_Version( void );

/*****************************************************************************
 * �� �� ��  : XP_MQTT_START
 * ��������  : ���� mqtt���ñ� ����mqtt����
 * �������  : 
                config : mqtt���ñ�
 * �� �� ֵ  : 
                XP_MQTT_ERR_CODE: ������(0:�ɹ�, other:��"xp_mqtt_state_code.h")                
 * ��    ע  : 
                XP_MQTT_START �� XP_MQTT_CloseWait ��ʹ����һһ��Ӧ�ġ�
*****************************************************************************/
XP_MQTT_ERR_CODE IFA XP_MQTT_START( XP_MQTT_CONFIG *config );

/*****************************************************************************
 * �� �� ��  : XP_MATT_CloseWait
 * ��������  : 
                �ر�mqtt task
 * �������  : ��
 * �� �� ֵ  : ��
 * ��    ע  : 
                XP_MATT_CloseWait һ�������� XP_MQTT_START �ɹ�֮��
*****************************************************************************/
void IFA XP_MQTT_CloseWait( void );

/*****************************************************************************
 * �� �� ��  : Get_XP_MQTT_ReceiveMsg
 * ��������  : 
               ��ȡmqtt���յ����ݰ�
 * �������  : 
                msg     : �����Ϣ��   
                timeOut : ������ʱʱ��
 * �� �� ֵ  : 
               -1 : Ϊ����
                0 : �����ݻ�ȡ
              n>0 : Ϊ���ݰ���
 * ��    ע  : ��

*****************************************************************************/
long IFA Get_XP_MQTT_ReceiveMsg( MQTT_MSG* msg, uint32 timeOut );

/*****************************************************************************
 * �� �� ��  : XP_MQTT_SendMsg
 * ��������  : 
                ������Ϣ
 * �������  : 
                mqttMsg :   ��Ϣ��Ŀ                                
 * �� �� ֵ  : 
                XP_MQTT_ERR_CODE: ������(0:�ɹ�, other:��"xp_mqtt_state_code.h")                
 * ��    ע  : 
                mqttMsg.sendMode:       ���ݷ���ģʽ
                    SEND_MODE_BLOCK:    ����ģʽ(��Ҫ�ȴ�xp_mqtt_task���ز������)
                    SEND_MODE_UNBLOCK:  ����ģʽ(����ȴ�,�ɶ������,�����¼��ص��õ����)
*****************************************************************************/
XP_MQTT_ERR_CODE IFA XP_MQTT_SendMsg( MQTT_MSG *mqttMsg );

/*****************************************************************************
 * �� �� ��  : XP_MQTT_TopicTable_DeleteAll
 * ��������  : 
                �������������ʹ�õ���,ִ��ɾ������
 * �������  : ��                
 * �� �� ֵ  : 
                XP_MQTT_ERR_CODE: ������(0:�ɹ�, other:��"xp_mqtt_state_code.h")                
 * ��    ע  : ��
*****************************************************************************/
XP_MQTT_ERR_CODE IFA XP_MQTT_TopicTable_DeleteAll( void );

/*****************************************************************************
 * �� �� ��  : XP_MQTT_TopicTable_Submit
 * ��������  : 
                �ύ��������
 * �������  : 
                topics : ������Ŀָ��
                itemNum: ��Ŀ����
                
 * �� �� ֵ  : 
                XP_MQTT_ERR_CODE: ������(0:�ɹ�, other:��"xp_mqtt_state_code.h")                
 * ��    ע  : ��
*****************************************************************************/
XP_MQTT_ERR_CODE IFA XP_MQTT_TopicTable_Submit( XP_MQTT_TOPIC_ITEM* topics, uint8 itemNum );



#endif

