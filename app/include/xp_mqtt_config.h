#ifndef __XP_MQTT_CONFIG_H__
#define __XP_MQTT_CONFIG_H__

//ע:ҪԤ��10K�ڴ�����xp_mqtt(�ó��ڴ��˵~~~)

/***********************************************************************************/
//                 DEBUG
/***********************************************************************************/
#define XP_MQTT_DEBUG   1
#if XP_MQTT_DEBUG
#include "driver.h"
#define m_printf( format, ... )      printf( "D: "format"\n", ##__VA_ARGS__ )
#else
#define m_printf( format, ... ) 
#endif

/***********************************************************************************/
//                 XP_MQTT��������
/***********************************************************************************/
#define XP_MQTT_TASK_STACK_DEPTEH   640     //xp_mqtt�����ջ
#define XP_MQTT_TASK_PRIORITY       9       //xp_mqtt�������ȼ�

//�������ݰ�
//���topic����
#define XP_MQTT_MAX_TOPICLEN        70
//��������峤��
#define XP_MQTT_MAX_PAYLOADLEN      200
//���ݷ��Ͷ�������
#define XP_MQTT_SEND_MSG_QUEUE_LEN  3
//���ݽ��ն�������
#define XP_MQTT_RCV_MSG_QUEUE_LEN   5

//�ɶ����������
//(�����û������������������ʹ�õ���mqttClient��ǰ�������)
//#define XP_MQTT_SUBSCIBE_NUM    MAX_MESSAGE_HANDLERS       
//(����̶�Ϊ5)
#define XP_MQTT_SUBSCIBE_NUM        5   

#define XP_MQTT_BUF_SIZE            1024    //�����շ���������С

#define XP_MQTT_YIELD_TIME          100     //�Ự����ʱ��(Ҳ�Ƿ�����С���)
#define XP_MQTT_RECONNECT_INTERVAL  1000    //mqtt�������,��λms

#endif

