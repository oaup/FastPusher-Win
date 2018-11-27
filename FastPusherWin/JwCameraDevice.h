#pragma once
class CJwCameraDevice
{
public:
	CJwCameraDevice();
	~CJwCameraDevice();

public:
	virtual bool Open();

	virtual bool Close();

	virtual bool QueryVideoSample();
};

