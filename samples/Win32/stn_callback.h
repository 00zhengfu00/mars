#pragma once

#include "mars/stn/stn.h"
#include "mars/stn/stn_logic.h"

namespace mars {
	namespace stn {
	
		class StnCallBack : public Callback {

		public:
			StnCallBack() {};
			~StnCallBack() {};

			virtual bool MakesureAuthed();
			//�ײ�ѯ���ϲ��host��Ӧ��ip�б�
			virtual std::vector<std::string> OnNewDns(const std::string& host);
			//������յ�push��Ϣ�ص�
			virtual void OnPush(int32_t cmdid, const AutoBuffer& msgpayload);
			//�ײ��ȡtaskҪ���͵�����
			virtual bool Req2Buf(int32_t taskid, void* const user_context, AutoBuffer& outbuffer, int& error_code, const int channel_select);
			//�ײ�ذ����ظ��ϲ����
			virtual int Buf2Resp(int32_t taskid, void* const user_context, const AutoBuffer& inbuffer, int& error_code, const int channel_select);
			//����ִ�н���
			virtual int  OnTaskEnd(int32_t taskid, void* const user_context, int error_type, int error_code);
			//�ϱ���������
			virtual void ReportFlow(int32_t wifi_recv, int32_t wifi_send, int32_t mobile_recv, int32_t mobile_send);
			//�ϱ���������״̬
			virtual void ReportConnectStatus(int status, int longlink_status);
			//��������У�� ECHECK_NOW, ECHECK_NEXT = 1, ECHECK_NEVER = 2
			virtual int  GetLonglinkIdentifyCheckBuffer(AutoBuffer& identify_buffer, AutoBuffer& buffer_hash, int32_t& cmdid);
			//��������У��ذ�
			virtual bool OnLonglinkIdentifyResponse(const AutoBuffer& response_buffer, const AutoBuffer& identify_buffer_hash);
			//
			virtual void RequestSync();
		};

	}
}

