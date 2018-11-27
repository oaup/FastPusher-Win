#pragma once

class CJwGrabDesktopDevice
{
public:
	CJwGrabDesktopDevice();
	~CJwGrabDesktopDevice();

public:
	virtual bool Open();

	virtual bool Close();

	virtual bool QueryVideoSample();
};

