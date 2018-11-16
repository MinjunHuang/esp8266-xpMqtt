#ifndef __XP_MQTT_VERSION_H__
#define __XP_MQTT_VERSION_H__

/***********************************************************************************/
//                  xp_mqtt�汾    
/***********************************************************************************/
//#define XP_MQTT_VER_STR     "xp_mqtt_v1.0.0"
/*
��������:
1��SDK�汾: ESP8266_RTOS_SDK_2.0.0_740857
2���״η�����
*/

//************************************************************************
//#define XP_MQTT_VER_STR     "xp_mqtt_v1.1.0"
/*
��������:
1���޸�xp_mqtt_err_code.hΪxp_mqtt_state_code.h����xp_mqtt_task�¼������Ƶ�xp_mqtt_state_code.h�С�
2�������ύ���ı�API(XP_MQTT_TopicTable_Submit)���Ѷ��ĺ�ȥ���������ύ���ı����ʽ��
3�����Ӷ��ı�״̬(������ʾִ��״��)
    TABLE_STATE_IDLE = 0, //���ı����״̬
    TABLE_STATE_CHANGE,   //���ı������ݱ��(���ݶ������nextState�������)
    TABLE_STATE_IMPORT,   //���ı���(�����������ӳɹ���)(���ݶ������state��������)
4������xp_mqtt_updata_topicTable�ڲ�������mqtt�����Ķ��ĺ�ȥ���Ĵ���
5���������ݽ����¼�	
    XP_MQTT_EVENT_RECEIVE_SUCC,     //���ݽ��ճɹ�
    XP_MQTT_EVENT_RECEIVE_FAIL,     //���ݽ���ʧ��
6������mqtt��Ϣ�����¼�
    XP_MQTT_EVENT_PUBLISHING,       //mqtt��Ϣ������
    XP_MQTT_EVENT_PUBLISHING_SUCC,  //�����ɹ�
    XP_MQTT_EVENT_PUBLISHING_FAIL,  //����ʧ��
7������XP_MQTT_SendMsg�ķ���ģʽ
    (1)��������(Ҫ�ȴ�xp_mqtt������)
    (2)���跢��(����ȴ��������ڻص��¼��еõ�������))
8����XP_MQTT_BROKER_HOST��XP_MQTT_BROKER_PORT��XP_MQTT_COMMAND_TIMEOUT 
�Ƴ�xp_mqtt_config.h����XP_MQTT_CONFIG����ֵ����
*/

//************************************************************************
//#define XP_MQTT_VER_STR     "xp_mqtt_v1.1.1"
/*
��������:
1���޸���������ʹ�ö��е���ʽ
*/
    
//************************************************************************
//#define XP_MQTT_VER_STR     "xp_mqtt_v1.1.2"
/*
��������:
1���Ż��������µĴ���������ղ������ᴥ���������¡�
2���Ż�xp_mqtt_updata_topicTable����(xp_mqtt�ڲ�����)
    (1)����"����"����ǰ���ж��Ƿ���������Ҫ���£�������ֱ���˳����������κ��¼���        
3���޸�xp_mqtt_task�����ջΪ640
*/

//************************************************************************
#define XP_MQTT_VER_STR     "xp_mqtt_v1.1.3"
/*
��������:
1������"topic�����״̬"
   (1)ITEM_HANDLE_ADD_UNSUB //����������Ӳ���(topic�����������������borker����)�����ڽ������onenetƽ̨���·�ָ�
2������XP_MQTT_ITEM_STATE(����ʹ��)
*/





#endif

