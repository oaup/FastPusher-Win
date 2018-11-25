#pragma once 
extern "C" 
{ 
#include <libavcodec/avcodec.h> 
#include <libavdevice/avdevice.h> 
#include<libavfilter/avfilter.h> 
#include <libswscale/swscale.h> 
#include <libswresample/swresample.h> 
#include <libavformat/avformat.h> 
#include <libavutil/avutil.h> 
#include <libavutil/imgutils.h> 
}

class CFastEncoder
{
	public:
		CFastEncoder();
	public:
		AVFrame *m_pRGBFrame;   //֡����
		AVFrame *m_pYUVFrame;   //֡����
		AVCodec *pCodecH264;    //������
		AVCodecContext *c;      //���������ݽṹ����
		uint8_t *yuv_buff;      //yuvͼ��������
		uint8_t *rgb_buff;      //rgbͼ��������
		SwsContext *scxt;       //ͼ���ʽת������
		uint8_t *outbuf;        //���������Ƶ���ݻ���
		int outbuf_size;        //�����������ȥ��С
		int nDataLen;           //rgbͼ������������
		int width;              //�����Ƶ���
		int height;             //�����Ƶ�߶�
		AVPacket pkt;            //���ݰ��ṹ��
	public:
		//��ʼ��
		void Ffmpeg_Encoder_Init();
		// ���ò���,��һ������Ϊ������,�ڶ�������Ϊѹ����������Ƶ�Ŀ�ȣ���������Ƶ��Ϊ��߶� 
		void Ffmpeg_Encoder_Setpara(AVCodecID mycodeid, int vwidth, int vheight); 
		// ���벢д�����ݵ��ļ�
		void Ffmpeg_Encoder_Encode(FILE *file, uint8_t *inRgbData);
		// �������H264����
		int Ffmepg_Encoder_Encode(uint8_t *inYuvData,uint8_t *outData, int length);
		//�ر�
		void Ffmpeg_Encoder_Close(); 
}


