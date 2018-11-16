#ifndef __XP_MQTT_STATE_CODE_H__
#define __XP_MQTT_STATE_CODE_H__

//xp_mqtt_task�¼�
typedef enum
{
    //xp mqtt�¼���ʼID
    XP_MQTT_EVENT_START__ = 0,   
    
    XP_MQTT_EVENT_NET_CONNECTING,   //����������
    XP_MQTT_EVENT_NET_CONN_SUCC,    //�������ӳɹ�
    XP_MQTT_EVENT_NET_CONN_FAIL,    //��������ʧ��
    XP_MQTT_EVENT_NET_DISCONN,      //����Ͽ�
    XP_MQTT_EVENT_NET_RECONN,       //��������
    
    XP_MQTT_EVENT_MQTT_CONNECTING,  //��mqtt������������
    XP_MQTT_EVENT_MQTT_CONN_SUCC,   //��mqtt���������ӳɹ�
    XP_MQTT_EVENT_MQTT_CONN_FAIL,   //��mqtt����������ʧ��
        
    XP_MQTT_EVENT_FIRST_CONN,       //��һ������mqtt������

    XP_MQTT_EVENT_TOPICTABLE_UPDATING,      //����������
    XP_MQTT_EVENT_TOPICTABLE_UPDATA_SUCC,   //�������³ɹ�
    XP_MQTT_EVENT_TOPICTABLE_UPDATA_FAIL,   //��������ʧ��

    XP_MQTT_EVENT_RECEIVE_SUCC,     //���ݽ��ճɹ�
    XP_MQTT_EVENT_RECEIVE_FAIL,     //���ݽ���ʧ��

    XP_MQTT_EVENT_PUBLISHING,       //mqtt��Ϣ������
    XP_MQTT_EVENT_PUBLISH_SUCC,     //�����ɹ�
    XP_MQTT_EVENT_PUBLISH_FAIL,     //����ʧ��
        
    XP_MQTT_EVENT_TASK_CLOSE,      //ɾ��xp_mqtt����ǰ�����һ���¼�

    //xp mqtt�¼�����ID
    XP_MQTT_EVENT_END__,   
}XP_MQTT_EVENT;

//�������
typedef enum
{
    XP_MQTT_SUCCESS          =  0,   //�ɹ�    
    XP_MQTT_ERR_MALLOC_FAIL  = -1,   //�����ڴ�ʧ��	
    XP_MQTT_ERR_NO_START     = -2,   //δִ��XP_MQTT_START,
    
//xpmqtt���ô���
    XP_MQTT_ERR_CONFIG_IS_NULL              = -11,  //�������ñ�Ϊ��
    XP_MQTT_ERR_CONFIG_HAS_NULL             = -12,  //�������ñ���ڿ���
    XP_MQTT_ERR_CONFIG_CELLBACK_HAS_NULL    = -13,  //�������ñ��еĻص��������ڿ���
    XP_MQTT_ERR_CONFIG_CREATE_TASK_FAIL     = -14,  //����xp_mqtt����ʧ��

//xpmqtt�������ӻ�ɾ������
    XP_MQTT_ERR_TOPICTAB_FULL               = -30,  //���������

//xpmqtt�������
    XP_MQTT_ERR_TASK_PROC_ERR               = -50,  //״̬������
    XP_MQTT_ERR_TASK_SUBTABLE_ERR           = -51,  //���ı�ִ�г���           

//xpmqtt���ݷ�������
    XP_MQTT_ERR_SEND_DISCONNECT             = -70,  //δ����mqtt
    XP_MQTT_ERR_SEND_FULL                   = -71,  //���Ͷ�������
    XP_MQTT_ERR_SEND_FAIL                   = -72,  //����ʧ��
}XP_MQTT_ERR_CODE;


#endif

