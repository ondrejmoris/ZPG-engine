#pragma once
#include "CameraObserver.h"

// TODO - implementovat. Nen� t�eba to implemetnovat a� d�le a ukl�dat CameraObsercer[] zde.

class CameraObservable
{
public:
	virtual void addCameraObserver(CameraObserver* obs) = 0;
	virtual void removeCameraObserver(CameraObserver* obs) = 0;

	virtual void notifyCameraObservers() = 0;
};